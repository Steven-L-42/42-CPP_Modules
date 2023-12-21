/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slippert <slippert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 12:00:51 by slippert          #+#    #+#             */
/*   Updated: 2023/12/18 13:08:02 by slippert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ClapTrap.hpp"

ClapTrap::ClapTrap()
{
}

ClapTrap::ClapTrap(std::string _Name) : name(_Name), hit_points(10), energy_points(10), attack_damage(0)
{
	std::cout << "ClapTrap " << name << " created!" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap &copy)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = copy;
}
ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called" << std::endl;
}
ClapTrap &ClapTrap::operator=(ClapTrap &other)
{
	this->name = other.name;
	this->hit_points = other.hit_points;
	this->energy_points = other.energy_points;
	this->attack_damage = other.attack_damage;
	return (*this);
}

void ClapTrap::attack(const std::string &target)
{
	if (energy_points <= 0)
	{
		std::cout
		<< "ClapTrap "
		<< name
		<< " has no energy!"
		<< std::endl;
		return ;
	}
	if (hit_points <= 0)
	{
		std::cout
		<< "ClapTrap "
		<< name
		<< " cant attack when dead!"
		<< std::endl;
		return ;
	}
	std::cout
	<< "ClapTrap "
	<< this->name
	<< " attacks "
	<< target
	<< ", causing "
	<< this->attack_damage
	<< " points of damage!"
	<< std::endl;
	this->energy_points--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (hit_points <= 0)
	{
		std::cout
		<< "ClapTrap "
		<< name
		<< " cant take damage when dead!"
		<< std::endl;
		return ;
	}
	std::cout
	<< "ClapTrap "
	<< this->name
	<< " taked "
	<< amount
	<< " points of damage!"
	<< std::endl;
	this->hit_points -= amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (energy_points <= 0)
	{
		std::cout
		<< "ClapTrap "
		<< name
		<< " has no energy!"
		<< std::endl;
		return ;
	}
	if (hit_points <= 0)
	{
		std::cout
		<< "ClapTrap "
		<< name
		<< " cant repair when dead!"
		<< std::endl;
		return ;
	}
	std::cout
	<< "ClapTrap "
	<< this->name
	<< " repaired "
	<< amount
	<< " points!"
	<< std::endl;
	this->hit_points += amount;
	this->energy_points--;
}
