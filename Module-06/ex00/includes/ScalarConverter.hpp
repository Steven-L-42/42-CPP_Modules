/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slippert <slippert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 21:02:05 by slippert          #+#    #+#             */
/*   Updated: 2024/01/16 18:41:16 by slippert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cmath>
#include <iostream>
#include <sstream>

class ScalarConverter
{
  private:
	const std::string input;
	char c;
	int i;
	float f;
	double d;

  public:
	ScalarConverter();
	ScalarConverter(const std::string _input);
	ScalarConverter(const ScalarConverter &ref);
	ScalarConverter &operator=(const ScalarConverter &ref);
	~ScalarConverter();
	template <typename T>
	static T convert(const std::string &literal);
};
