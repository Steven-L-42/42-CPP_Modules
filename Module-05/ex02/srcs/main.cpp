/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slippert <slippert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 16:08:00 by slippert          #+#    #+#             */
/*   Updated: 2024/01/15 13:53:00 by slippert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"

#define red "\033[1;31m"
#define green "\033[1;32m"
#define reset "\033[0m"

int	main(void)
{
	{
		std::cout << green << "\nTEST START : ShrubberyCreationForm" << reset << std::endl;
		try
		{
			ShrubberyCreationForm shrubberForm("ShrubberForm");
			std::cout << "\nIs NOT Signed before Execute\n" << std::endl;
			Bureaucrat Steven("Steven", 138);
			std::cout << Steven << std::endl;
			std::cout << shrubberForm << std::endl;
			Steven.executeForm(shrubberForm);
			Steven.signForm(shrubberForm);
			std::cout << shrubberForm << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		std::cout << std::endl;
		try
		{
			ShrubberyCreationForm shrubberForm("ShrubberForm");
			std::cout << "\nCan Sign but NOT Execute\n" << std::endl;
			Bureaucrat Steven("Steven", 138);
			std::cout << Steven << std::endl;
			std::cout << shrubberForm << std::endl;
			Steven.signForm(shrubberForm);
			std::cout << shrubberForm << std::endl;
			Steven.executeForm(shrubberForm);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		std::cout << std::endl;
		try
		{
			ShrubberyCreationForm shrubberForm("ShrubberForm");
			std::cout << "\nCan Sign & Execute\n" << std::endl;
			Bureaucrat Steven("Steven", 137);
			std::cout << Steven << std::endl;
			std::cout << shrubberForm << std::endl;
			Steven.executeForm(shrubberForm);
			Steven.signForm(shrubberForm);
			std::cout << shrubberForm << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		std::cout << std::endl;
		try
		{
			ShrubberyCreationForm shrubberForm("ShrubberForm");
			std::cout << "\nCan NOT Sign & NOT Execute\n" << std::endl;
			Bureaucrat Steven("Steven", 150);
			std::cout << Steven << std::endl;
			std::cout << shrubberForm << std::endl;
			Steven.signForm(shrubberForm);
			std::cout << shrubberForm << std::endl;
			Steven.executeForm(shrubberForm);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		std::cout << red << "\nTEST END : ShrubberyCreationForm\n" << reset << std::endl;
	}
	std::cout << "-------------------------------------------" << std::endl;
	{
		std::cout << green << "\nTEST START : RobotomyRequestForm" << reset << std::endl;
		try
		{
			RobotomyRequestForm robotForm("RobotForm");
			std::cout << "\nIs NOT Signed before Execute\n" << std::endl;
			Bureaucrat Steven("Steven", 138);
			std::cout << Steven << std::endl;
			std::cout << robotForm << std::endl;
			Steven.executeForm(robotForm);
			Steven.signForm(robotForm);
			std::cout << robotForm << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		std::cout << std::endl;
		try
		{
			RobotomyRequestForm robotForm("RobotForm");
			std::cout << "\nCan Sign but NOT Execute\n" << std::endl;
			Bureaucrat Steven("Steven", 50);
			std::cout << Steven << std::endl;
			std::cout << robotForm << std::endl;
			Steven.signForm(robotForm);
			std::cout << robotForm << std::endl;
			Steven.executeForm(robotForm);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		std::cout << std::endl;
		try
		{
			RobotomyRequestForm robotForm("RobotForm");
			std::cout << "\nCan Sign & Execute\n" << std::endl;
			Bureaucrat Steven("Steven", 30);
			std::cout << Steven << std::endl;
			std::cout << robotForm << std::endl;
			Steven.signForm(robotForm);
			std::cout << robotForm << std::endl;
			Steven.executeForm(robotForm);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		std::cout << std::endl;
		try
		{
			RobotomyRequestForm robotForm("RobotForm");
			std::cout << "\nCan NOT Sign & NOT Execute\n" << std::endl;
			Bureaucrat Steven("Steven", 80);
			std::cout << Steven << std::endl;
			std::cout << robotForm << std::endl;
			Steven.signForm(robotForm);
			std::cout << robotForm << std::endl;
			Steven.executeForm(robotForm);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		std::cout << red << "\nTEST END : RobotomyRequestForm\n" << reset << std::endl;
	}
	std::cout << "-------------------------------------------" << std::endl;
	{
		std::cout << green << "\nTEST START : PresidentialPardonForm" << reset << std::endl;
		try
		{
			PresidentialPardonForm pardonForm("PardonForm");
			std::cout << "\nIs NOT Signed before Execute\n" << std::endl;
			Bureaucrat Steven("Steven", 138);
			std::cout << Steven << std::endl;
			std::cout << pardonForm << std::endl;
			Steven.executeForm(pardonForm);
			Steven.signForm(pardonForm);
			std::cout << pardonForm << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		std::cout << std::endl;
		try
		{
			PresidentialPardonForm pardonForm("PardonForm");
			std::cout << "\nCan Sign but NOT Execute\n" << std::endl;
			Bureaucrat Steven("Steven", 20);
			std::cout << Steven << std::endl;
			std::cout << pardonForm << std::endl;
			Steven.signForm(pardonForm);
			std::cout << pardonForm << std::endl;
			Steven.executeForm(pardonForm);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		std::cout << std::endl;
		try
		{
			PresidentialPardonForm pardonForm("PardonForm");
			std::cout << "\nCan Sign & Execute\n" << std::endl;
			Bureaucrat Steven("Steven", 1);
			std::cout << Steven << std::endl;
			std::cout << pardonForm << std::endl;
			Steven.signForm(pardonForm);
			std::cout << pardonForm << std::endl;
			Steven.executeForm(pardonForm);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		std::cout << std::endl;
		try
		{
			PresidentialPardonForm pardonForm("PardonForm");
			std::cout << "\nCan NOT Sign & NOT Execute\n" << std::endl;
			Bureaucrat Steven("Steven", 30);
			std::cout << Steven << std::endl;
			std::cout << pardonForm << std::endl;
			Steven.signForm(pardonForm);
			std::cout << pardonForm << std::endl;
			Steven.executeForm(pardonForm);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		std::cout << red << "\nTEST END : PresidentialPardonForm\n" << reset << std::endl;
	}
	return (0);
}
