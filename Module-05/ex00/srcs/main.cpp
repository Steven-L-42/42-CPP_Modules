/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slippert <slippert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 16:08:00 by slippert          #+#    #+#             */
/*   Updated: 2024/01/22 12:04:23 by slippert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

int main(void)
{
	std::cout << blue << "\n--- Start Instantiate Tests ---" << reset << std::endl;
	// Success Tests
	{
		try
		{
			std::cout << green << "\n1 : Expected = to success" << reset << std::endl;
			Bureaucrat Steven("Steven", 1);
			std::cout << Steven << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		try
		{
			std::cout << green << "\n50 : Expected = Success" << reset << std::endl;
			Bureaucrat Steven("Steven", 50);
			std::cout << Steven << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		try
		{
			std::cout << green << "\n75 : Expected = Success" << reset << std::endl;
			Bureaucrat Steven("Steven", 75);
			std::cout << Steven << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		try
		{
			std::cout << green << "\n150 : Expected = Success" << reset << std::endl;
			Bureaucrat Steven("Steven", 150);
			std::cout << Steven << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	// Fail Tests
	{
		try
		{
			std::cout << red << "\n151 : Expected = to low" << reset << std::endl;
			Bureaucrat Steven("Steven", 151);
			std::cout << Steven << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		try
		{
			std::cout << red << "\n225 : Expected = to low" << reset << std::endl;
			Bureaucrat Steven("Steven", 200);
			std::cout << Steven << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		try
		{
			std::cout << red << "\n0 : Expected = to high" << reset << std::endl;
			Bureaucrat Steven("Steven", 0);
			std::cout << Steven << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		try
		{
			std::cout << red << "\n-25 : Expected = to high" << reset << std::endl;
			Bureaucrat Steven("Steven", -1);
			std::cout << Steven << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}


	std::cout << blue << "\n--- Start Decrement Tests ---" << reset << std::endl;
	// Decrement Tests
	{
		try
		{
			std::cout << green << "\n1 to 2 : Expected = to success" << reset << std::endl;
			Bureaucrat Steven("Steven", 1);
			std::cout << Steven << std::endl;
			std::cout << blue << "=> Run DecrementGrade();" << reset << std::endl;
			Steven.DecrementGrade();
			std::cout << Steven << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		try
		{
			std::cout << green << "\n50 to 75 : Expected = to success" << reset << std::endl;
			Bureaucrat Steven("Steven", 50);
			std::cout << Steven << std::endl;
			std::cout << blue << "=> Run 25 * DecrementGrade();" << reset << std::endl;
			for (size_t i = 0; i < 25; i++)
				Steven.DecrementGrade();
			std::cout << Steven << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		try
		{
			std::cout << green << "\n145 to 150 : Expected = to success" << reset << std::endl;
			Bureaucrat Steven("Steven", 145);
			std::cout << Steven << std::endl;
			std::cout << blue << "=> Run 5 * DecrementGrade();" << reset << std::endl;
			for (size_t i = 0; i < 5; i++)
				Steven.DecrementGrade();
			std::cout << Steven << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		try
		{
			std::cout << red << "\n150 to 151 : Expected = to low" << reset << std::endl;
			Bureaucrat Steven("Steven", 150);
			std::cout << Steven << std::endl;
			std::cout << blue << "=> Run DecrementGrade();" << reset << std::endl;
			Steven.DecrementGrade();
			std::cout << Steven << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << blue << "\n--- Start Increment Tests ---" << reset << std::endl;
	// Increment Tests
	{
		try
		{
			std::cout << green << "\n10 to 9 : Expected = to success" << reset << std::endl;
			Bureaucrat Steven("Steven", 10);
			std::cout << Steven << std::endl;
			std::cout << blue << "=> Run IncrementGrade();" << reset << std::endl;
			Steven.IncrementGrade();
			std::cout << Steven << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		try
		{
			std::cout << green << "\n75 to 50 : Expected = to success" << reset << std::endl;
			Bureaucrat Steven("Steven", 75);
			std::cout << Steven << std::endl;
			std::cout << blue << "=> Run 25 * IncrementGrade();" << reset << std::endl;
			for (size_t i = 0; i < 25; i++)
				Steven.IncrementGrade();
			std::cout << Steven << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		try
		{
			std::cout << green << "\n145 to 100 : Expected = to success" << reset << std::endl;
			Bureaucrat Steven("Steven", 145);
			std::cout << Steven << std::endl;
			std::cout << blue << "=> Run 45 * IncrementGrade();" << reset << std::endl;
			for (size_t i = 0; i < 45; i++)
				Steven.IncrementGrade();
			std::cout << Steven << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		try
		{
			std::cout << red << "\n1 to 0 : Expected = to high" << reset << std::endl;
			Bureaucrat Steven("Steven", 1);
			std::cout << Steven << std::endl;
			std::cout << blue << "=> Run IncrementGrade();" << reset << std::endl;
			Steven.IncrementGrade();
			std::cout << Steven << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	return (0);
}
