/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slippert <slippert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 10:23:32 by slippert          #+#    #+#             */
/*   Updated: 2023/12/14 10:46:40 by slippert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Fixed.hpp"
#include "Fixed.hpp"
#include "Fixed.hpp"

Fixed::Fixed() : _value(0)
{
	std::cout
	<< "Default constructor called"
	<< std::endl;
}

Fixed::Fixed(Fixed &copy)
{
	std::cout
	<< "Copy constructor called"
	<< std::endl;
	*this = copy;
}

Fixed::~Fixed()
{
	std::cout
	<< "Destructor called"
	<< std::endl;
}

int Fixed::getRawBits(void) const
{
	std::cout
	<< "getRawBits member function called"
	<< std::endl;
	return (_value);
}

void Fixed::setRawBits(int const raw)
{
	std::cout
	<< "setRawBits member function called"
	<< std::endl;
	this->_value = raw;
}

Fixed &Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	_value = other.getRawBits();
	return (*this);
}
