/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slippert <slippert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 10:23:10 by slippert          #+#    #+#             */
/*   Updated: 2023/12/04 10:59:23 by slippert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Harl.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (1);
	Harl harl;
	harl.complain(argv[1]);
	return (0);
}
