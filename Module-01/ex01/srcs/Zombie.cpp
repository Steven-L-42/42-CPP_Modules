/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slippert <slippert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 19:37:11 by slippert          #+#    #+#             */
/*   Updated: 2023/12/03 21:32:29 by slippert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Zombie.hpp"

Zombie::Zombie(void)
{
}

Zombie::~Zombie(void)
{
	std::cout
	<< name
	<< ": destroyed!"
	<< std::endl;
}

void Zombie::announce(void)
{
	std::cout
	<< name
	<< ": BraiiiiiiinnnzzzZ..."
	<< std::endl;
}

void Zombie::setName(std::string name)
{
	this->name = name;
	std::cout
	<< name
	<< ": created!"
	<< std::endl;
}
