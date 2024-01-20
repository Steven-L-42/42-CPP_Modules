/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slippert <slippert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 14:06:51 by slippert          #+#    #+#             */
/*   Updated: 2024/01/20 14:22:45 by slippert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Data.hpp"
#include <iostream>

class ConvertHelper;

class Serializer
{
  private:
  public:
	Serializer();
	Serializer(const Serializer &ref);
	Serializer &operator=(const Serializer &ref);
	~Serializer();
	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);
};
