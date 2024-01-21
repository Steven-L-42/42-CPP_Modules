/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slippert <slippert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 18:46:12 by slippert          #+#    #+#             */
/*   Updated: 2024/01/21 14:24:52 by slippert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Span.hpp"

Span::Span() : maxNumbers(0)
{
}

Span::Span(unsigned int N) : maxNumbers(N) {}

Span::Span(const Span &ref) : arr(ref.arr), maxNumbers(ref.maxNumbers)
{
	*this = ref;
}

Span &Span::operator=(const Span &ref)
{
	if (this != &ref)
	{
		arr.clear();
		arr = std::vector<int>(ref.maxNumbers);
		for (size_t i = 0; i < ref.maxNumbers; i++)
		{
			arr[i] = ref.arr[i];
		}
		maxNumbers = ref.maxNumbers;
	}
	return (*this);
}

Span::~Span()
{
}

void Span::addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	size_t dst = std::distance(begin, end);

	if (arr.size() + dst > maxNumbers)
		throw std::runtime_error("Exceeded maximum capacity");

	arr.insert(arr.end(), begin, end);
}

void Span::addNumber(int number)
{
	if (arr.size() >= maxNumbers)
		throw std::runtime_error("Exceeded maximum capacity");
	arr.push_back(number);
}

int Span::shortestSpan()
{
	int shortest = INT_MAX;
	for (size_t i = 0; i < arr.size() - 1; i++)
	{
		for (size_t j = i + 1; j < arr.size(); j++)
		{
			int span = std::abs(arr[j] - arr[i]);
			shortest = std::min(shortest, span);
		}
	}
	return (shortest);
}

int Span::longestSpan()
{
	int longest = -INT_MAX;
	for (size_t i = 0; i < arr.size() - 1; i++)
	{
		for (size_t j = i + 1; j < arr.size(); j++)
		{
			int span = std::abs(arr[j] - arr[i]);
			longest = std::max(longest, span);
		}
	}
	return (longest);
}
