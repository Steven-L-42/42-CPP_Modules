/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slippert <slippert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 16:26:17 by slippert          #+#    #+#             */
/*   Updated: 2024/01/20 17:54:54 by slippert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

template <class T>
class Array
{
	private:
		T *arr;
		size_t _size;
	public:
		Array();
		Array(unsigned int n);
		Array(const Array &ref);
		Array &operator=(const Array &ref);
		T &operator[](size_t index);
		T &operator[](size_t index) const;
		~Array();
		size_t size();
};

template <class T>
Array<T>::Array() : arr(new T()), _size(0)
{}

template <class T>
Array<T>::Array(unsigned int n) : arr(new T[n]()), _size(n)
{}

template <class T>
Array<T>::Array(const Array &ref): arr(new T[ref._size]()), _size(ref._size)
{
	for (size_t i = 0; i < ref._size; ++i)
		arr[i] = ref.arr[i];
}

template <class T>
Array<T>::~Array()
{
	delete [] arr;
}

template <class T>
size_t Array<T>::size()
{
	return (_size);
}

template <class T>
Array<T> &Array<T>::operator=(const Array &ref)
{
	if (this != &ref)
	{
		delete [] arr;
		for (size_t i = 0; i < ref._size; i++)
		{
			arr[i] = ref[i];
		}
	}
	return (*this);
}

template <class T>
T &Array<T>::operator[](std::size_t index)
{
	if (index >= _size) {
		throw std::out_of_range("Index out of bounds");
	}
	return (arr[index]);
}

template <class T>
T &Array<T>::operator[](std::size_t index) const
{
	if (index >= _size) {
		throw std::out_of_range("Index out of bounds");
	}
	return (arr[index]);
}
