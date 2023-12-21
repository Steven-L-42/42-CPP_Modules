/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slippert <slippert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 12:31:41 by slippert          #+#    #+#             */
/*   Updated: 2023/12/20 15:45:46 by slippert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	std::cout
	<< "WrongCat Default constructor is called"
	<< std::endl;
}

WrongCat::~WrongCat()
{
	std::cout
	<< "WrongCat destructor is called"
	<< std::endl;
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other)
{
	std::cout
	<< "WrongCat copy constructor is called"
	<< std::endl;
	*this = other;
}

WrongCat& WrongCat::operator=(const WrongCat &other)
{
	std::cout
	<< "WrongCat copy operator is called"
	<< std::endl;
	this->type = other.type;
	return *this;
}

void WrongCat::makeSound(void) const
{
	std::cout
	<< "Miau"
	<< std::endl;
}