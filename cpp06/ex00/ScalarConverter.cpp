/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gorg <gorg@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 12:31:17 by gorg              #+#    #+#             */
/*   Updated: 2025/09/27 12:31:17 by gorg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

enum class datatype
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	PSEUDO,
	INVALID
};

struct Values
{

	std::string ch;
	std::string in;
	std::string fl;
	std::string db;
};

struct FillStruct
{
	std::string _raw;
	double _val;
	datatype _type;
	bool overflow;
};

void print(const Values &v)
{
	std::cout << "char : " << v.ch << std::endl
			<< "int : " << v.in << std::endl
			<< "float : " << v.fl << std::endl
			<< "double : " << v.db << std::endl;
}

bool isChar(std::string const &s)
{
	if (s.size() == 1 && !std::isdigit(static_cast<unsigned char>(s[0])))
		return true;
	return false;
}

//N FOR passed number should have dot or not
bool numCheck(const std::string &s, bool n)
{
	if (s.empty())
		return false;

	int i = 0;
	bool dot = false;

	if (s[i] == '+' || s[i] == '-')
	{
		if (s.size() == 1)
			return false;
		i++;
	}
	for (; i < (int)s.size(); i++)
	{
		if (std::isdigit(static_cast<unsigned char>(s[i])))
			continue ;
		else if (s[i] == '.')
		{
			if (!n || dot)
				return false;
			dot = true;
		}
		else
			return false;
	}
	if (n && !dot)
		return false;
	return true;
}

bool isInt(std::string const &s)
{
	return numCheck(s, false);
}

bool isDouble(const std::string &s)
{
	return numCheck(s, true);
}

bool isFloat(std::string const &s)
{
	if (s.size() < 2 || s.back() != 'f')
		return false;
	return numCheck(s.substr(0, s.size() - 1), true);
}


bool isPseudo(std::string const &s)
{
	return s == "-inff" || s == "+inff" || s == "nanf" || s == "-inf" || s == "+inf" || s == "nan";
}

static FillStruct filler(std::string const &s)
{
	FillStruct f;
	f._raw = s;
//	f._val = 0;
	f.overflow = false;
	f._type = datatype::INVALID;

	if (isChar(s))
	{
		f._type = datatype::CHAR;
		f._val  = static_cast<unsigned char>(s[0]);
		return f;
	}
	if (isPseudo(s))
	{
		f._type = datatype::PSEUDO;
		return f;
	}
	if (isInt(s))
	{
		f._type = datatype::INT;
		try {
			f._val  = std::stoi(s);
		}
		catch(...) {
			f.overflow = true;
		}
		return f;
	}
	if (isFloat(s))
	{
		f._type = datatype::FLOAT;
		try {
			f._val  = std::stof(s);
		}
		catch(...) {
			f.overflow = true;
		}

		return f;
	}
	if (isDouble(s))
	{
		f._type = datatype::DOUBLE;
		try {
			f._val  = std::stod(s);
		}
		catch(std::exception &e) {
			f.overflow = true;
		}
		return f;
	}
	return f;
}

static std::string formatFloat(double d)
{

	float f = static_cast<float>(d);
	if (std::isnan(f) || std::isinf(f))
		return "impossible";
	std::ostringstream oss;
	oss << std::fixed << std::setprecision(1) << f << 'f';
	return oss.str();
}

static std::string formatDouble(double d)
{
	if (std::isnan(d) || std::isinf(d))
		return "impossible";
	std::ostringstream oss;
	oss << std::fixed << std::setprecision(1)<< d;
	return oss.str();
}

static std::string formatCharFromDouble(double d)
{
	if (std::isnan(d) || std::isinf(d) || d < 0.0 || d > 255.0)
		return "impossible";
	unsigned char c = static_cast<unsigned char>(static_cast<int>(d));
	if (std::isprint(c))
	{
		std::string out = "'";
		out += static_cast<char>(c);
		out += "'";
		return out;
	}
	return "Non displayable";
}

static std::string formatIntFromDouble(double d)
{
	if (std::isnan(d) || std::isinf(d)
		|| d < static_cast<double>(std::numeric_limits<int>::min())
		|| d > static_cast<double>(std::numeric_limits<int>::max()))
		return "impossible";
	return std::to_string(static_cast<int>(d));
}





static Values converter(const FillStruct &f)
{
	Values v;
	v.ch = "impossible";
	v.in = "impossible";
	v.fl = "impossible";
	v.db = "impossible";

	if (f.overflow == true)
		return v;
	if (f._type == datatype::PSEUDO)
	{
	//	std::cout << "PSEUDO" << std::endl;
		if (!f._raw.empty() && f._raw.back() == 'f' && (f._raw.size() == 5 || f._raw == "nanf"))
		{
			v.fl = f._raw;
			v.db = f._raw.substr(0, f._raw.size() - 1);
		}
		else
		{
			v.fl = f._raw + 'f';
			v.db = f._raw;
		}
		return v;
	}

	if (f._type == datatype::CHAR)
	{
	//	std::cout << "CHAR" << std::endl;
		unsigned char c = static_cast<unsigned char>(f._val);
		if (std::isprint(c))
		{
			v.ch = "'";
			v.ch += static_cast<char>(c);
			v.ch += "'";
		}
		else v.ch = "Non displayable";
		v.in = std::to_string(static_cast<int>(c));
		v.fl = std::to_string(static_cast<int>(c)) + ".0f";
		v.db = std::to_string(static_cast<int>(c)) + ".0";
		return v;
	}

	if (f._type == datatype::INT)
	{
	//	std::cout << "INT" << f._val << std::endl;
		int i = static_cast<int>(f._val);

		if (i >= 0 && i <= 255)
		{
			unsigned char c = static_cast<unsigned char>(i);
			if (std::isprint(c))
			{
				v.ch = "'";
				v.ch += static_cast<char>(c);
				v.ch += "'";
			}
			else v.ch = "Non displayable";
		}
		else v.ch = "impossible";
		v.in = std::to_string(i);
		v.fl = formatFloat(static_cast<double>(i));
		v.db = formatDouble(static_cast<double>(i));
		return v;
	}

	if (f._type == datatype::FLOAT || f._type == datatype::DOUBLE)
	{
	//	std::cout << "F&D" << f._val << std::endl;
		double d = f._val;
		v.ch = formatCharFromDouble(d);
		v.in = formatIntFromDouble(d);
	//	if (f._raw.compare(0, 5, std::to_string(d), 0, 5) == 0)
		v.fl = formatFloat(d);
	//	if (f._raw.compare(0, f._raw.size() - 1, std::to_string(d), 0, 5) == 0)
		v.db = formatDouble(f._val);
		return v;
	}

	return v;
}




void ScalarConverter::convert(std::string const &s)
{
	FillStruct f = filler(s);
	if (f._type == datatype::INVALID)
	{
		std::cout << "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible\n";
		return ;
	}
	Values v = converter(f);
	print(v);
}