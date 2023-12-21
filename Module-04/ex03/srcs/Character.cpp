/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slippert <slippert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 14:04:15 by slippert          #+#    #+#             */
/*   Updated: 2023/12/19 17:37:18 by slippert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Character.hpp"

Character::Character( std::string const & _name ) : name(_name)
{
	for (int i = 0; i < 4; i++)
	{
		this->inventory[i] = NULL;
	}
	std::cout
	<< "Character "
	<< this->name
	<< " created"
	<< std::endl;
}

Character::Character(const Character  &other) : name(other.name)
{
	*this = other;
	std::cout
	<< "Character "
	<< this->name
	<< " created"
	<< std::endl;
}

Character& Character::operator=(const Character &other)
{
	this->name = other.name;
	for (int i = 0; i < 4; i++)
	{
		this->inventory[i] = other.inventory[i];
	}
	return *this;
}

Character::~Character()
{
	std::cout
	<< "Character "
	<< this->name
	<< " destroyed"
	<< std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (this->inventory[i])
			delete this->inventory[i];
	}
}

void Character::equip(AMateria* mat)
{
	for (int i = 0; i < 4; i++)
	{
		if (!this->inventory[i])
		{
			this->inventory[i] = mat;
			std::cout
			<< "Character "
			<< this->name
			<< " equipped with "
			<< mat->getType()
			<< std::endl;
			return;
		}
	}
	std::cout
	<< "Character "
	<< this->name
	<< " can't equip "
	<< mat->getType()
	<< std::endl;
}

void Character::unequip(int idx)
{
	if (this->inventory[idx])
	{
		delete this->inventory[idx];
		this->inventory[idx] = NULL;
		std::cout
		<< "Character "
		<< this->name
		<< " unequipped"
		<< std::endl;
	}
	else
	{
		std::cout
		<< "Character "
		<< this->name
		<< " can't unequip"
		<< std::endl;
	}
}

void    Character::use(int idx, ICharacter& target)
{
	if (this->inventory[idx])
	{
		this->inventory[idx]->use(target);
		std::cout
		<< "Character "
		<< this->name
		<< " uses "
		<< this->inventory[idx]->getType()
		<< std::endl;
	}
	else
	{
		std::cout
		<< "Character "
		<< this->name
		<< " can't use"
		<< std::endl;
	}
}

std::string const & Character::getName() const
{
	return this->name;
}