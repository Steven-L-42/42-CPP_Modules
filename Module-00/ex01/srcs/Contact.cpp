/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slippert <slippert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 18:18:56 by slippert          #+#    #+#             */
/*   Updated: 2023/12/10 15:14:29 by slippert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Contact.hpp"

Contact::Contact() {}

Contact::~Contact() {}

// return true on exiting the parsing with EOF
bool Contact::Init()
{
	std::string temp;
	std::cout << ORANGE << "\n\nTo save a new contact, you have to fill all fields!\n" << RESET;

	temp = parseInput("First Name:");
	if (temp.empty())
		return (true);
	this->firstName = temp;
	temp = parseInput("Last Name:");
	if (temp.empty())
		return (true);
	this->lastName = temp;
	temp = parseInput("Nickname:");
	if (temp.empty())
		return (true);
	this->nickname = temp;
	temp = parseInput("Phone Number:");
	if (temp.empty())
		return (true);
	this->phoneNumber = temp;
	temp = parseInput("Darkest Secret:");
	if (temp.empty())
		return (true);
	this->darkestSecret = temp;

	return (false);
}

std::string Contact::getData()
{
	return (this->firstName);
}

void Contact::DisplayRow(int index)
{
	for (int j = std::to_string(index).length(); j < 10; j++)
		std::cout << " ";
		std::cout << index << "|";
	for (int j = this->firstName.length(); j < 10; j++)
		std::cout << " ";
	std::cout << this->firstName.substr(0, 10) << "|";
	for (int j = this->lastName.length(); j < 10; j++)
		std::cout << " ";
	std::cout << this->lastName.substr(0, 10) << "|";
	for (int j = this->nickname.length(); j < 10; j++)
		std::cout << " ";
	std::cout << this->nickname.substr(0, 10) << std::endl;
}

void	Contact::DisplayInfo()
{
	std::cout << GREEN << "\n\n" << "~~~Contact~~~" << RESET << std::endl;
	std::cout << BLUE << "First Name: " << RESET << this->firstName << std::endl;
	std::cout << BLUE << "Last Name: " << RESET << this->lastName << std::endl;
	std::cout << BLUE << "Nickname: " << RESET << this->nickname << std::endl;
	std::cout << BLUE << "Phone Number: " << RESET << this->phoneNumber << std::endl;
	std::cout << BLUE << "Darkest Secret: " << RESET << this->darkestSecret << "\n" << std::endl;
}

bool Contact::isEmpty()
{
	if (this->firstName.empty())
		return (true);
	return (false);
}

bool Contact::ContainsOnlySpace(std::string &str)
{
	for (size_t i = 0; i < str.length(); i++)
		if (!std::isspace(static_cast<unsigned char>(str[i])))
			return false;
	return true;
}

std::string Contact::TrimWhitespaces(std::string &str)
{
	std::string result = str;
	size_t start = result.find_first_not_of(" \t\n\r");
	if (start != std::string::npos)
		result = result.substr(start);
	else
		result = "";

	size_t end = result.find_last_not_of(" \t\n\r");
	if (end != std::string::npos)
		result = result.substr(0, end + 1);
	else
		result = "";

	return (result);
}

std::string Contact::parseInput(std::string attribut)
{
	std::string line;
	std::cout << BLUE << attribut << "\n" << RESET;
	while (1)
	{
		std::getline(std::cin, line);
		if (std::cin.eof())
			return std::string();
		if (!ContainsOnlySpace(line))
			return (TrimWhitespaces(line));
	}
	return (line);
}
