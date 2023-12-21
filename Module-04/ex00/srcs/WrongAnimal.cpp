/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slippert <slippert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 12:30:39 by slippert          #+#    #+#             */
/*   Updated: 2023/12/19 12:30:42 by slippert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("no type")
{
	std::cout
	<< "WrongAnimal constructor is called"
	<< std::endl;
}

WrongAnimal::WrongAnimal(std::string _type) : type(_type)
{
	std::cout
	<< "WrongAnimal constructor is called"
	<< std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout
	<< "WrongAnimal destructor is called"
	<< std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
	std::cout
	<< "WrongAnimal copy constructor is called"
	<< std::endl;
	*this = other;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &other)
{
	std::cout
	<< "WrongAnimal copy operator is called"
	<< std::endl;
	this->type = other.type;
	return *this;
}

void WrongAnimal::makeSound() const
{
	std::cout
	<< "WrongAnimal makeSound called"
	<< std::endl;
}

std::string WrongAnimal::getType() const
{
	return (this->type);
}

void WrongAnimal::setType(std::string &type)
{
	this->type = type;
}