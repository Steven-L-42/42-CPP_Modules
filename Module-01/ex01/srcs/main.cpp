/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slippert <slippert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 19:38:50 by slippert          #+#    #+#             */
/*   Updated: 2023/12/10 16:36:07 by slippert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Zombie.hpp"

int	main()
{
	Zombie *horde;

	int hordeSize = 5;
	horde = zombieHorde(hordeSize, "Zombie ");
	if (!horde)
		return (1);
	for (size_t i = 0; i < hordeSize; i++)
		horde[i].announce();
	delete[](horde);
	horde = zombieHorde(0, "Zombie Frank");
	return (0);
}
