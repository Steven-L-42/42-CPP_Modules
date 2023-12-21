/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slippert <slippert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 12:00:53 by slippert          #+#    #+#             */
/*   Updated: 2023/12/18 14:08:52 by slippert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScavTrap.hpp"
#include "../include/FragTrap.hpp"
#include "../include/DiamondTrap.hpp"

int main(void)
{
	DiamondTrap Steven("Steven");

	std::cout << std::endl;

	ScavTrap Enemy("Enemy");

	std::cout << std::endl;

	Steven.attack("Enemy");
	Enemy.takeDamage(30);

	Enemy.attack("Steven");
	Steven.takeDamage(20);

	std::cout << std::endl;
	Steven.beRepaired(5);
	Steven.beRepaired(5);
	Steven.beRepaired(5);
	std::cout << std::endl;
	Steven.guardGate();
	Steven.highFivesGuys();

	std::cout << std::endl;

	Steven.whoAmI();

	std::cout << std::endl;
	return (0);
}
