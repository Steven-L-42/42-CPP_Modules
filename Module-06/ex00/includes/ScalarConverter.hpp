/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slippert <slippert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 21:02:05 by slippert          #+#    #+#             */
/*   Updated: 2024/01/15 21:50:11 by slippert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cmath>
#include <iostream>

class ScalarConverter
{
  private:
  public:
	ScalarConverter();
	ScalarConverter(const ScalarConverter &ref);
	ScalarConverter &operator=(const ScalarConverter &ref);
	~ScalarConverter();
	static void convert(const std::string &literal);
};

ScalarConverter::ScalarConverter()
{
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

void ScalarConverter::convert(const std::string &literal)
{
	char	c;
	int		i;
	float	f;
	double	d;

	try
	{
		c = static_cast<char>(std::stoi(literal));
		if ((c >= 0 && c <= 32) || c == 127)
			std::cout << "Char:  Non displayable" << std::endl;
		else if (c < 0 || c > 127)
			std::cout << "Char:  impossible" << std::endl;
		else
			std::cout << "Char: " << c << std::endl;
	}
	catch (std::out_of_range)
	{
		std::cout << "impossible" << std::endl;
	}
	catch (std::invalid_argument)
	{
		std::cout << "impossible" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		i = std::stoi(literal);
		std::cout << "Int: " << i << std::endl;
	}
	catch (std::out_of_range)
	{
		std::cout << "impossible" << std::endl;
	}
	catch (std::invalid_argument)
	{
		std::cout << "impossible" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		f = std::stof(literal);
		if (std::isnan(f))
			std::cout << "Float: nanf" << std::endl;
		else if (std::floor(f) != f)
			std::cout << "Float: " << f << "f" << std::endl;
		else
			std::cout << "Float: " << f << ".0f" << std::endl;
	}
	catch (std::out_of_range)
	{
		std::cout << "impossible" << std::endl;
	}
	catch (std::invalid_argument)
	{
		std::cout << "impossible" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		d = std::stod(literal);
		if (std::isnan(d))
			std::cout << "Double: " << d << std::endl;
		else if (std::floor(d) != d)
			std::cout << "Double: " << d << "" << std::endl;
		else
			std::cout << "Double: " << d << ".0" << std::endl;
	}
	catch (std::out_of_range)
	{
		std::cout << "impossible" << std::endl;
	}
	catch (std::invalid_argument)
	{
		std::cout << "impossible" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}
