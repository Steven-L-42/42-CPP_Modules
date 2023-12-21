/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slippert <slippert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 21:34:58 by slippert          #+#    #+#             */
/*   Updated: 2023/12/12 14:35:53 by slippert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Replace.hpp"

int	main(int argc, char **argv)
{
	if (argc != 4)
		return (std::cout << "Error: Need 3 arguments: <filename> <string to replace> <new string>\n", 1);
	Replace replace = Replace(argv + 1);
	if (replace.initReplace())
		return (1);
	return (0);
}
