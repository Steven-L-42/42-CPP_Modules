/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slippert <slippert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 16:21:54 by slippert          #+#    #+#             */
/*   Updated: 2023/12/18 14:05:23 by slippert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "../include/FragTrap.hpp"
#include "../include/ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
	private:
		std::string name;
		DiamondTrap();
	public:
		DiamondTrap(std::string _Name);
		~DiamondTrap();
		using ScavTrap::attack;
		void whoAmI();
};
