/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slippert <slippert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 21:02:05 by slippert          #+#    #+#             */
/*   Updated: 2024/01/23 14:45:23 by slippert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ConvertHelper.hpp"
#include <iostream>

class ConvertHelper;

class ScalarConverter
{
  private:
	const std::string input;
	ScalarConverter(const std::string _input);
	ScalarConverter(const ScalarConverter &ref);
	ScalarConverter &operator=(const ScalarConverter &ref);
  public:
	ScalarConverter();
	~ScalarConverter();
	static void convert(const std::string &literal);
};
