/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slippert <slippert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 18:18:56 by slippert          #+#    #+#             */
/*   Updated: 2023/12/02 18:44:53 by slippert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
	else if (argc > 1)
	{
		std::string new_argv[argc - 1];
		for (int i = 1; i < argc; i++)
			new_argv[i - 1] = argv[i];
		for (int i = 0; i < argc - 1; i++)
			std::transform(new_argv[i].begin(), new_argv[i].end(), new_argv[i].begin(), ::toupper);
		for (int i = 0; i < argc - 1; i++)
			std::cout << new_argv[i];
		std::cout << "\n";
	}
	return (0);
}
