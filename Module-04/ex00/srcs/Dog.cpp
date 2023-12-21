/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slippert <slippert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 11:35:38 by slippert          #+#    #+#             */
/*   Updated: 2023/12/19 13:31:26 by slippert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	std::cout
	<< "Dog Default constructor is called"
	<< std::endl;
}

Dog::~Dog()
{
	std::cout
	<< "Dog destructor is called"
	<< std::endl;
}

Dog::Dog(const Dog &other) : Animal(other)
{
	std::cout
	<< "Dog copy constructor is called"
	<< std::endl;
	*this = other;
}

Dog& Dog::operator=(const Dog &other)
{
	std::cout
	<< "Dog copy operator is called"
	<< std::endl;
	this->type = other.type;
	return *this;
}

void Dog::makeSound(void) const
{
	std::cout
	<< "Wau Wau"
	<< std::endl;
}
