/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slippert <slippert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 19:38:50 by slippert          #+#    #+#             */
/*   Updated: 2023/12/03 20:29:26 by slippert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main()
{
	std::string original = "HI THIS IS BRAIN";

	std::string* stringPTR = &original;
	std::string& stringREF = original;

	// Get the Address
	std::cout << "Address stringORG:\t" << &original << std::endl;
	std::cout << "Address stringPTR:\t" << stringPTR << std::endl;
	std::cout << "Address stringREF:\t" << &stringREF << std::endl << std::endl;

	// Get the Value
	std::cout << "Text stringORG:\t\t" << original << std::endl;
	std::cout << "Text stringPTR:\t\t" << *stringPTR << std::endl;
	std::cout << "Text stringREF:\t\t" << stringREF << std::endl;

	return (0);
}
