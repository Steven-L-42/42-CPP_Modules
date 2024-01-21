/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slippert <slippert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 21:01:17 by slippert          #+#    #+#             */
/*   Updated: 2024/01/21 15:14:12 by slippert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/MutantStack.hpp"

int main(void)
{
	std::cout << green << "\nStart Test" << reset << std::endl << std::endl;
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << "SIZE: " << mstack.size() << std::endl;
	std::cout << "TOP: " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "SIZE: " << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	std::cout << "TOP: " << mstack.top() << std::endl;
	std::cout << "SIZE: " << mstack.size() << std::endl;
	mstack.pop();
	std::cout << "SIZE: " << mstack.size() << std::endl;
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator itEnd = mstack.end();
	++it;
	--it;
	while (it != itEnd)
	{
		std::cout << "IT: " << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);

	std::cout << red << "\nEnd Test" << reset << std::endl << std::endl;

	return (0);
}
