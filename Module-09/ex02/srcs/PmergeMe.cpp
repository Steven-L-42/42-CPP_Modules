/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slippert <slippert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 15:23:57 by slippert          #+#    #+#             */
/*   Updated: 2024/02/14 14:14:29 by slippert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

const char *PmergeMe::InvalidInputException::what() const throw()
{
	static std::string msg = red + std::string("Error: your input contains invalid characters!\n") + blue + std::string("(Allowed: only positive Numbers)") + reset;
	return (msg.c_str());
}

const char *PmergeMe::SortedNumbersException::what() const throw()
{
	static std::string msg = red + std::string("Error: your input is already sorted!") + reset;
	return (msg.c_str());
}

void PmergeMe::FordJohnson(int _size, char **_argv, bool _display)
{
	std::vector<int> conBefore;
	for (int i = 1; i < _size; i++)
	{
		std::string tmp = std::string(_argv[i]);
		bool allDigit = std::all_of(tmp.begin(), tmp.end(), ::isdigit);
		int nbr = static_cast<int>(std::atoi(_argv[i]));
		if (!allDigit || nbr < 0)
			throw(InvalidInputException());
		conBefore.push_back(nbr);
	}

	if (std::is_sorted(conBefore.begin(), conBefore.end()))
		throw(SortedNumbersException());

	if (_display)
	{
		std::cout << blue << "Before:\t" << green;
		display(conBefore);
	}

	double durationVector;
	double durationDeque;
	templateSort(conVector, durationVector, _size, _argv);
	templateSort(conDeque, durationDeque, _size, _argv);

	if (_display)
	{
		std::cout << blue << "After:\t" << green;
		display(conVector);
	}

	displayTime(conVector, "std::vector<int>", durationVector);
	displayTime(conDeque, "std::deque<int> ", durationDeque);
}
