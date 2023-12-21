/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slippert <slippert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 10:23:10 by slippert          #+#    #+#             */
/*   Updated: 2023/12/14 16:51:08 by slippert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Point.hpp"

bool	bsp(Point const a, Point const b, Point const c, Point const point);

void	result(bool check)
{
	if (check)
		std::cout << "Point is in the triangle" << std::endl;
	else
		std::cout << "Point is not in the triangle" << std::endl;
}

int	main(void)
{
	Point a(0, 0);
	Point b(10, 0);
	Point c(5, 5);
	{
		Point point(0, 0);
		result(bsp(a, b, c, point)); // false - x & y is on line
	}
	{
		Point point(1, 1);
		result(bsp(a, b, c, point)); // false - x & y is on line
	}
	{
		Point point(1, 0.99);
		result(bsp(a, b, c, point)); // true - y is 0.01 under a line
	}
	{
		Point point(5, 2.5);
		result(bsp(a, b, c, point)); // true - point is in the middle
	}
	{
		Point point(9.90, 0.09);
		result(bsp(a, b, c, point)); // true - x is 0.1 left from end | y is 0.01 under the highest spot
	}
	{
		Point point(9.90, 0.1);
		result(bsp(a, b, c, point)); // false - x is 0.1 left from end | y is exakt on the line
	}
	{
		Point point(20, 0);
		result(bsp(a, b, c, point)); // false - point is not on the triangle
	}
	{
		Point point(5, 10);
		result(bsp(a, b, c, point)); // false - point is not on the triangle
	}
	return (0);
}
