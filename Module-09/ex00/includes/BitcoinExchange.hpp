/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slippert <slippert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 21:02:05 by slippert          #+#    #+#             */
/*   Updated: 2024/02/14 16:20:57 by slippert         ###   ########.fr       */
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

class BitcoinExchange
{
private:
	struct CSVRow
	{
		int year;
		int month;
		int day;
		std::string date;
		float rate;
		float btc;
		std::string error;
	};
	typedef std::map<int, CSVRow>::iterator iter;
	std::map<int, CSVRow> map_input;
	std::map<int, CSVRow> map_rates;
	std::string input;
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &ref);
	BitcoinExchange &operator=(const BitcoinExchange &ref);
	bool CheckHeader(std::string &line, std::ifstream &file);
	bool CheckLine(std::string &line, std::ifstream &file);
	void StartExchange();
	void LoadInputFile();
	void LoadExchangeRates();
	bool CheckDelims(std::string &column);
	bool CheckDateFormat(std::string &column);
	bool CheckDateValid(std::string &column);
	void CombineRateToInput();
	void FindClosestDay(iter map, iter rates);
	static bool isAlphabetical(char c);
	bool isNotANumberOrFloat(std::string &input);
	static bool isNumeric(char c);
	std::string trimWhitespaces(std::string &str);

public:
	BitcoinExchange(std::string &_input);
	~BitcoinExchange();
};
