/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slippert <slippert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 19:37:12 by slippert          #+#    #+#             */
/*   Updated: 2023/12/12 14:17:35 by slippert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	if (N < 1)
	{
		std::cout
		<< "Horde needs min. 1 Zombie!"
		<< std::endl;
		return (nullptr);
	}
	Zombie* horde = new Zombie[N];
	if (!horde)
	{
		std::cout
		<< "Horde allocation failed!"
		<< std::endl;
		return (nullptr);
	}
	for (size_t i = 0; i < N; i++)
		horde[i].setName(name + std::to_string(i));
	return (horde);
}
