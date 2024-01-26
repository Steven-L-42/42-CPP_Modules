/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slippert <slippert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 21:02:05 by slippert          #+#    #+#             */
/*   Updated: 2024/01/26 11:07:13 by slippert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cctype>

#define blue "\033[1;34m"
#define red "\033[1;31m"
#define green "\033[1;32m"
#define reset "\033[0m"

class PmergeMe
{
private:
	std::stack<std::string> math;
	PmergeMe(const PmergeMe &ref);
	PmergeMe &operator=(const PmergeMe &ref);

public:
	PmergeMe();
	~PmergeMe();
	bool CheckForValidInput(std::string &input);
	std::string RemoveWhitespaces(std::string &input);
	class ExpressionException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
};