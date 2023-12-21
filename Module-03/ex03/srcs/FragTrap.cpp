/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slippert <slippert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 16:21:30 by slippert          #+#    #+#             */
/*   Updated: 2023/12/18 13:08:02 by slippert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/FragTrap.hpp"

FragTrap::FragTrap(std::string _Name) : ClapTrap(_Name)
{
	this->hit_points = 100;
	this->energy_points = 100;
	this->attack_damage = 30;
	std::cout
	<< "FragTrap constructor created!"
	<< std::endl;
}

FragTrap::~FragTrap()
{
	std::cout
	<< "FragTrap destructor called"
	<< std::endl;
}

void FragTrap::highFivesGuys(void)
{
	if (this->energy_points <= 0)
	{
		std::cout
		<< "FragTrap "
		<< this->name
		<< " has no energy!"
		<< std::endl;
		return ;
	}
	std::cout
	<< "FragTrap "
	<< this->name
	<< " give HighFive"
	<< std::endl;
	this->energy_points -= 1;
}