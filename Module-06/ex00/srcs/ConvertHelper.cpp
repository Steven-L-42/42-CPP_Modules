/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ConvertHelper.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slippert <slippert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 18:02:26 by slippert          #+#    #+#             */
/*   Updated: 2024/01/23 18:56:29 by slippert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ConvertHelper.hpp"

// ConvertHelper::ConvertHelper()
// {
// }

ConvertHelper::ConvertHelper(const std::string _input) : input(_input)
{
}

// ConvertHelper::ConvertHelper(const ConvertHelper &ref)
// {
// }

// ConvertHelper &ConvertHelper::operator=(const ConvertHelper &ref)
// {
// 	*this = ref;
// 	return (*this);
// }

ConvertHelper::~ConvertHelper()
{
}

void ConvertHelper::Preset()
{
	isStringOrEmpty = false;
	isDouble = false;
	isFloat = false;
	isChar = false;
	charIssue = false;
	intIssue = false;
	floatIssue = false;
	doubleIssue = false;
	if (input == "inf" || input == "+inf" || input == "inff" || input == "+inff" || input == "-inf" || input == "-inff" || input == "nan" || input == "nanf")
	{
		isSpecial = true;
		if (input == "nanf")
			input = "nan";
		if (input == "inf")
		{
			input = "+inf";
			isDouble = true;
		}
		if (input == "-inf" || input == "+inf" || input == "nan")
			isDouble = true;

		if (input == "inff")
		{
			input = "+inff";
			isFloat = true;
		}
		if (input == "-inff" || input == "+inff")
			isFloat = true;
	}
	else
		isSpecial = false;
}

// static_cast : Ein Typumwandlungen zur Kompilierzeit.
// Er wird verwendet, um bekannte und sichere Typkonvertierungen durchzuführen.
void ConvertHelper::ToChar()
{
	if (input.size() >= 1)
	{
		char tmp[input.size() + 1];
		strcpy(tmp, input.c_str());
		bool alldigit = true;
		int countchars = 0;

		for (std::string::iterator it = input.begin(); it != input.end(); ++it)
		{
			if (!std::isdigit(*it) && *it != 'f' && *it != '.')
				alldigit = false;
			if (static_cast<unsigned char>(*it) >= 0 && static_cast<unsigned char>(*it) <= 127)
				countchars++;
		}
		if (input[0] == 'f' || input[0] == '.')
			alldigit = false;
		if (!alldigit)
		{
			for (std::string::iterator it = input.begin(); it != input.end(); ++it)
			{
				if (static_cast<unsigned char>(*it) < 0 || static_cast<unsigned char>(*it) > 127)
				{
					isStringOrEmpty = true;
					return;
				}
			}
		}
		if (alldigit)
		{
			int tmp_i = std::atoi(tmp);
			if (tmp_i < 0 || tmp_i > 127)
			{
				charIssue = true;
				char_Issue = "impossible";
				return;
			}
			if ((tmp_i >= 0 && tmp_i <= 32) || tmp_i == 127)
			{
				charIssue = true;
				char_Issue = "Non displayable";
				return;
			}
			char_con = static_cast<char>(tmp_i);
		}
		else if ((size_t)countchars == input.size())
		{
			if (countchars == 1)
			{
				isChar = true;
				char_con = input[0];
			}
			else
			{
				isStringOrEmpty = true;
				charIssue = true;
				char_Issue = "impossible";
			}
		}
		else
		{
			charIssue = true;
			char_Issue = "impossible";
		}
	}
	else
		isStringOrEmpty = true;
}

void ConvertHelper::ToInt()
{
	if (isChar)
	{
		int_con = static_cast<int>(char_con);
		return;
	}
	char tmp[input.size() + 1];
	strcpy(tmp, input.c_str());
	long tmp_l = static_cast<long>(std::atol(tmp));
	if (tmp_l > INT_MAX || tmp_l < INT_MIN)
	{
		intIssue = true;
		int_Issue = "impossible";
	}
	else
		int_con = static_cast<int>(std::atoi(tmp));
}

void ConvertHelper::ToFloat()
{
	if (isChar)
	{
		float_con = static_cast<float>(char_con);
		return;
	}
	char tmp[input.size() + 1];
	strcpy(tmp, input.c_str());
	double tmp_d = strtod(input.c_str(), NULL);
	if (tmp_d > FLT_MAX || tmp_d < -FLT_MAX)
	{

		floatIssue = true;
		float_Issue = "impossible";
		std::cout << float_Issue << std::endl;
	}
	else
		float_con = static_cast<float>(std::atof(tmp));
}

void ConvertHelper::ToDouble()
{
	if (isChar)
	{
		double_con = static_cast<double>(char_con);
		return;
	}
	char tmp[input.size() + 1];
	strcpy(tmp, input.c_str());
	long double tmp_ld = strtold(input.c_str(), NULL);
	if (tmp_ld > DBL_MAX || tmp_ld < -DBL_MAX)
	{
		doubleIssue = true;
		double_Issue = "impossible";
	}
	else
		double_con = strtod(input.c_str(), NULL);
}

void ConvertHelper::Convert()
{
	if (isSpecial)
		return;
	ToChar();
	ToInt();
	ToFloat();
	ToDouble();
}

void ConvertHelper::PrintResults()
{
	if (!isStringOrEmpty && isSpecial)
	{
		std::cout << "Char: impossible" << std::endl;
		std::cout << "Int: impossible" << std::endl;
		std::cout << "Float: " << input << (isDouble ? "f" : "") << std::endl;
		if (isFloat)
		{
			size_t pos = input.find_last_of('f');
			if (pos != std::string::npos && input.find_first_of('f') != pos)
				input.erase(pos);
		}
		std::cout << "Double: " << input << std::endl;
	}
	else if (!isStringOrEmpty)
	{
		std::stringstream ssf;
		ssf << std::setprecision(6) << float_con;
		std::string float_con_str = ssf.str();

		std::stringstream ssd;
		ssd << std::setprecision(15) << double_con;
		std::string double_con_str = ssd.str();

		std::cout << "Char: " << (charIssue ? char_Issue : "'" + std::string(1, char_con) + "'") << std::endl;
		std::cout << "Int: " << (intIssue ? int_Issue : std::to_string(int_con)) << std::endl;
		std::cout << "Float: " << (floatIssue ? float_Issue : (float_con_str.find('.') != std::string::npos ? float_con_str + "f" : float_con_str + ".0f")) << std::endl;
		std::cout << "Double: " << (doubleIssue ? double_Issue : (double_con_str.find('.') != std::string::npos ? double_con_str : double_con_str + ".0")) << std::endl;
	}
	else
	{
		std::cout << "Char: impossible" << std::endl;
		std::cout << "Int: impossible" << std::endl;
		std::cout << "Float: impossible" << std::endl;
		std::cout << "Double: impossible" << std::endl;
	}
}
