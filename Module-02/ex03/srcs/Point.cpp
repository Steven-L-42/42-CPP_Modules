/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slippert <slippert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 10:59:04 by slippert          #+#    #+#             */
/*   Updated: 2023/12/14 11:33:30 by slippert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Point.hpp"

Point::Point() : x(0), y(0) {}

Point::Point(const float _x, const float _y) : x(_x), y(_y) {}

Point::Point(Point &copy) : x(copy.x), y(copy.y) {}

Point::~Point() {}

Point& Point::operator=(const Point &other)
{
	*this = other;
	return (*this);
}

int Point::getX() const
{
	return (x.getRawBits());
}

int Point::getY() const
{
	return (y.getRawBits());
}