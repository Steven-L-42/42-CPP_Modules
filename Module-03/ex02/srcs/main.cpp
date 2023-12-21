/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slippert <slippert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 12:00:53 by slippert          #+#    #+#             */
/*   Updated: 2023/12/18 13:17:48 by slippert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScavTrap.hpp"
#include "../include/FragTrap.hpp"

int main(void)
{
	ScavTrap Steven("Steven");

	std::cout << std::endl;

	FragTrap SuperStrong("SuperStrong");

	std::cout << std::endl;

	SuperStrong.attack("Steven");
	Steven.takeDamage(30);
	SuperStrong.highFivesGuys();

	std::cout << std::endl;

	Steven.attack("SuperStrong");
	SuperStrong.takeDamage(20);

	std::cout << std::endl;
	return (0);
}
