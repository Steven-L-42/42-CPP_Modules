/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slippert <slippert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 21:01:17 by slippert          #+#    #+#             */
/*   Updated: 2024/01/20 15:33:21 by slippert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Helper.hpp"

#define red "\033[1;31m"
#define green "\033[1;32m"
#define reset "\033[0m"

// void ft_leaks()
// {
// 	system ("leaks realtype");
// }

int main(void)
{
	// atexit(ft_leaks);
	{
		std::cout << green << "\nSTART TEST" << reset << std::endl;
		Helper help;
		Base *test = help.generate();
		std::cout << "\nTest with Pointer" << std::endl;
		help.identify(test);
		std::cout << "\nTest with Referenz" << std::endl;
		help.identify(*test);
		std::cout << red << "\nEND TEST" << reset << std::endl << std::endl;
		delete (test);
	}
	return (0);
}