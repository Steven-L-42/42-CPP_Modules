/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slippert <slippert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 14:07:10 by slippert          #+#    #+#             */
/*   Updated: 2024/01/23 18:58:33 by slippert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Serializer.hpp"

Serializer::Serializer()
{
}

// Serializer::Serializer(const Serializer &ref)
// {
// }

// Serializer &Serializer::operator=(const Serializer &ref)
// {
// 	*this = ref;
// 	return (*this);
// }

Serializer::~Serializer()
{
}


// reinterpret_cast ist ein C++-Operator, der dazu verwendet wird,
// einen Zeiger oder eine Referenz von einem Typ in einen anderen umzuwandeln.
uintptr_t Serializer::serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data *Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}
