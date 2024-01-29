/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slippert <slippert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 11:19:32 by slippert          #+#    #+#             */
/*   Updated: 2024/01/29 12:43:39 by slippert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Brain.hpp"

#include "../include/WrongAnimal.hpp"
#include "../include/WrongCat.hpp"

#include "../include/Animal.hpp"
#include "../include/Cat.hpp"
#include "../include/Dog.hpp"

void leaks()
{
	//system("leaks abstract");
}

int main()
{
	//atexit(leaks);

	std::cout << std::endl;
	std::cout << "----------------BASIC----------------" << std::endl;
	std::cout << std::endl;

	// std::cout << "TEST COPY 1/2" << std::endl;
	// Dog basic;
	// std::cout << std::endl;
	// std::cout << "TEST COPY 2/2" << std::endl;
	// Dog tmp = basic;

	int ideas = 50;
	const Animal* dog[ideas];
	const Animal* cat[ideas];

	for (int i = 0; i < ideas; i++)
	{
		std::cout << std::endl;
		dog[i] = new Dog();
		std::cout << std::endl;
		cat[i] = new Cat();
	}

	std::cout << std::endl;
	std::cout << "--------------DESTRUCT---------------" << std::endl;
	std::cout << std::endl;

	for (int i = 0; i < ideas; i++)
	{
		delete dog[i];
		std::cout << std::endl;
		delete cat[i];
		std::cout << std::endl;
	}
	return 0;
}