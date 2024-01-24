/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slippert <slippert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 18:46:12 by slippert          #+#    #+#             */
/*   Updated: 2024/01/24 18:12:52 by slippert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Span.hpp"

Span::Span() : maxNumbers(0) {}

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
		for (size_t i = 0; i < static_cast<size_t>(ref.maxNumbers); i++)
		{
			arr[i] = ref.arr[i];
		}
		maxNumbers = ref.maxNumbers;
	}
	return (*this);
}

Span::~Span() {}

const char *Span::NotEnoughItemsException::what() const throw()
{
	return ("You need at least 2 Items to calculate a Span");
}

void Span::addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	size_t dst = std::distance(begin, end);

	if (arr.size() + dst > static_cast<size_t>(maxNumbers))
		throw std::runtime_error("Exceeded maximum capacity");

	arr.insert(arr.end(), begin, end);
}

void Span::addNumber(int number)
{
	if (arr.size() >= static_cast<size_t>(maxNumbers))
		throw std::runtime_error("Exceeded maximum capacity");

	arr.push_back(number);
}

int Span::shortestSpan()
{
	if (arr.size() <= 1)
		throw(NotEnoughItemsException());
	int shortest = std::numeric_limits<int>::max();
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
	if (arr.size() <= 1)
		throw(NotEnoughItemsException());
	std::vector<int>::iterator it_min = std::min_element(arr.begin(), arr.end());
	std::vector<int>::iterator it_max = std::max_element(arr.begin(), arr.end());
	return ((*it_max - *it_min));
}
