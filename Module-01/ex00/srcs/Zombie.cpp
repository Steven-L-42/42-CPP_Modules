/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slippert <slippert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 18:29:45 by slippert          #+#    #+#             */
/*   Updated: 2023/12/10 16:33:05 by slippert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Zombie.hpp"

Zombie::Zombie(std::string name)
{
	this->name = name;
	std::cout
	<< this->name
	<< ": created!"
	<< std::endl;
}

Zombie::~Zombie(void)
{
	std::cout
	<< this->name
	<< ": destroyed!"
	<< std::endl;
}

void Zombie::announce(void)
{
	std::cout
	<< name
	<< ": BraiiiiiiinnnzzzZ!"
	<< std::endl;
}
