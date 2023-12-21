/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slippert <slippert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 10:23:10 by slippert          #+#    #+#             */
/*   Updated: 2023/12/04 16:55:58 by slippert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Harl.hpp"

int	main()
{
	Harl harl;
	std::string input;
	do
	{
		std::cout << "Enter a Level: ";
		std::cin >> input;
		harl.complain(input);
	}
	while (input.compare("EXIT"));
	return (0);
}
