/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slippert <slippert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 11:19:28 by slippert          #+#    #+#             */
/*   Updated: 2023/12/20 15:51:54 by slippert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Animal
{
	protected:
		std::string type;
		Animal();
	public:
		virtual ~Animal();
		Animal(std::string _type);
		Animal(const Animal &other);
		Animal& operator=(const Animal &other);

		std::string getType() const;
		void setType(std::string &type);
		virtual void makeSound() const = 0;
};
