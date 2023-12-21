/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slippert <slippert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 18:18:56 by slippert          #+#    #+#             */
/*   Updated: 2023/12/10 15:04:11 by slippert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PhoneBook.hpp"
#include "../include/Contact.hpp"

PhoneBook::PhoneBook()
{
	numOfContacts = 0;
	indexOfOldestContact = 0;
	isTerminated = false;
}

PhoneBook::~PhoneBook() {}

void	PhoneBook::ListContacts()
{
	if (numOfContacts == 0)
	{
		std::cout << RED << "\n\nOh it seems you have no contacts :(\n\n" << RESET;
		return ;
	}
	std::cout << BLUE << "\n\nINDEX     |FIRST NAME|LAST NAME |NICKNAME  \n" << RESET;
	for (int i = 0; i < 8 && !contact[i].isEmpty(); i++)
		contact[i].DisplayRow(i);
	SearchContact();
}

// iomanips (iostream) : The << and >> operators are also used for stream manipulators in C++.
void	PhoneBook::SearchContact()
{
	std::string input;
	int number;

	std::cout << ORANGE << "\n\nEnter a index number (0 - " << numOfContacts - 1 << "):\n" << RESET;
	while (1)
	{
		std::cin >> input;
		try
		{
			if (std::cin.eof())
				return ;
			number = std::stoi(input);
			if (number >= 0 && number < numOfContacts)
				break;
			else
				std::cout << RED << "Your input wasn't correct - Retry (0 - " << numOfContacts - 1 << "):" << RESET << std::endl;
		}
		catch (const std::invalid_argument& e)
		{
			std::cerr << RED << "Invalid argument: " << e.what() << RESET << std::endl;
		}
		catch (const std::out_of_range& e)
		{
			std::cerr  << RED << "Out of range: " << e.what() << RESET << std::endl;
		}
		input.clear();
	}
	contact[number].DisplayInfo();
}

void	PhoneBook::AddContact()
{
	if (numOfContacts == 8)
	{
		indexOfOldestContact %= 8;
		this->isTerminated = contact[indexOfOldestContact].Init();
		if (this->isTerminated)
			return ;
		std::cout << GREEN << "\nContact '" << contact[indexOfOldestContact++].getData() << "' saved.\n\n";
	}
	else
	{
		this->isTerminated = contact[numOfContacts].Init();
		if (this->isTerminated)
			return ;
		std::cout << GREEN << "\nContact '" << contact[numOfContacts++].getData() << "' saved.\n\n";
	}
}
