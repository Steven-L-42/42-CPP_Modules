/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slippert <slippert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 10:23:35 by slippert          #+#    #+#             */
/*   Updated: 2023/12/13 17:54:56 by slippert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int _value;
		static const int fractionalBits = 8;
	public:
		Fixed();
		Fixed(const Fixed &copy);
		Fixed(const int newInt);
		Fixed(const float newFloat);
		~Fixed();
		Fixed& operator=(const Fixed &other);
		bool operator>(const Fixed &other);
		bool operator<(const Fixed &other);
		bool operator>=(const Fixed &other);
		bool operator<=(const Fixed &other);
		bool operator==(const Fixed &other);
		bool operator!=(const Fixed &other);

		Fixed operator+(const Fixed &other);
		Fixed operator-(const Fixed &other);
		Fixed operator*(const Fixed &other);
		Fixed operator/(const Fixed &other);

		Fixed operator++(int);
		Fixed operator--(int);
		Fixed &operator++();
		Fixed &operator--();
		static Fixed& min(Fixed &a, Fixed &b);
		static const Fixed& min(const Fixed &a, const Fixed &b);
		static Fixed& max(Fixed &a, Fixed &b);
		static const Fixed& max(const Fixed &a, const Fixed &b);
		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat( void ) const;
		int toInt( void ) const;

};

std::ostream &operator<<(std::ostream &stream, const Fixed &nbr);
