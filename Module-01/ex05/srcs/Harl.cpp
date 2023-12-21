/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slippert <slippert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 10:23:32 by slippert          #+#    #+#             */
/*   Updated: 2023/12/04 17:11:31 by slippert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Harl.hpp"

Harl::Harl() {}
Harl::~Harl() {}

void Harl::error(void)
{
	std::cout << "ERROR MESSAGE" << std::endl;
}

void Harl::warning(void)
{
	std::cout << "WARNING MESSAGE" << std::endl;
}

void Harl::info(void)
{
	std::cout << "INFO MESSAGE" << std::endl;
}

void Harl::debug(void)
{
	std::cout << "DEBUG MESSAGE!" << std::endl;
}

void Harl::defaultAction(void) {}

void Harl::complain(std::string level)
{
	t_functions funcs[] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error, &Harl::defaultAction};
	std::string levels[] = { "DEBUG", "INFO", "WARNING", "ERROR", level};
	int i = 0;
	while (i < 5 && levels[i].compare(level))
		i++;
	(this->*funcs[i])();
}
