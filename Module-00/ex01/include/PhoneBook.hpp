/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slippert <slippert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 18:18:56 by slippert          #+#    #+#             */
/*   Updated: 2023/12/10 14:51:45 by slippert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Contact.hpp"

class PhoneBook
{
	private:
		Contact contact[8];
		int numOfContacts;
		int indexOfOldestContact;
		int indexes;
		void SearchContact();
	public:
		PhoneBook();
		~PhoneBook();
		void ListContacts();
		void AddContact();
		bool isTerminated;
};
