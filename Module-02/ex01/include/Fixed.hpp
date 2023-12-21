/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slippert <slippert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 10:23:35 by slippert          #+#    #+#             */
/*   Updated: 2023/12/13 15:56:56 by slippert         ###   ########.fr       */
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
		Fixed& operator=(const Fixed& other);
		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat( void ) const;
		int toInt( void ) const;

};

std::ostream &operator<<(std::ostream &stream, const Fixed &nbr);
