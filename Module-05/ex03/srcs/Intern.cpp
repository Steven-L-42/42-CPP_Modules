/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slippert <slippert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:29:50 by slippert          #+#    #+#             */
/*   Updated: 2024/01/22 13:32:44 by slippert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Intern.hpp"

Intern::Intern()
{
}

Intern::Intern(const Intern &ref)
{
}

Intern::~Intern()
{
}

Intern &Intern::operator=(const Intern &ref)
{
	*this = ref;
	return (*this);
}

const char *Intern::NotExistingFormException::what() const throw()
{
	std::string error = red + std::string("Requested form does not exist") + reset;
	const char *message = error.c_str();
	return (message);
}

static AForm *CreateShrubberyRequest(std::string target)
{
	return (new ShrubberyCreationForm(target));
}

static AForm *CreateRobotomyRequest(std::string target)
{
	return (new RobotomyRequestForm(target));
}

static AForm *CreatePresidential(std::string target)
{
	return (new PresidentialPardonForm(target));
}

AForm *Intern::makeForm(std::string formName, const std::string target)
{
	std::string Forms[3] = {"shrubbery request", "robotomy request", "presidential request"};
	AForm *(*List[])(const std::string target) = {CreateShrubberyRequest, CreateRobotomyRequest, CreatePresidential};
	for (int i = 0; i < 3; i++)
	{
		if (Forms[i] == formName)
		{
			std::cout << "Intern creates Form " << formName << std::endl;
			return (List[i](target));
		}
	}
	throw(Intern::NotExistingFormException());
	return (NULL);
}
