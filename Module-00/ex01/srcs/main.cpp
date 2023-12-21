/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slippert <slippert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:19:23 by slippert          #+#    #+#             */
/*   Updated: 2023/12/10 15:04:47 by slippert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PhoneBook.hpp"

int	main(void)
{
	PhoneBook phoneBook;
	std::string cmd;

	std::cout << BLUE << "\n<< Welcome this is your awesome phone >>\n" << RESET << std::endl;
	while (1)
	{
		if (!phoneBook.isTerminated)
			std::cout << ORANGE << "\nPlease enter your command:" << RESET << std::endl;
		std::cin >> cmd;
		if (cmd.empty())
		{
			std::cout << RED << "Phone has been terminated!" << RESET << std::endl;
			return (1);
		}
		else if (cmd == "ADD")
			phoneBook.AddContact();
		else if (cmd == "SEARCH")
			phoneBook.ListContacts();
		else if (cmd == "EXIT")
			break ;
		cmd.clear();
	}
	return (0);
}
