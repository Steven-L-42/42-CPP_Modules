/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slippert <slippert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 20:31:54 by slippert          #+#    #+#             */
/*   Updated: 2023/12/03 21:23:34 by slippert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __HUMANA_H__
#define __HUMANA_H__

#include "Weapon.hpp"

class HumanA
{
	private:
	Weapon &_weapon;
	std::string name;
	public:
	HumanA(std::string name, Weapon &weapon);
	~HumanA();
	void attack(void);
};

#endif