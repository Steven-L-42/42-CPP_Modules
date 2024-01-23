/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slippert <slippert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 21:02:05 by slippert          #+#    #+#             */
/*   Updated: 2024/01/23 13:45:38 by slippert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <string>
#include <cctype>

#define blue "\033[1;34m"
#define red "\033[1;31m"
#define green "\033[1;32m"
#define reset "\033[0m"

struct CSVRow
{
	std::map<int, std::string> btc;
	std::map<int, std::string> date;
	std::string rate;
	std::string error;
};

class BitcoinExchange
{
private:
	std::map<std::string, CSVRow> data;
	std::string input;
	BitcoinExchange();

public:
	BitcoinExchange(std::string &_input);
	BitcoinExchange(const BitcoinExchange &ref);
	BitcoinExchange &operator=(const BitcoinExchange &ref);
	~BitcoinExchange();
	void StartExchange();
	void LoadInputFile();
	void LoadExchangeRates();
	bool CheckDelims(std::string &column);
	bool CheckDateFormat(std::string &column);
	std::string trimWhitespaces(std::string &str);
};

BitcoinExchange::BitcoinExchange(std::string &_input) : input(_input)
{
	StartExchange();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &ref) {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &ref)
{
	if (this != &ref)
		*this = ref;
	return (*this);
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::LoadInputFile()
{
	std::ifstream file;
	if ((file.open(input.c_str()), file.fail()))
	{
		std::cerr << "Error: could not open file." << std::endl;
		return;
	}

	std::string line;
	std::getline(file, line);
	while (std::getline(file, line))
	{
		CSVRow row;

		std::istringstream lineStream(line);
		row.date.insert(std::make_pair(row.date.size(), lineStream.gcount()));
		if (std::getline(lineStream, row.date, '|') && std::getline(lineStream, row.btc, '|'))
		{
			row.date = trimWhitespaces(row.date);
			row.btc = trimWhitespaces(row.btc);

			if (CheckDateFormat(row.date))
			{
				std::cerr << "Error: wrong formated date." << std::endl;
				return;
			}
			long number = static_cast<long>(std::atol(row.btc.c_str()));
			if (number < 0 || number > INT_MAX)
			{
				if (number > INT_MAX)
					row.error = "Error: too large a number.";
				else
					row.error = "Error: not a positive number.";
				row.date = "";
			}
			if (data.find(row.date) != data.end())
				std::cout << "TEST" << row.date << std::endl;
			std::pair<std::string, CSVRow> newRow(row.date, row);
			data.insert(newRow);
			// data.push_back(row);
		}
		else
		{
			row.error = "Error: bad input";
			std::pair<std::string, CSVRow> newRow(row.date, row);
			data.insert(newRow);
		}
	}
	for (std::map<std::string, CSVRow>::iterator it = data.begin(); it != data.end(); ++it)
	{
		std::cout << it->first << " => " << it->second.btc << std::endl;
	}
}

void BitcoinExchange::LoadExchangeRates()
{
	std::ifstream file;
	if ((file.open("data.csv"), file.fail()))
	{
		std::cerr << "Error: could not open file." << std::endl;
		return;
	}
	CSVRow row;
	std::string line;
	if (std::getline(file, line))
	{
		std::istringstream lineStream(line);
		if (std::getline(file, line, ','))
			row.date = line;
		std::cout << line << std::endl;
		if (std::getline(file, line))
			row.rate = line;
		std::cout << line << std::endl;
	}
}
void BitcoinExchange::StartExchange()
{
	LoadInputFile();
	LoadExchangeRates();
	// for (size_t i = 0; i < data.size(); i++)
	// {
	// 	std::cout << data[i].date << (data[i].btc != "" ? " => " : "") << data[i].btc << std::endl;
	// }
}

bool BitcoinExchange::CheckDelims(std::string &column)
{
	size_t count = 0;
	size_t pos = 0;

	while (column[pos])
	{
		if (column[pos] == '-')
			count++;
		pos++;
	}
	if (count != 2)
		return (false);
	return (true);
}

bool BitcoinExchange::CheckDateFormat(std::string &column)
{
	int i = 0;
	int count = 0;
	int cycle = 0;
	int delim = 0;
	int size = column.size();
	if (size != 10 || !CheckDelims(column))
		return (true);
	for (size_t i = 0; i < size; i++)
	{
		if (cycle == 0) // Check Year
		{
			if (column[i] == '-' && count == 4)
			{
				count = 0;
				cycle++;
				continue;
			}
			else if (std::isdigit(column[i]))
				count++;
			else
				return (true);
		}
		if (cycle == 1) // Check Month
		{
			if (column[i] == '-' && count == 2)
			{
				count = 0;
				cycle++;
				continue;
			}
			else if (std::isdigit(column[i]))
				count++;
			else
				return (true);
		}
		if (cycle == 2) // Check Days
		{
			if (std::isdigit(column[i]))
				count++;
			else
				return (true);
			if (count == 2)
				break;
		}
	}
	return (false);
}

std::string BitcoinExchange::trimWhitespaces(std::string &str)
{
	size_t start = str.find_first_not_of(" \t\n\r");
	size_t end = str.find_last_not_of(" \t\n\r");

	if (start == std::string::npos || end == std::string::npos)
		return ("");
	return (str.substr(start, end - start + 1));
}
