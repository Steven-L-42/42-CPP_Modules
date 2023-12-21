/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slippert <slippert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 16:21:30 by slippert          #+#    #+#             */
/*   Updated: 2023/12/18 14:14:56 by slippert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string _name) : ClapTrap(_name + "_clap_name"), FragTrap(_name), ScavTrap(_name)
{
	this->hit_points = FragTrap::_hit_points;
    this->energy_points = ScavTrap::_energy_points;
    this->attack_damage = FragTrap::_attack_power;
	this->name = _name;
	std::cout << "DiamondTrap constructor created!" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout
	<< "DiamondTrap destructor called"
	<< std::endl;
}

void DiamondTrap::whoAmI()
{
	std::cout
	<< "WhoAmI ?"
	<< "\nDiamondTrap Name is: "
	<< this->name
	<< "\nClapTrap Name is: "
	<< ClapTrap::name
	<< std::endl;
}
