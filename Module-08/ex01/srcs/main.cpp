/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slippert <slippert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 21:01:17 by slippert          #+#    #+#             */
/*   Updated: 2024/01/24 18:10:59 by slippert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Span.hpp"

int main(void)
{
	try
	{
		std::cout << blue << "\nTest Subject" << reset << std::endl;
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << "Shortest: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest: " << sp.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		std::cout << blue << "\n10.000 Random with addNumber" << reset << std::endl;
		Span sp = Span(10000);
		std::vector<int> numbers;
		std::srand(std::time(0));
		for (size_t i = 0; i < 10000; i++)
			numbers.push_back(rand());
		sp.addNumbers(numbers.begin(), numbers.end());
		std::cout << "Shortest: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest: " << sp.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		std::cout << blue << "\n3 with addNumbers" << reset << std::endl;
		Span sp = Span(3);
		std::vector<int> numbers;
		numbers.push_back(256);
		numbers.push_back(1024);
		numbers.push_back(512);
		sp.addNumbers(numbers.begin(), numbers.end());
		std::cout << "Shortest: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest: " << sp.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		std::cout << blue << "\nCheck maxNumbers exception" << reset << std::endl;
		Span sp = Span(2);
		std::vector<int> numbers;
		numbers.push_back(256);
		numbers.push_back(1024);
		numbers.push_back(512);
		sp.addNumbers(numbers.begin(), numbers.end());
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		std::cout << blue << "\nCheck NotEnoughException" << reset << std::endl;
		Span sp = Span(2);
		std::vector<int> numbers;
		numbers.push_back(256);

		sp.addNumbers(numbers.begin(), numbers.end());
		std::cout << "Shortest: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest: " << sp.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
