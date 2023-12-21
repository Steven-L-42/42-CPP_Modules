/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slippert <slippert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 20:43:06 by slippert          #+#    #+#             */
/*   Updated: 2023/12/12 14:23:09 by slippert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/HumanB.hpp"

HumanB::HumanB(std::string name)
{
	this->has_weapon = false;
	this->name = name;
}
HumanB::~HumanB()
{
	std::cout
	<< name
	<< " died"
	<< std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
	this->has_weapon = true;
	this->_weapon = &weapon;
	std::cout
	<< this->name
	<< " is now assaulted with "
	<< this->_weapon->getType()
	<< std::endl;
}

void HumanB::attack()
{
	if (this->has_weapon)
	{
		std::cout
		<< name
		<< " attacks with their "
		<< _weapon->getType()
		<< std::endl;
	}
	else
	{
		std::cout
		<< name
		<< " cant attack without a weapon!"
		<< std::endl;
	}

}
