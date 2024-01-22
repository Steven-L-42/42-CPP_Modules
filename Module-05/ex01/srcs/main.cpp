/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slippert <slippert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 16:08:00 by slippert          #+#    #+#             */
/*   Updated: 2024/01/22 12:51:24 by slippert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/Form.hpp"

int main(void)
{
	std::cout << blue << "\n--- Start Form Sign Tests ---" << reset << std::endl;
	// Succes Tests
	try
	{
		std::cout << green << "\nForm 1, Bureaucrat 1: Expected = to success" << reset << std::endl;
		Form Test("TestForm", 1, 1);
		Bureaucrat Steven("Steven", 1);
		std::cout << Steven << std::endl;
		std::cout << Test << std::endl;
		Steven.signForm(Test);
		std::cout << Test << std::endl;
		Steven.signForm(Test);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << green << "\nForm 150, Bureaucrat 150: Expected = to success" << reset << std::endl;
		Form Test("TestForm", 150, 1);
		Bureaucrat Steven("Steven", 150);
		std::cout << Steven << std::endl;
		std::cout << Test << std::endl;
		Steven.signForm(Test);
		std::cout << Test << std::endl;
		Steven.signForm(Test);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << green << "\nForm 130, Bureaucrat 75: Expected = to success" << reset << std::endl;
		Form Test("TestForm", 130, 1);
		Bureaucrat Steven("Steven", 75);
		std::cout << Steven << std::endl;
		std::cout << Test << std::endl;
		Steven.signForm(Test);
		std::cout << Test << std::endl;
		Steven.signForm(Test);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << green << "\nForm 50, Bureaucrat 1: Expected = to success" << reset << std::endl;
		Form Test("TestForm", 50, 1);
		Bureaucrat Steven("Steven", 1);
		std::cout << Steven << std::endl;
		std::cout << Test << std::endl;
		Steven.signForm(Test);
		std::cout << Test << std::endl;
		Steven.signForm(Test);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	// Fail Tests
	try
	{
		std::cout << red << "\nForm 50, Bureaucrat 51: Expected = to low" << reset << std::endl;
		Form Test("TestForm", 50, 1);
		Bureaucrat Steven("Steven", 51);
		std::cout << Steven << std::endl;
		std::cout << Test << std::endl;
		Steven.signForm(Test);
		std::cout << Test << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << red << "\nForm 1, Bureaucrat 51: Expected = to low" << reset << std::endl;
		Form Test("TestForm", 1, 1);
		Bureaucrat Steven("Steven", 51);
		std::cout << Steven << std::endl;
		std::cout << Test << std::endl;
		Steven.signForm(Test);
		std::cout << Test << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << red << "\nForm 1, Bureaucrat 2: Expected = to low" << reset << std::endl;
		Form Test("TestForm", 1, 1);
		Bureaucrat Steven("Steven", 2);
		std::cout << Steven << std::endl;
		std::cout << Test << std::endl;
		Steven.signForm(Test);
		std::cout << Test << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << red << "\nForm 149, Bureaucrat 150: Expected = to low" << reset << std::endl;
		Form Test("TestForm", 149, 1);
		Bureaucrat Steven("Steven", 150);
		std::cout << Steven << std::endl;
		std::cout << Test << std::endl;
		Steven.signForm(Test);
		std::cout << Test << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
