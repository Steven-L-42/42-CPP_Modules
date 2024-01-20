/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slippert <slippert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 21:01:17 by slippert          #+#    #+#             */
/*   Updated: 2024/01/20 18:40:05 by slippert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/easyfind.hpp"

int main(int argc, char **argv)
{
	std::vector<int> list;
	list.push_back(2);
	list.push_back(7);
	list.push_back(5);
	list.push_back(20);

	std::cout << blue << "\nAll list items ";
	for (size_t i = 0; i < list.size(); i++)
		std::cout << list[i] << (i == list.size() - 1 ? "" : ", ");
	std::cout << "." << reset << std::endl;

	std::cout << blue << "\n~Expected 'Found' 5~" << reset << std::endl;
	::easyfind(list, 5);

	std::cout << blue << "\n~Expected 'Not Found' 6~" << reset << std::endl;
	::easyfind(list, 6);

	std::cout << blue << "\n~Expected 'Not Found' 21~" << reset << std::endl;
	::easyfind(list, 21);

	std::cout << blue << "\n~Expected 'Found' 20~" << reset << std::endl;
	::easyfind(list, 20);

	return (0);
}