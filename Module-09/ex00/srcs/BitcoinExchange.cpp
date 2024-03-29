/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slippert <slippert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 15:23:57 by slippert          #+#    #+#             */
/*   Updated: 2024/02/15 10:56:13 by slippert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(std::string &_input) : input(_input)
{
	StartExchange();
}

// BitcoinExchange::BitcoinExchange(const BitcoinExchange &ref) {}

// BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &ref)
// {
// 	if (this != &ref)
// 		*this = ref;
// 	return (*this);
// }

BitcoinExchange::~BitcoinExchange() {}

bool BitcoinExchange::isNumeric(char c)
{
	return (c >= '0' && c <= '9');
}

bool BitcoinExchange::isAlphabetical(char c)
{
	return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

bool BitcoinExchange::isNotANumberOrFloat(std::string &input)
{
	bool foundDot = false;
	bool foundDigit = false;

	for (std::string::iterator it = input.begin(); it != input.end(); it++)
	{
		if ((*it < '0' || *it > '9') && *it != '.' && *it != '-')
			return true;

		if (*it == '.')
		{
			if (foundDot || !foundDigit)
				return true;
			else
				foundDot = true;
		}

		if (*it >= '0' && *it <= '9')
			foundDigit = true;
	}
	return false;
}

bool BitcoinExchange::CheckLine(std::string &line, std::ifstream &file)
{
	std::string::iterator it;
	std::getline(file, line);

	it = std::find_if(line.begin(), line.end(), isNumeric);
	if (it == line.end())
		return (false);
	it = std::find(it, line.end(), '|');
	if (it == line.end())
		return (false);
	it = std::find_if(it, line.end(), isNumeric);
	if (it == line.end())
		return (false);
	return (true);
}

bool BitcoinExchange::CheckHeader(std::string &line, std::ifstream &file)
{
	std::string::iterator it;
	std::getline(file, line);

	it = std::find_if(line.begin(), line.end(), isAlphabetical);
	if (it == line.end())
		return (false);
	it = std::find(it, line.end(), '|');
	if (it == line.end())
		return (false);
	it = std::find_if(it, line.end(), isAlphabetical);
	if (it == line.end())
		return (false);
	return (true);
}

void BitcoinExchange::LoadInputFile()
{
	std::string line;
	std::ifstream file;
	if ((file.open(input.c_str()), file.fail()))
	{
		std::cerr << "Error: could not open file." << std::endl;
		return;
	}

	if (!CheckHeader(line, file))
	{
		std::cerr << "Error: header is missing or not valid." << std::endl;
		return;
	}

	while (std::getline(file, line))
	{
		if (line.length() == 0)
			continue;
		CSVRow row;

		std::istringstream lineStream(line);

		row.error = "";
		row.rate = 0;
		std::string btc;

		if (std::getline(lineStream, row.date, '|') && std::getline(lineStream, btc, '|'))
		{
			row.date = trimWhitespaces(row.date);
			btc = trimWhitespaces(btc);

			if (CheckDateFormat(row.date) || CheckDateValid(row.date))
			{
				row.btc = 0.0;
				row.error = "Error: bad input";
				map_input.insert(std::make_pair(map_input.size(), row));
			}
			else
			{
				long long_Number = static_cast<long>(std::atol(btc.c_str()));
				if (btc.length() == 0)
				{
					row.error = "Error: missing number.";
					row.date = "";
				}
				else
				{
					if (isNotANumberOrFloat(btc))
					{
						row.error = "Error: is not number.";
						row.date = "";
					}
				}
				if ((long_Number <= 0 && !isNotANumberOrFloat(btc)) || long_Number >= 1000)
				{
					if (long_Number >= 1000)
						row.error = "Error: too large a number.";
					else
						row.error = "Error: not a positive number.";
					row.date = "";
				}
				float float_Number = static_cast<float>(std::atof(btc.c_str()));
				row.btc = float_Number;
				if (row.date != "")
				{
					std::string splitted;
					std::istringstream dateStream(row.date);
					std::getline(dateStream, splitted, '-');
					row.year = static_cast<int>(std::atoi(splitted.c_str()));
					std::getline(dateStream, splitted, '-');
					row.month = static_cast<int>(std::atoi(splitted.c_str()));
					std::getline(dateStream, splitted, '-');
					row.day = static_cast<int>(std::atoi(splitted.c_str()));
				}
				map_input.insert(std::make_pair(map_input.size(), row));
			}
		}
		else
		{
			row.btc = 0.0;
			if (std::find(line.begin(), line.end(), '|') != line.end())
			{
				row.error = "Error: missing number.";
				row.date = "";
			}
			else
				row.error = "Error: bad input";
			map_input.insert(std::make_pair(map_input.size(), row));
		}
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
	std::string line;
	std::getline(file, line);

	while (std::getline(file, line))
	{
		CSVRow row;

		std::istringstream lineStream(line);
		std::string rate;
		if (std::getline(lineStream, row.date, ',') && std::getline(lineStream, rate, ','))
		{
			row.date = trimWhitespaces(row.date);
			rate = trimWhitespaces(rate);

			if (row.date != "")
			{
				std::string splitted;
				std::istringstream dateStream(row.date);
				std::getline(dateStream, splitted, '-');
				row.year = static_cast<int>(std::atoi(splitted.c_str()));
				std::getline(dateStream, splitted, '-');
				row.month = static_cast<int>(std::atoi(splitted.c_str()));
				std::getline(dateStream, splitted, '-');
				row.day = static_cast<int>(std::atoi(splitted.c_str()));
			}
			float float_Number = static_cast<float>(std::atof(rate.c_str()));
			row.rate = float_Number;
			map_rates.insert(std::make_pair(map_rates.size(), row));
		}
	}
}

void BitcoinExchange::FindClosestDay(iter it_map, iter rates)
{
	iter it_rates = rates;
	iter closest_it = rates;
	int daysDiffer = std::numeric_limits<int>::max();
	std::cout << it_map->second.day << std::endl;
	for (; it_rates != map_rates.end(); it_rates++)
	{
		if (std::abs(closest_it->second.day - it_map->second.day) < daysDiffer)
		{
			daysDiffer = std::abs(closest_it->second.day - it_map->second.day);
			closest_it = it_rates;
		}
	}
}

void BitcoinExchange::CombineRateToInput()
{
	iter it_map;
	iter it_rates;

	for (it_map = map_input.begin(); it_map != map_input.end(); it_map++)
	{
		if (it_map->second.error != "")
			continue;
		iter it_closest;
		int daysDiffer = std::numeric_limits<int>::max();
		bool foundClosest = false;
		for (it_rates = map_rates.begin(); it_rates != map_rates.end(); it_rates++)
		{
			if (it_map->second.date == it_rates->second.date)
			{
				foundClosest = true;
				it_closest->second.rate = it_rates->second.rate;
				break;
			}
			else if (it_map->second.year == it_rates->second.year && it_map->second.month == it_rates->second.month)
			{
				if (std::abs(it_rates->second.day - it_map->second.day) < daysDiffer)
				{
					daysDiffer = std::abs(it_rates->second.day - it_map->second.day);
					it_closest = it_rates;
					it_rates--;
					// Check DayBefore if rate was lower
					if (it_rates->second.rate < it_closest->second.rate && it_map->second.day < it_closest->second.day)
						it_closest = it_rates;
					it_rates++;
					it_rates++;
					// Check DayNext if rate was lower
					if (it_rates->second.rate < it_closest->second.rate && it_map->second.day > it_closest->second.day)
						it_closest = it_rates;
					it_rates--;
					foundClosest = true;
				}
			}
		}

		if (!foundClosest)
		{
			if (it_map->second.year < map_rates.begin()->second.year)
				it_map->second.rate = map_rates.begin()->second.rate;
			else
				it_map->second.rate = (--map_rates.cend())->second.rate;
		}
		else
			it_map->second.rate = it_closest->second.rate;
	}
}

void BitcoinExchange::StartExchange()
{
	LoadInputFile();
	LoadExchangeRates();
	CombineRateToInput();

	for (std::map<int, CSVRow>::iterator it = map_input.begin(); it != map_input.end(); ++it)
	{
		if (it->second.error != "" && it->second.date == "")
			std::cout << it->second.error << std::endl;
		else if (it->second.error != "" && it->second.date != "")
			std::cout << it->second.error << " => " << it->second.date << std::endl;
		else
			std::cout << it->second.date << " => " << it->second.btc << " => " << (it->second.btc * it->second.rate) << std::endl;
	}
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

bool BitcoinExchange::CheckDateValid(std::string &column)
{
	std::map<int, int> days;
	days.insert(std::make_pair(1, 31));
	days.insert(std::make_pair(2, 28));
	days.insert(std::make_pair(3, 31));
	days.insert(std::make_pair(4, 30));
	days.insert(std::make_pair(5, 31));
	days.insert(std::make_pair(6, 30));
	days.insert(std::make_pair(7, 31));
	days.insert(std::make_pair(8, 31));
	days.insert(std::make_pair(9, 30));
	days.insert(std::make_pair(10, 31));
	days.insert(std::make_pair(11, 30));
	days.insert(std::make_pair(12, 31));

	int year = static_cast<int>(std::atoi(column.substr(0, 4).c_str()));
	int month = static_cast<int>(std::atoi(column.substr(5, 2).c_str()));
	int day = static_cast<int>(std::atoi(column.substr(8, 2).c_str()));

	if ((month < 1 || month > 12))
		return (true);

	int maxDay = days[month];

	if (month == 2 && (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)))
		maxDay++;

	if (day < 1 || day > maxDay)
		return (true);
	return (false);
}

bool BitcoinExchange::CheckDateFormat(std::string &column)
{
	int count = 0;
	int cycle = 0;
	size_t size = column.size();
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
