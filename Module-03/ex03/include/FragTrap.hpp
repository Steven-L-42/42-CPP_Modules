/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slippert <slippert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 16:21:54 by slippert          #+#    #+#             */
/*   Updated: 2023/12/18 14:15:51 by slippert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "../include/ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
	private:
		FragTrap();
	public:
		FragTrap(std::string _Name);
		~FragTrap();
		void highFivesGuys(void);
		static const int _hit_points = 100;
		static const int _attack_power = 30;
};
