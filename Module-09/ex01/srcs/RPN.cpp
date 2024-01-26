/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slippert <slippert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 15:23:57 by slippert          #+#    #+#             */
/*   Updated: 2024/01/26 12:14:36 by slippert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RPN.hpp"

RPN::RPN() {}

RPN::~RPN() {}

const char *RPN::ExpressionException::what() const throw()
{
	return ("Error: your input contains not allowed characters!\nAllowed characters \"0123456789 +-/*\".\n");
}

void RPN::CheckForValidInput(std::string &input)
{
	std::string allowedChars = "0123456789 +-/*";
	for (std::string::iterator it = input.begin(); it != input.end(); it++)
		if (allowedChars.find(*it) == std::string::npos)
			throw(ExpressionException());
}

std::string RPN::RemoveWhitespaces(std::string &input)
{
	size_t start = input.find_first_not_of(" \t\n\r");
	size_t end = input.find_last_not_of(" \t\n\r");

	if (start == std::string::npos || end == std::string::npos)
		return ("");
	return (input.substr(start, end - start + 1));
}

void RPN::CreateCalcStack(std::string &input)
{
	std::reverse(input.begin(), input.end());
	input.erase(std::remove_if(input.begin(), input.end(), ::isspace), input.end());

	for (std::string::iterator it = input.begin(); it != input.end(); it++)
		math.push(std::string(1, *it));
	if (math.size() < 3)
		throw(std::logic_error("Error: input requires at least 3 characters!\nExample: ./RPN \"1 2 +\"\n"));
}

void RPN::Calculate(std::string &input, bool _activeDebug)
{
	CheckForValidInput(input);
	CreateCalcStack(input);
	while (math.size() > 0)
	{
		std::istringstream iss1(math.top());
		math.pop();
		int calced = 0;
		int last = 0;
		int first = 0;
		char op = '\0';
		if (iss1 >> last)
		{
			std::istringstream iss2(math.top());
			math.pop();
			if (iss2 >> first)
			{
				if (math.size() == 0)
					throw(std::runtime_error("Error: there is missing number or operator for calculation.\n"));
				std::istringstream iss3(math.top());
				math.pop();
				iss3 >> op;
			}
		}
		std::string tmp = "";
		if (math.size() > 0)
		{
			tmp = math.top();
			math.pop();
		}
		switch (op)
		{
		case '+':
			calced = first + last;
			break;
		case '-':
			calced = first - last;
			break;
		case '*':
			calced = first * last;
			break;
		case '/':
			calced = first / last;
			break;
		default:
			break;
		}
		if (_activeDebug)
			std::cout << first << " " << op << " " << last << " = " << calced << std::endl;
		if (tmp == "")
		{
			std::cout << calced << std::endl;
			break;
		}
		std::ostringstream oss;
		oss << calced;
		std::string strValue = oss.str();
		math.push(strValue);
		math.push(tmp);
	}
}
