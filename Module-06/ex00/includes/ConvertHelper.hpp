/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ConvertHelper.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slippert <slippert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 21:02:05 by slippert          #+#    #+#             */
/*   Updated: 2024/01/19 14:17:02 by slippert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <cctype>
#include <cfloat>
#include <iomanip>
#include <sstream>
class ConvertHelper
{
  private:
	std::string input;
	char char_con;
	int	int_con;
	float float_con;
	double double_con;
	bool	isSpecial;
	bool	isFloat;
	bool	isChar;
	bool	isDouble;
	bool	isStringOrEmpty;
	bool	charIssue;
	bool	intIssue;
	bool	floatIssue;
	bool	doubleIssue;
	std::string char_Issue;
	std::string int_Issue;
	std::string float_Issue;
	std::string double_Issue;
  public:
	ConvertHelper();
	ConvertHelper(const std::string _input);
	ConvertHelper(const ConvertHelper &ref);
	ConvertHelper &operator=(const ConvertHelper &ref);
	~ConvertHelper();
	void Preset();
	void Convert();
	void PrintResults();
	void ToChar();
	void ToInt();
	void ToFloat();
	void ToDouble();
};
