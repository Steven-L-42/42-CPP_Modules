/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Helper.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slippert <slippert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 14:07:10 by slippert          #+#    #+#             */
/*   Updated: 2024/01/20 15:29:39 by slippert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Helper.hpp"

Helper::Helper()
{}

Helper::Helper(const Helper &ref)
{}

Helper::~Helper()
{}

Helper &Helper::operator=(const Helper &ref)
{
	*this = ref;
	return (*this);
}

Base *Helper::generate(void)
{
	std::srand(static_cast<unsigned int>(std::time(0)));
	int random = std::rand() % 3;
	switch (random)
	{
		case 0:
			return (new A);
		case 1:
			return (new B);
		case 2:
			return (new C);
		default:
			break;
	}
	return NULL;
}

void Helper::identify(Base *p)
{
	if (dynamic_cast<A*>(p) != NULL)
		std::cout << "Identified as A" << std::endl;
	else if (dynamic_cast<B*>(p) != NULL)
		std::cout << "Identified as B" << std::endl;
	else if (dynamic_cast<C*>(p) != NULL)
		std::cout << "Identified as C" << std::endl;
}

void Helper::identify(Base &p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "Identified as A" << std::endl;
	}
	catch (std::exception &e){}
	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "Identified as B" << std::endl;
	}
	catch (std::exception &e){}
	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "Identified as C" << std::endl;
	}
	catch (std::exception &e){}
}
