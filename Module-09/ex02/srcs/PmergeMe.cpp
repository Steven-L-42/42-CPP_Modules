/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slippert <slippert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 15:23:57 by slippert          #+#    #+#             */
/*   Updated: 2024/02/04 18:33:23 by slippert         ###   ########.fr       */
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

void PmergeMe::FordJohnson(int _size, char **_argv)
{
	std::vector<int> conBefore;
	for (int i = 1; i < _size; i++)
	{
		int nbr = static_cast<int>(std::atoi(_argv[i]));
		if (nbr <= 0)
			throw(InvalidInputException());
		conBefore.push_back(nbr);
	}

	if (std::is_sorted(conBefore.begin(), conBefore.end()))
		throw(SortedNumbersException());

	std::cout << blue << "Before:\t" << green;
	display(conBefore);

	double durationVector;
	double durationDeque;
	templateSort(conVector, durationVector, _size, _argv);
	templateSort(conDeque, durationDeque, _size, _argv);

	std::cout << blue << "After:\t" << green;
	display(conVector);

	displayTime(conVector, "std::vector<int>", durationVector);
	displayTime(conDeque, "std::deque<int>", durationDeque);
}
