/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slippert <slippert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 14:04:15 by slippert          #+#    #+#             */
/*   Updated: 2023/12/20 14:17:57 by slippert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Ice.hpp"

Ice::Ice() : AMateria("ice")
{
	std::cout
	<< "Ice constructor '"
	<< this->_type
	<< "' called"
	<< std::endl;
}

Ice::Ice(const Ice &other) : AMateria("ice")
{
	std::cout
	<< "Ice copy constructor '"
	<< this->_type
	<< "' called"
	<< std::endl;

	*this = other;
}

Ice::~Ice()
{
	std::cout
	<< "Ice destructor '"
	<< this->_type
	<< "' called"
	<< std::endl;
}

Ice& Ice::operator=(const Ice &other)
{
	std::cout
	<< "Ice copy operator '"
	<< this->_type
	<< "' called"
	<< std::endl;

	this->_type = other._type;
	return *this;
}

AMateria* Ice::clone() const
{
	return (new Ice(*this));
}


void Ice::use(ICharacter& target)
{
	std::cout
	<< "* shoots an ice bolt at "
	<< target.getName()
	<< " *"
	<< std::endl;
}
