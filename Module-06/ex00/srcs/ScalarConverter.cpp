/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slippert <slippert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 18:02:26 by slippert          #+#    #+#             */
/*   Updated: 2024/01/16 18:42:34 by slippert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const std::string _input) : input(_input)
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

template <typename T>
T ScalarConverter::convert(const std::string &literal)
{
	T res;

	// if (isChar)

	return (res);
}

