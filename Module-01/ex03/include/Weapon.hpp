/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slippert <slippert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 20:31:54 by slippert          #+#    #+#             */
/*   Updated: 2023/12/03 21:27:07 by slippert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __WEAPON_H__
#define __WEAPON_H__

#include <iostream>

class Weapon
{
	private:
	std::string type;
	public:
	Weapon(std::string type);
	~Weapon();
	const std::string getType();
	void setType(std::string type);
};

#endif