/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slippert <slippert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 21:01:17 by slippert          #+#    #+#             */
/*   Updated: 2024/01/25 20:50:06 by slippert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RPN.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error: Example usage ./RPN \"8 9 * 9 - 9 - 9 - 4 - 1 +\"." << std::endl;
		return (1);
	}
	try
	{
		std::string input = argv[1];
		RPN rpn;
		rpn.Calculate(input, false);
	}
	catch (std::exception &e)
	{
		std::cout << e.what();
		return (1);
	}
	return (0);
}
