/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slippert <slippert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 11:19:32 by slippert          #+#    #+#             */
/*   Updated: 2023/12/20 15:49:40 by slippert         ###   ########.fr       */
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
	//system("leaks brain");
}

int main()
{
	//atexit(leaks);
	std::cout << "\n----------------BASIC----------------\n" << std::endl;

	std::cout << "TEST COPY 1/2" << std::endl;
	Dog basic;
	std::cout << std::endl;
	std::cout << "TEST COPY 2/2" << std::endl;
	Dog tmp = basic;

	int ideas = 2;
	const Animal* dog[ideas];
	const Animal* cat[ideas];

	for (int i = 0; i < ideas; i++)
	{
		std::cout << std::endl;
		dog[i] = new Dog();
		std::cout << std::endl;
		cat[i] = new Cat();
	}

	std::cout << "\n--------------DESTRUCT---------------\n" << std::endl;

	for (int i = 0; i < ideas; i++)
	{
		delete dog[i];
		std::cout << std::endl;
		delete cat[i];
		std::cout << std::endl;
	}

	std::cout << "\n---------------LEAKS-----------------\n" << std::endl;
	return 0;
}