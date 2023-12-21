/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slippert <slippert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 11:34:48 by slippert          #+#    #+#             */
/*   Updated: 2023/12/19 13:25:11 by slippert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout
	<< "Cat Default constructor is called"
	<< std::endl;
	this->brain = new Brain();
}

Cat::~Cat()
{
	std::cout
	<< "Cat destructor is called"
	<< std::endl;
	delete (this->brain);
}

Cat::Cat(const Cat &other) : Animal(other)
{
	std::cout
	<< "Cat copy constructor is called"
	<< std::endl;
	this->type = other.type;
	this->brain = new Brain();
}

Cat& Cat::operator=(const Cat &other)
{
	std::cout
	<< "Cat copy operator is called"
	<< std::endl;
	this->type = other.type;
	return *this;
}

void Cat::makeSound(void) const
{
	std::cout
	<< "Miau"
	<< std::endl;
}