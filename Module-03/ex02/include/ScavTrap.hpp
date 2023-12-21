/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slippert <slippert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 12:47:29 by slippert          #+#    #+#             */
/*   Updated: 2023/12/15 16:38:00 by slippert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "../include/ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	private:
		ScavTrap();
	public:
		ScavTrap(std::string _Name);
		~ScavTrap();
		void guardGate();
		void attack(const std::string &target);
};
