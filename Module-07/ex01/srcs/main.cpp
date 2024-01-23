/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slippert <slippert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 21:01:17 by slippert          #+#    #+#             */
/*   Updated: 2024/01/23 18:48:17 by slippert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/iter.hpp"
#include <iostream>

template <class T>
void myFunction(T &test)
{
	test += 5;
}

int main(void)
{
	std::cout << std::endl;

	int arr[] = {0, 42, 100};
	size_t arr_len = sizeof(arr) / sizeof(arr[0]);

 	::iter(arr, arr_len, myFunction<int>);

	for (size_t i = 0; i < arr_len; i++)
	{
		std::cout << arr[i]  << " ";
	}

	std::cout << std::endl << std::endl;

	char arr_char[] = {'a', 'b', 'c'};
	arr_len = sizeof(arr_char) / sizeof(arr_char[0]);

 	::iter(arr_char, arr_len, myFunction<char>);

	for (size_t i = 0; i < arr_len; i++)
	{
		std::cout << arr_char[i]  << " ";
	}

	std::cout << std::endl << std::endl;
	return (0);
}
