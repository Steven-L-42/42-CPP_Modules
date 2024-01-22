/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slippert <slippert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 16:08:00 by slippert          #+#    #+#             */
/*   Updated: 2024/01/22 13:07:27 by slippert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"

int	main(void)
{
	{
		std::cout << blue << "\nTEST START : ShrubberyCreationForm" << reset << std::endl;
		try
		{
			ShrubberyCreationForm shrubberForm("ShrubberForm");
			std::cout << red << "\n~ Expected FAIL : Is NOT Signed before Execute ~" << reset << std::endl;
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
			std::cout << red << "\n~ Expected FAIL : Can Sign but NOT Execute ~" << reset << std::endl;
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
			std::cout << red << "\n~ Expected FAIL : Can NOT Sign & NOT Execute ~" << reset << std::endl;
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
		std::cout << std::endl;
		try
		{
			ShrubberyCreationForm shrubberForm("ShrubberForm");
			std::cout << green << "\n~ Expected SUCCESS : Can Sign & Execute ~" << reset << std::endl;
			Bureaucrat Steven("Steven", 137);
			std::cout << Steven << std::endl;
			std::cout << shrubberForm << std::endl;
			Steven.signForm(shrubberForm);
			Steven.executeForm(shrubberForm);
			std::cout << shrubberForm << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}


		std::cout << orange << "\nTEST END : ShrubberyCreationForm\n" << reset << std::endl;
	}
	std::cout << "-------------------------------------------" << std::endl;
	{
		std::cout << blue << "\nTEST START : RobotomyRequestForm" << reset << std::endl;
		try
		{
			RobotomyRequestForm robotForm("RobotForm");
			std::cout << red << "\n~ Expected FAIL : Is NOT Signed before Execute ~" << reset << std::endl;
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
			std::cout << red << "\n~ Expected FAIL : Can Sign but NOT Execute ~" << reset << std::endl;
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
			std::cout << red << "\n~ Expected FAIL : Can NOT Sign & NOT Execute ~" << reset << std::endl;
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
		std::cout << std::endl;
		try
		{
			RobotomyRequestForm robotForm("RobotForm");
			std::cout << green << "\n~ Expected SUCCESS : Can Sign & Execute ~" << reset << std::endl;
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

		std::cout << orange << "\nTEST END : RobotomyRequestForm\n" << reset << std::endl;
	}
	std::cout << "-------------------------------------------" << std::endl;
	{
		std::cout << blue << "\nTEST START : PresidentialPardonForm" << reset << std::endl;
		try
		{
			PresidentialPardonForm pardonForm("PardonForm");
			std::cout << red << "\n~ Expected FAIL : Is NOT Signed before Execute ~" << reset << std::endl;
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
			std::cout << red << "\n~ Expected FAIL : Can Sign but NOT Execute ~" << reset << std::endl;
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
			std::cout << red << "\n~ Expected FAIL : Can NOT Sign & NOT Execute ~" << reset << std::endl;
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
		std::cout << std::endl;
		try
		{
			PresidentialPardonForm pardonForm("PardonForm");
			std::cout << green << "\n~ Expected SUCCESS : Can Sign & Execute ~" << reset << std::endl;
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
		std::cout << orange << "\nTEST END : PresidentialPardonForm\n" << reset << std::endl;
	}
	return (0);
}
