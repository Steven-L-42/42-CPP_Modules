/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slippert <slippert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 17:05:33 by slippert          #+#    #+#             */
/*   Updated: 2024/01/24 14:38:10 by slippert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Array.hpp"

#define MAX_VAL 10

// void ft_leaks(void)
// {
// 	system("leaks template");
// }

int main(void)
{
	// atexit(ft_leaks);

	Array<int> numbers(MAX_VAL);
	int *mirror = new int[MAX_VAL];
	srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}

	std::cout << "\nDisplay original numbers:" << std::endl;
	for (size_t i = 0; i < numbers.size(); i++)
		std::cout << numbers[i] << std::endl;
	std::cout << std::endl;

	// SCOPE
	{
		// Copy constructor
		Array<int> copy;
		copy = numbers;

		std::cout << "Display copy test:" << std::endl;
		for (size_t i = 0; i < copy.size(); i++)
			std::cout << copy[i] << std::endl;
		std::cout << std::endl;

		// assigment constructor
		Array<int> tmp = numbers;

		std::cout << "Display assign tmp:" << std::endl;
		for (size_t i = 0; i < tmp.size(); i++)
			std::cout << tmp[i] << std::endl;
		std::cout << std::endl;

		// assigment constructor
		Array<int> copy_ref(tmp);

		std::cout << "Display ref copy test:" << std::endl;
		for (size_t i = 0; i < copy_ref.size(); i++)
			std::cout << copy_ref[i] << std::endl;
		std::cout << std::endl;
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << "didn't save the same value!!" << std::endl;
			return 1;
		}
	}

	try
	{
		numbers[-2] = 0;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		numbers[MAX_VAL] = 0;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	for (int i = 0; i < MAX_VAL; i++)
		numbers[i] = rand();

	std::cout << "\nDisplay new numbers:" << std::endl;
	for (size_t i = 0; i < numbers.size(); i++)
		std::cout << numbers[i] << std::endl;
	std::cout << std::endl;

	delete[] mirror;
	return (0);
}
