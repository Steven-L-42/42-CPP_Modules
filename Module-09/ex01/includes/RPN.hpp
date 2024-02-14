/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slippert <slippert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 21:02:05 by slippert          #+#    #+#             */
/*   Updated: 2024/02/07 13:17:54 by slippert         ###   ########.fr       */
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

class RPN
{
private:
	std::stack<std::string> math;
	RPN(const RPN &ref);
	RPN &operator=(const RPN &ref);

public:
	RPN();
	~RPN();
	void CheckForValidInput(std::string &input);
	void Calculate(std::string &input, bool _activeDebug);
	void CreateCalcStack(std::string &input);
	bool isNumber(std::string &item, float &nbr);
	std::string RemoveWhitespaces(std::string &input);
	class ExpressionException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
};
