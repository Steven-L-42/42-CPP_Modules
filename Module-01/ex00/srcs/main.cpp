/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slippert <slippert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 18:23:44 by slippert          #+#    #+#             */
/*   Updated: 2023/12/12 14:13:57 by slippert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Zombie.hpp"

int	main()
{
	Zombie *test = newZombie("Brunhilde");
	test->announce();
	randomChump("Bruno");
	delete(test);
	return (0);
}
