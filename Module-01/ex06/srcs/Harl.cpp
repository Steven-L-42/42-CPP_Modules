/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slippert <slippert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 10:23:32 by slippert          #+#    #+#             */
/*   Updated: 2023/12/04 17:14:53 by slippert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Harl.hpp"

Harl::Harl() {}
Harl::~Harl() {}

void Harl::error(void)
{
	std::cout
	<< "[ ERROR ]" << std::endl
	<< "ERROR MESSAGE\n" << std::endl;
}

void Harl::warning(void)
{
	std::cout
	<< "[ WARNING ]" << std::endl
	<< "WARNING MESSAGE\n" << std::endl;
}

void Harl::info(void)
{
	std::cout
	<< "[ INFO ]" << std::endl
	<< "INFO MESSAGE\n" << std::endl;
}

void Harl::debug(void)
{
	std::cout
	<< "[ DEBUG ]" << std::endl
	<< "DEBUG MESSAGE!\n" << std::endl;
}

void Harl::complain(std::string level)
{
	std::unordered_map<std::string, int> levelMap;
	levelMap.insert(std::make_pair("DEBUG", 1));
	levelMap.insert(std::make_pair("INFO", 2));
	levelMap.insert(std::make_pair("WARNING", 3));
	levelMap.insert(std::make_pair("ERROR", 4));
	levelMap.insert(std::make_pair(level, 5));
	std::unordered_map<std::string, int>::iterator it = levelMap.find(level);
	switch (it->second)
	{
		case 1:
			debug();
		case 2:
			info();
		case 3:
			warning();
		case 4:
			error();
		break;
		default:
			std::cout << "[ WRONG COMMAND ]" << std::endl;
		break;
	}
}
