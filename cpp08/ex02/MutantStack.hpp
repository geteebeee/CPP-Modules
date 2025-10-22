/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gorg <gorg@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 10:41:22 by gorg              #+#    #+#             */
/*   Updated: 2025/10/09 10:41:22 by gorg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stack>
// <stack> -->
// template<
//     class T,
//     class Container = std::deque<T>
// > class stack;

// Member	Description
// Container c
 

template <typename T, typename Container = std::deque<T>>
class MutantStack : public std::stack<T, Container>
{
	public:
		typedef typename Container::iterator iterator;
		typedef typename Container::const_iterator const_iterator;
		typedef typename Container::reverse_iterator reverse_iterator;
		typedef typename Container::const_reverse_iterator const_reverse_iterator;

		iterator begin() { return this->c.begin(); }
		iterator end() {return this->c.end();}
		reverse_iterator rbegin() { return this->c.rbegin();}
		reverse_iterator rend() { return this->c.rend();}
		const_iterator begin() const { return this->c.begin(); }
		const_iterator end() const {return this->c.end();}
		const_reverse_iterator rbegin() const { return this->c.rbegin();}
		const_reverse_iterator rend() const { return this->c.rend();}
};
