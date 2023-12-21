/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slippert <slippert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 14:16:55 by slippert          #+#    #+#             */
/*   Updated: 2023/12/20 14:32:42 by slippert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Character.hpp"
#include "../include/ICharacter.hpp"
#include "../include/MateriaSource.hpp"
#include "../include/IMateriaSource.hpp"
#include "../include/Cure.hpp"
#include "../include/Ice.hpp"

void leaks()
{
	//system("leaks interface");
}

int main()
{
	//atexit(leaks);
	IMateriaSource* src = new MateriaSource();


	std::cout << "\n------------DEBUG1------------\n" << std::endl;


	src->learnMateria(new Ice());
	src->learnMateria(new Cure());


	std::cout << "\n------------DEBUG2------------\n" << std::endl;


	ICharacter* me = new Character("me");


	std::cout << "\n------------DEBUG3------------\n" << std::endl;


	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);


	std::cout << "\n------------DEBUG4------------\n" << std::endl;


	ICharacter* bob = new Character("bob");


	std::cout << "\n------------DEBUG5------------\n" << std::endl;


	me->use(0, *bob);
	me->use(1, *bob);


	std::cout << "\n-----------DESTRUCT-----------\n" << std::endl;


	delete bob;
	delete me;
	delete src;


	std::cout << "\n-------------LEAKS------------\n" << std::endl;


	return (0);
}
