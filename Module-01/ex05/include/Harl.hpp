/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slippert <slippert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 10:23:35 by slippert          #+#    #+#             */
/*   Updated: 2023/12/04 17:12:04 by slippert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __HARL_H__
#define __HARL_H__

#include <iostream>
#include <unordered_map>

class Harl
{
	private:
	void debug( void );
	void info( void );
	void warning( void );
	void error( void );
	void defaultAction( void );
	public:
	Harl();
	~Harl();
	void complain(std::string level);
};

typedef void (Harl::*t_functions)(void);
#endif
