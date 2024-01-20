/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slippert <slippert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 21:02:05 by slippert          #+#    #+#             */
/*   Updated: 2024/01/20 18:39:22 by slippert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <vector>

#define blue "\033[1;34m"
#define red "\033[1;31m"
#define green "\033[1;32m"
#define reset "\033[0m"

template <class T>
void easyfind(T arr, int searched)
{
	size_t arrSize = sizeof(arr) / sizeof(arr[0]);
	for (size_t i = 0; i < arrSize; i++)
	{
		if (arr[i] == searched)
		{
			std::cout << green << "Element found in container." << reset << std::endl;
			return ;
		}
	}
	std::cout << red << "Element not found in container." << reset << std::endl;
}
