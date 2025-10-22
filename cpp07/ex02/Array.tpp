/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gorg <gorg@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 09:32:42 by gorg              #+#    #+#             */
/*   Updated: 2025/10/07 09:32:42 by gorg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T>
Array<T>::Array() : _size(0), _arr(nullptr) {}

template <typename T>
Array<T>::~Array()
{
	delete[] _arr;
}

template <typename T>
Array<T>::Array(unsigned int n) : _size(n), _arr(nullptr)
{
	if (_size == 0)
		return ;
	_arr = new T[_size];
}

template <typename T>
Array<T>::Array(Array const &other) : _size(other._size), _arr(nullptr)
{
	if (_size == 0)
		return ;
	_arr = new T[_size];
	for (unsigned int i = 0; i < _size; i++)
	{
		_arr[i] = other._arr[i];
	}
}

template <typename T>
Array<T> &Array<T>::operator=(Array const &rhs)
{
	if (this != &rhs)
	{
		T *temp_arr;
		if (rhs._size)
			temp_arr = new T[rhs._size];
		else
			temp_arr = nullptr;
		for (unsigned int i = 0; i < rhs._size; i++)
			temp_arr[i] = rhs._arr[i];
		delete[] _arr;
		_arr = temp_arr;
		_size = rhs._size;
	}
	return *this;
}

template <typename T>
T &Array<T>::operator[](unsigned int n)
{
	if (_size <= n)
		throw std::out_of_range("Cash Me Outside");
	return _arr[n];
}

template <typename T>
T const &Array<T>::operator[](unsigned int n) const
{
	if (_size <= n)
		throw std::out_of_range("Cash Me Outside");
	return _arr[n];
}

template <typename T>
unsigned int Array<T>::size() const
{
	return _size;
}