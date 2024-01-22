/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slippert <slippert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 16:08:00 by slippert          #+#    #+#             */
/*   Updated: 2024/01/22 13:24:23 by slippert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AForm.hpp"
#include "../includes/Bureaucrat.hpp"
#include "../includes/Intern.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"

int	main(void)
{
	Intern	someRandomIntern;
	AForm	*forms[3];

	std::cout << green << "\nTEST START : Robotomy\n" << reset << std::endl;
	try
	{
		forms[0] = someRandomIntern.makeForm("robotomy requestion", "Bender_Robo");
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		forms[0] = someRandomIntern.makeForm("robotomy request", "Bender_Robo");
		Bureaucrat Steven("Steven", 1);
		try
		{
			forms[0]->execute(Steven);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		try
		{
			forms[0]->beSigned(Steven);
			forms[0]->execute(Steven);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << red << "\nTEST END : Robotomy\n" << reset << std::endl;
	std::cout << "-------------------------------------------" << std::endl;
	std::cout << green << "\nTEST START : Shrubbery\n" << reset << std::endl;
	try
	{
		forms[0] = someRandomIntern.makeForm("shrubbery requestion", "Bender_Shrub");
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		forms[1] = someRandomIntern.makeForm("shrubbery request", "Bender_Shrub");
		Bureaucrat Steven("Steven", 75);
		try
		{
			forms[1]->execute(Steven);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		try
		{
			forms[1]->beSigned(Steven);
			forms[1]->execute(Steven);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << red << "\nTEST END : Shrubbery\n" << reset << std::endl;
	std::cout << "-------------------------------------------" << std::endl;
	std::cout << green << "\nTEST START : Presidential\n" << reset << std::endl;
	try
	{
		forms[0] = someRandomIntern.makeForm("presidential requestion", "Bender_Pres");
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		forms[2] = someRandomIntern.makeForm("presidential request", "Bender_Pres");
		Bureaucrat Steven("Steven", 3);
		try
		{
			forms[2]->execute(Steven);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		try
		{
			forms[2]->beSigned(Steven);
			forms[2]->execute(Steven);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << red << "\nTEST END : Presidential\n" << reset << std::endl;
	return (0);
}
