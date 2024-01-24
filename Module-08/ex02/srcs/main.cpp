/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slippert <slippert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 21:01:17 by slippert          #+#    #+#             */
/*   Updated: 2024/01/24 17:41:11 by slippert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/MutantStack.hpp"

int main(void)
{
	{
		std::cout << green << "\nTest Subject\n" << reset << std::endl;
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

		std::cout << red << "\nEnd Test\n" << reset << std::endl;
	}

	{
		std::cout << green << "\nTest Mooooore\n"  << reset << std::endl;
		MutantStack<int> mstack;
		std::cout << "SIZE: " << mstack.size() << std::endl;
		mstack.push(5);
		std::cout << "SIZE: " << mstack.size() << std::endl;
		std::cout << "TOP: " << mstack.top() << std::endl << std::endl;
		mstack.push(17);
		mstack.push(0);
		mstack.push(24);
		mstack.push(234);
		mstack.push(785);
		std::cout << "SIZE: " << mstack.size() << std::endl;
		std::cout << "TOP: " << mstack.top() << std::endl << std::endl;
		mstack.pop();
		std::cout << "SIZE: " << mstack.size() << std::endl;
		std::cout << "TOP: " << mstack.top() << std::endl << std::endl;
		mstack.push(42);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator itEnd = mstack.end();
		it--;
		while (++it != itEnd)
			std::cout << "IT: " << *it << std::endl;
		std::stack<int> s(mstack);

		std::cout << red << "\nEnd Test\n"
				  << reset << std::endl;
	}

	return (0);
}
