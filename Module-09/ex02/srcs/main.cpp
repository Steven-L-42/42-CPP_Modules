/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slippert <slippert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 21:01:17 by slippert          #+#    #+#             */
/*   Updated: 2024/01/26 11:07:20 by slippert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error: Example usage ./PmergeMe 3 5 9 7 4." << std::endl;
		return (1);
	}
	try
	{
		std::string input = argv[1];
		PmergeMe pmergeMe;
		// pmergeMe.Calculate(input, false);
	}
	catch (std::exception &e)
	{
		std::cout << e.what();
		return (1);
	}
	return (0);
}
