/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slippert <slippert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 16:21:54 by slippert          #+#    #+#             */
/*   Updated: 2023/12/15 16:27:49 by slippert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "../include/ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	private:
		FragTrap();
	public:
		FragTrap(std::string _Name);
		~FragTrap();
		void highFivesGuys(void);
};
