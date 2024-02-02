/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slippert <slippert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 21:01:17 by slippert          #+#    #+#             */
/*   Updated: 2024/02/02 12:48:52 by slippert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"

int main(int argc, char **argv)
{
	if (argc < 2)
		return (1);
	PmergeMe mergeMe;
	try
	{
		mergeMe.FordJohnson(argc, argv);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
