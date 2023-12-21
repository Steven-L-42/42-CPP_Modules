/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slippert <slippert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 10:23:32 by slippert          #+#    #+#             */
/*   Updated: 2023/12/14 16:34:36 by slippert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Fixed.hpp"

Fixed::Fixed() : _value(0)
{
	if (activateMessages)
		std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copy)
{
	if (activateMessages)
		std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed::Fixed(const int newInt) : _value(newInt * (1 << Fixed::fractionalBits))
{
	if (activateMessages)
		std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float newFloat) : _value(roundf(newFloat * (1 << Fixed::fractionalBits)))
{
	if (activateMessages)
		std::cout << "Float constructor called" << std::endl;
}
Fixed::~Fixed()
{
	if (activateMessages)
		std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	return (_value);
}

void Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	if (activateMessages)
		std::cout << "Copy assignment operator called" << std::endl;
	_value = other.getRawBits();
	return (*this);
}

std::ostream &operator<<(std::ostream &stream, const Fixed &nbr)
{
	stream << nbr.toFloat();
	return (stream);
}

float Fixed::toFloat(void) const
{
	return (float)this->_value / (float)(1 << Fixed::fractionalBits);
}

int Fixed::toInt(void) const
{
	return (this->_value >> Fixed::fractionalBits);
}

Fixed Fixed::operator++(int)
{
	Fixed temp(*this);
	_value++;
	return (temp);
}

Fixed Fixed::operator--(int)
{
	Fixed temp(*this);
	_value--;
	return (temp);
}

Fixed &Fixed::operator++()
{
	this->_value += 1;
	return (*this);
}

Fixed &Fixed::operator--()
{
	this->_value -= 1;
	return (*this);
}

Fixed Fixed::operator+(const Fixed &other)
{
	return (Fixed(this->toFloat() + other.toFloat()));
}

Fixed Fixed::operator-(const Fixed &other)
{
	return (Fixed(this->toFloat() - other.toFloat()));
}

Fixed Fixed::operator*(const Fixed &other)
{
	return (Fixed(this->toFloat() * other.toFloat()));
}

Fixed Fixed::operator/(const Fixed &other)
{
	return (Fixed(this->toFloat() / other.toFloat()));
}

bool Fixed::operator>(const Fixed &other)
{
	return (this->_value > other.getRawBits());
}

bool Fixed::operator<(const Fixed &other)
{
	return (this->_value < other.getRawBits());
}

bool Fixed::operator<=(const Fixed &other)
{
	return (this->_value <= other.getRawBits());
}

bool Fixed::operator>=(const Fixed &other)
{
	return (this->_value >= other.getRawBits());
}

bool Fixed::operator==(const Fixed &other)
{
	return (this->_value == other.getRawBits());
}

bool Fixed::operator!=(const Fixed &other)
{
	return (this->_value != other.getRawBits());
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	if (a.getRawBits() < b.getRawBits())
		return (a);
	return (b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a.getRawBits() < b.getRawBits())
		return (a);
	return (b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	if (a.getRawBits() > b.getRawBits())
		return (a);
	return (b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a.getRawBits() > b.getRawBits())
		return (a);
	return (b);
}
