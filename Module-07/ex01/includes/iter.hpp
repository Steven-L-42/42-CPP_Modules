/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slippert <slippert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 16:26:17 by slippert          #+#    #+#             */
/*   Updated: 2024/01/20 17:36:20 by slippert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template <class A, class L, class F>
void iter(A* arr, L length, F func)
{
	for (L i = 0; i < length; i++) {
		func(arr[i]);
	}
}
