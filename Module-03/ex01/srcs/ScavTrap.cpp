/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slippert <slippert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 12:48:09 by slippert          #+#    #+#             */
/*   Updated: 2023/12/18 13:08:02 by slippert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScavTrap.hpp"

ScavTrap::ScavTrap(std::string _Name) : ClapTrap(_Name)
{
	this->hit_points = 100;
	this->energy_points = 50;
	this->attack_damage = 20;
	std::cout << "ScavTrap " << _Name << " created!" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called" << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap is now in Gatekeeper mode" << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
	if (energy_points <= 0)
	{
		std::cout
		<< "ScavTrap "
		<< name
		<< " has no energy!"
		<< std::endl;
		return ;
	}
	if (hit_points <= 0)
	{
		std::cout
		<< "ScavTrap "
		<< name
		<< " cant attack when dead!"
		<< std::endl;
		return ;
	}
	std::cout
	<< "ScavTrap "
	<< this->name
	<< " attacks "
	<< target
	<< ", causing "
	<< this->attack_damage
	<< " points of damage!"
	<< std::endl;
	this->energy_points--;
}
