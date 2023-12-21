/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slippert <slippert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 14:04:15 by slippert          #+#    #+#             */
/*   Updated: 2023/12/19 16:31:42 by slippert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/AMateria.hpp"

AMateria::AMateria() : _type("")
{
	std::cout
	<< "AMateria default constructor called"
	<< std::endl;
}

AMateria::AMateria(std::string const & type) : _type(type)
{
	std::cout
	<< "AMateria constructor '"
	<< this->_type
	<< "' called"
	<< std::endl;
}

AMateria::AMateria(AMateria &other)
{
	std::cout
	<< "AMateria copy constructor '"
	<< this->_type
	<< "' called"
	<< std::endl;

	*this = other;
}

AMateria::~AMateria()
{
	std::cout
	<< "AMateria destructor '"
	<< this->_type
	<< "' called"
	<< std::endl;
}

AMateria& AMateria::operator=(AMateria &other)
{
	std::cout
	<< "AMateria copy operator '"
	<< this->_type
	<< "' called"
	<< std::endl;

	this->_type = other._type;
	return *this;
}

std::string const & AMateria::getType() const
{
	return (this->_type);
}

void AMateria::use(ICharacter& target)
{
	std::cout
	<< "AMateria "
	<< this->_type
	<< " used on "
	<< target.getName()
	<< std::endl;
}