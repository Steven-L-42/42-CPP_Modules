/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slippert <slippert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 14:04:15 by slippert          #+#    #+#             */
/*   Updated: 2023/12/19 17:43:20 by slippert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Cure.hpp"

Cure::Cure() : AMateria("cure")
{
	std::cout
	<< "Cure constructor '"
	<< this->_type
	<< "' called"
	<< std::endl;
}

Cure::Cure(const Cure &other) : AMateria("cure")
{
	std::cout
	<< "Cure copy constructor '"
	<< this->_type
	<< "' called"
	<< std::endl;

	*this = other;
}

Cure::~Cure()
{
	std::cout
	<< "Cure destructor '"
	<< this->_type
	<< "' called"
	<< std::endl;
}

Cure& Cure::operator=(const Cure &other)
{
	std::cout
	<< "Cure copy operator '"
	<< this->_type
	<< "' called"
	<< std::endl;

	this->_type = other._type;
	return *this;
}

AMateria* Cure::clone() const
{
	return (new Cure(*this));
}

void Cure::use(ICharacter& target)
{
	std::cout
	<< "* heals "
	<< target.getName()
	<< "'s wounds *"
	<< std::endl;
}
