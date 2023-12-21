/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slippert <slippert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 11:19:30 by slippert          #+#    #+#             */
/*   Updated: 2023/12/19 13:20:55 by slippert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Brain.hpp"

Brain::Brain()
{
	std::cout
	<< "Brain constructor is called"
	<< std::endl;
}

Brain::~Brain()
{
	std::cout
	<< "Brain destructor is called"
	<< std::endl;
}

Brain::Brain(const Brain &other)
{
	std::cout
	<< "Brain copy constructor is called"
	<< std::endl;
	*this = other;
}

Brain& Brain::operator=(const Brain &other)
{
	std::cout
	<< "Brain copy operator is called"
	<< std::endl;
	for (int i = 0; i < 100; i++)
	{
		this->ideas[i] = other.ideas[i];
	}
	return *this;
}
