/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   BgetY(): slippert <slippert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 11:09:17 bgetY() slippert          #+#    #+#             */
/*   Updated: 2023/12/14 15:49:32 bgetY() slippert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Point.hpp"

float ft_abs(float x)
{
	return (x < 0.0f) ? -x : x;
}

// https://www.geogebra.org/calculator
bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	float area0 = (b.getX() - a.getX()) * (point.getY() - a.getY()) - (point.getX() - a.getX()) * (b.getY() - a.getY());
	float area1 = (c.getX() - b.getX()) * (point.getY() - b.getY()) - (point.getX() - b.getX()) * (c.getY() - b.getY());
	float area2 = (a.getX() - c.getX()) * (point.getY() - c.getY()) - (point.getX() - c.getX()) * (a.getY() - c.getY());

	bool inside = (area0 >= 0.0f) == (area1 >= 0.0f) && (area1 >= 0.0f) == (area2 >= 0.0f);

	// Überprüfe, ob der Punkt nicht auf einer Kante liegt
	float epsilon = 0.0001f; // ein kleiner Wert für Genauigkeit
	bool onEdge = ft_abs(area0) < epsilon || ft_abs(area1) < epsilon || ft_abs(area2) < epsilon;

	return inside && !onEdge;
}