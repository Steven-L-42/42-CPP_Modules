/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slippert <slippert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 12:00:53 by slippert          #+#    #+#             */
/*   Updated: 2023/12/15 16:41:23 by slippert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScavTrap.hpp"

int main(void)
{
	ScavTrap Steven("Steven");
	ScavTrap Butterfly("Butterfly");

	std::cout << std::endl;

	Steven.attack("Butterfly");
	Butterfly.takeDamage(5);

	std::cout << std::endl;

	Steven.attack("Butterfly");
	Butterfly.takeDamage(1);

	std::cout << std::endl;

	Steven.attack("Butterfly");
	Butterfly.takeDamage(1);

	Steven.attack("Butterfly");
	Butterfly.takeDamage(200);

	std::cout << std::endl;

	Butterfly.beRepaired(7);

	std::cout << std::endl;

	Steven.attack("Butterfly");
	Butterfly.takeDamage(10);

	std::cout << std::endl;

	Steven.guardGate();
	Butterfly.guardGate();

	std::cout << std::endl;

	std::cout << "-------------------------------------------\n" << std::endl;

	ScavTrap Person("Person");
	ScavTrap Chair("Chair");

	std::cout << std::endl;

	Person.attack("Chair");
	Chair.takeDamage(20);
	Person.attack("Chair");
	Chair.takeDamage(20);
	Person.attack("Chair");
	Chair.takeDamage(20);
	Person.attack("Chair");
	Chair.takeDamage(20);
	Person.attack("Chair");
	Chair.takeDamage(20);
	Person.attack("Chair");
	Chair.takeDamage(20);
	std::cout << std::endl;

	return (0);
}
