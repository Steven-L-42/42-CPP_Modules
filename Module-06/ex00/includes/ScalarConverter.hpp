/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slippert <slippert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 21:02:05 by slippert          #+#    #+#             */
/*   Updated: 2024/01/16 15:48:56 by slippert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cmath>
#include <cstdlib>
#include <iostream>

class ScalarConverter
{
  private:
	const std::string input;

  public:
	ScalarConverter();
	ScalarConverter(const std::string _input);
	ScalarConverter(const ScalarConverter &ref);
	ScalarConverter &operator=(const ScalarConverter &ref);
	~ScalarConverter();
	static void convert(const std::string &literal);
	void CheckLiteral(const std::string &literal);
};

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const std::string _input) : input(_input)
{
	CheckLiteral(input);
	convert(input);
}

ScalarConverter::ScalarConverter(const ScalarConverter &ref)
{
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &ref)
{
	*this = ref;
	return (*this);
}

ScalarConverter::~ScalarConverter()
{
}

void ScalarConverter::CheckLiteral(const std::string &literal)
{
}

void ScalarConverter::convert(const std::string &literal)
{
	int		size;
	char	*str;
	char	c;
	int		i;
	float	f;
	double	d;
	char	newChar;
	double	numDouble;
	double	charToInt;
	bool	isNaN;
	bool	isChar;

	size = literal.size() + 1;
	str = new char[size];
	std::strcpy(str, literal.c_str());
	numDouble = strtod(str, NULL);
	isNaN = false;
	isChar = false;
	isNaN = std::isnan(numDouble);
	// Convert to Char
	if (isNaN)
		std::cout << "Char: impossible" << std::endl;
	else if (literal.size() == 1)
	{
		newChar = literal[0];
		charToInt = newChar + 0;
		c = charToInt;
		if (charToInt < 0 || charToInt > 127)
			std::cout << "Char: impossible" << std::endl;
		else if ((charToInt >= 0 && charToInt <= 32) || charToInt == 127)
			std::cout << "Char: Non displayable" << std::endl;
		else
		{
			std::cout << "Char: " << newChar << std::endl;
			if (newChar < 48 || newChar > 57)
				isChar = true;
		}
	}
	else
	{
		if (numDouble < 0 || numDouble > 127)
			std::cout << "Char: impossible" << std::endl;
		else if ((numDouble >= 0 && numDouble <= 32) || numDouble == 127)
			std::cout << "Char: Non displayable" << std::endl;
		else
			std::cout << "Char: " << numDouble << std::endl;
	}
	// Convert to Int
	if (isNaN || numDouble > INT_MAX || numDouble < INT_MIN)
		std::cout << "Int: impossible" << std::endl;
	else
	{
		if (isChar)
			std::cout << "Int: " << charToInt << std::endl;
		else
			std::cout << "Int: " << numDouble << std::endl;
	}
	// Convert to Float
	f = std::atof(str);
	if (!std::isinf(f))
	{
		if (isChar)
			std::cout << "Float: " << charToInt << ".0f" << std::endl;
		else if (std::floor(f) == f)
			std::cout << "Float: " << f << ".0f" << std::endl;
		else
			std::cout << "Float: " << f << "f" << std::endl;
	}
	else
		std::cout << "Float: " << f << std::endl;
	// Convert to Double
	d = strtod(str, NULL);
	if (!std::isinf(d))
	{
		if (isChar)
			std::cout << "Double: " << charToInt << ".0" << std::endl;
		else if (std::floor(d) == d)
			std::cout << "Double: " << d << ".0" << std::endl;
		else
			std::cout << "Double: " << d << std::endl;
	}
	else
		std::cout << "Double: " << d << std::endl;
}
