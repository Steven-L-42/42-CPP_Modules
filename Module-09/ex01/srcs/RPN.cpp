/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slippert <slippert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 15:23:57 by slippert          #+#    #+#             */
/*   Updated: 2024/02/14 14:17:57 by slippert         ###   ########.fr       */
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
	for (std::string::iterator it = input.begin(); it != input.end(); it++)
		math.push(std::string(1, *it));
	if (math.size() < 3)
		throw(std::logic_error("Error: input requires at least 3 characters!\nExample: ./RPN \"1 2 +\"\n"));
}

bool RPN::isNumber(std::string &item, float &nbr)
{
	std::istringstream in(item);
	in >> nbr;
	if (in.fail())
		return (false);
	return (true);
}

void RPN::Calculate(std::string &input, bool _activeDebug)
{
	CheckForValidInput(input);
	CreateCalcStack(input);
	std::stringstream streamInput(input);
	std::string item;
	float nbr;
	std::stack<float> stackFloat;
	std::string ops = "+-*/";
	while (std::getline(streamInput, item, ' '))
	{
		if (isNumber(item, nbr))
			stackFloat.push(nbr);
		else if (std::find(ops.begin(), ops.end(), item[0]) != ops.end())
		{
			if (stackFloat.size() < 2)
				throw std::invalid_argument("Not valid polish notation!\n");
			float first = stackFloat.top();
			stackFloat.pop();
			float last = stackFloat.top();
			stackFloat.pop();
			switch (item[0])
			{
			case '+':
				stackFloat.push(last + first);
				break;
			case '-':
				stackFloat.push(last - first);
				break;
			case '*':
				stackFloat.push(last * first);
				break;
			case '/':
				if (last == 0)
					throw std::invalid_argument("Division by 0 not possible!\n");
				stackFloat.push(last / first);
				break;
			}
			if (_activeDebug)
				std::cout << last << " " << item << " " << first << " = " << stackFloat.top() << std::endl;
		}
	}
	if (stackFloat.size() != 1)
		throw std::invalid_argument("Not enough mathematical operators!\n");
	std::cout << stackFloat.top() << std::endl;
}
