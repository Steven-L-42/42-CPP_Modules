/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slippert <slippert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 21:02:05 by slippert          #+#    #+#             */
/*   Updated: 2024/01/24 18:02:09 by slippert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
#include <exception>

#define blue "\033[1;34m"
#define red "\033[1;31m"
#define green "\033[1;32m"
#define reset "\033[0m"

class Span
{
private:
	std::vector<int> arr;
	int maxNumbers;

public:
	Span();
	Span(unsigned int N);
	Span(const Span &ref);
	Span &operator=(const Span &ref);
	~Span();
	void addNumber(int number);
	void addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end);
	int shortestSpan();
	int longestSpan();
	class NotEnoughItemsException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
};
