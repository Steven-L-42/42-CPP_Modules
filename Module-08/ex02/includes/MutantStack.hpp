/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slippert <slippert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 21:02:05 by slippert          #+#    #+#             */
/*   Updated: 2024/01/22 11:49:55 by slippert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <algorithm>
#include <iostream>
#include <stack>
#include <list>

#define blue "\033[1;34m"
#define red "\033[1;31m"
#define green "\033[1;32m"
#define reset "\033[0m"

template <class T>
class MutantStack : public std::stack<T>
{
	public:
	typedef typename std::stack<T>::container_type::iterator iterator;
		MutantStack();
		MutantStack(const MutantStack &ref);
		MutantStack &operator=(const MutantStack &ref);
		~MutantStack();
		iterator begin();
		iterator end();
};


template <class T>
inline MutantStack<T>::MutantStack() : std::stack<T>() {}

template<class T>
inline MutantStack<T>::MutantStack(const MutantStack & ref) : std::stack<T>(ref) {}

template <class T>
inline MutantStack<T>::~MutantStack() {}

template <class T>
inline MutantStack<T> &MutantStack<T>::operator=(const MutantStack<T> &ref)
{
	if (this != &ref)
	{
		std::stack<T>::operator=(ref);
	}
	return (*this);
}

template <class T>
inline typename MutantStack<T>::iterator MutantStack<T>::begin()
{
	return (this->c.begin());
}

template <class T>
inline typename MutantStack<T>::iterator MutantStack<T>::end()
{
	return (this->c.end());
}
