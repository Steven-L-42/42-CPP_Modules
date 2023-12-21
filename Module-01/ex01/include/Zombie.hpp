/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slippert <slippert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 19:37:07 by slippert          #+#    #+#             */
/*   Updated: 2023/12/04 16:35:45 by slippert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __ZOMBIE_H__
#define __ZOMBIE_H__

#include <iostream>

class Zombie
{
	private:
	std::string name;
	public:
	Zombie(void);
	~Zombie(void);
	void announce(void);
	void setName(std::string name);
};

Zombie* newZombie(std::string name);
Zombie* zombieHorde(int N, std::string name);
#endif