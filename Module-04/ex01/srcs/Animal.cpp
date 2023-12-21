/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slippert <slippert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 11:19:30 by slippert          #+#    #+#             */
/*   Updated: 2023/12/20 15:01:38 by slippert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Animal.hpp"

Animal::Animal() : type("Animal")
{
	std::cout
	<< "Animal constructor is called"
	<< std::endl;
}

Animal::Animal(std::string _type) : type(_type)
{
	std::cout
	<< "Animal constructor is called"
	<< std::endl;
}

Animal::~Animal()
{
	std::cout
	<< "Animal destructor is called"
	<< std::endl;
}

Animal::Animal(const Animal &other)
{
	std::cout
	<< "Animal copy constructor is called"
	<< std::endl;
	*this = other;
}

Animal& Animal::operator=(const Animal &other)
{
	std::cout
	<< "Animal copy operator is called"
	<< std::endl;
	this->type = other.type;
	return *this;
}

void Animal::makeSound() const
{
	std::cout
	<< "Animal makeSound called"
	<< std::endl;
}

std::string Animal::getType() const
{
	return (this->type);
}

void Animal::setType(std::string &type)
{
	this->type = type;
}