/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slippert <slippert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 11:19:32 by slippert          #+#    #+#             */
/*   Updated: 2023/12/20 15:16:10 by slippert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/WrongAnimal.hpp"
#include "../include/WrongCat.hpp"

#include "../include/Animal.hpp"
#include "../include/Cat.hpp"
#include "../include/Dog.hpp"

void leaks()
{
	//system("leaks poly");
}

int main()
{
	//atexit(leaks);
	std::cout << "\n----------------BASIC----------------\n" << std::endl;

	const Animal* no_type = new Animal();
	std::cout << std::endl;

	const Animal* dog = new Dog();
	std::cout << std::endl;

	const Animal* cat = new Cat();


	std::cout << std::endl;

	std::cout << no_type->getType() << " = type" << std::endl;
	std::cout << dog->getType() << " = type" << std::endl;
	std::cout << cat->getType() << " = type" << std::endl;

	std::cout << std::endl;

	no_type->makeSound();
	cat->makeSound();
	dog->makeSound();

	std::cout << "\n----------------WRONG----------------\n" << std::endl;

	const WrongAnimal* wrong_cat = new WrongCat();
	std::cout << std::endl;

	wrong_cat->makeSound();

	std::cout << "\n--------------DESTRUCT---------------\n" << std::endl;

	delete(no_type);
	std::cout << std::endl;

	delete(cat);
	std::cout << std::endl;

	delete(dog);
	std::cout << std::endl;

	delete(wrong_cat);

	std::cout << "\n-----------------END-----------------\n" << std::endl;

	return (0);
}