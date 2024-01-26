/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slippert <slippert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 15:23:57 by slippert          #+#    #+#             */
/*   Updated: 2024/01/26 11:07:06 by slippert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

const char *PmergeMe::ExpressionException::what() const throw()
{
	return ("Error: your input contains not allowed characters!\nAllowed characters \"0123456789\".\n");
}

bool PmergeMe::CheckForValidInput(std::string &input)
{
	std::string allowedChars = "0123456789";
	for (std::string::iterator it = input.begin(); it != input.end(); it++)
		if (allowedChars.find(*it) == std::string::npos)
			return (false);
	return (true);
}

std::string PmergeMe::RemoveWhitespaces(std::string &input)
{
	size_t start = input.find_first_not_of(" \t\n\r");
	size_t end = input.find_last_not_of(" \t\n\r");

	if (start == std::string::npos || end == std::string::npos)
		return ("");
	return (input.substr(start, end - start + 1));
}
