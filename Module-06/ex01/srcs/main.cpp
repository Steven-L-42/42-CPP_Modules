/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slippert <slippert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 21:01:17 by slippert          #+#    #+#             */
/*   Updated: 2024/01/20 14:53:09 by slippert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Serializer.hpp"
#include "../includes/Data.hpp"

#define red "\033[1;31m"
#define green "\033[1;32m"
#define reset "\033[0m"

int main(int argc, char **argv)
{
	{
		std::cout << green << "\nSTART TEST #1" << reset << std::endl;
		Serializer serial;
		Data data("String Test #1");

		uintptr_t Serialized = serial.serialize(&data);

		std::cout << "Original Address: " << &data << " | Original String: " << data.notify << std::endl << std::endl;
		std::cout << "Serialized Address: 0x" << std::hex << Serialized << std::endl << std::endl;

		Data *Deserialized = serial.deserialize(Serialized);

		std::cout << "Deserialized Address: " << Deserialized << " | Deserialized String: " << Deserialized->notify << std::endl;
		std::cout << red << "END TEST #1" << reset << std::endl << std::endl;
	}
	return (0);
}