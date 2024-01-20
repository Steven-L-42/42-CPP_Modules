/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slippert <slippert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 21:02:05 by slippert          #+#    #+#             */
/*   Updated: 2024/01/20 17:35:15 by slippert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template <class T>
void swap(T a, T b)
{
	T c;
	c = a;
	a = b;
	b = c;
}

template <class T>
T min(T a, T b)
{
	if (a < b)
		return (a);
	return (b);
}

template <class T>
T max(T a, T b)
{
	if (a > b)
		return (a);
	return (b);
}
