/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slippert <slippert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 20:40:48 by slippert          #+#    #+#             */
/*   Updated: 2023/12/03 21:30:05 by slippert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) :_weapon(weapon)
{
	this->name = name;

	std::cout
	<< this->name
	<< " is now assaulted with "
	<< this->_weapon.getType()
	<< std::endl;
}

HumanA::~HumanA()
{
	std::cout
	<< name
	<< " died"
	<< std::endl;
}

void HumanA::attack()
{
	std::cout
	<< name
	<< " attacks with their "
	<< _weapon.getType()
	<< std::endl;
}
