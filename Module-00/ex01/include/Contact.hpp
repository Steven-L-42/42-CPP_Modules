/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slippert <slippert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 18:18:56 by slippert          #+#    #+#             */
/*   Updated: 2023/12/10 14:53:32 by slippert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __CONTACT_H__
#define __CONTACT_H__
#include <iostream>

// Color
#define GREEN "\033[1;32m"
#define RED "\033[1;31m"
#define ORANGE "\033[1;38;5;208m"
#define BLUE "\033[1;34m"

// Reset Color
#define RESET "\033[0m"

class Contact
{
	private:
	std::string	firstName;
	std::string	lastName;
	std::string	nickname;
	std::string	phoneNumber;
	std::string	darkestSecret;
	std::string TrimWhitespaces(std::string &str);
	bool ContainsOnlySpace(std::string &str);
	std::string parseInput(std::string attribut);
	public:
	Contact();
	~Contact();
	bool Init();
	std::string getData();
	void DisplayRow(int index);
	void DisplayInfo();
	bool isEmpty();
};

#endif