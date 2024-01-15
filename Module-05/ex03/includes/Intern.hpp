/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slippert <slippert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:02:39 by slippert          #+#    #+#             */
/*   Updated: 2024/01/15 15:25:23 by slippert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
  private:
  public:
	Intern();
	Intern(const Intern &ref);
	Intern &operator=(const Intern &ref);
	~Intern();
	AForm *makeForm(std::string formName, std::string formTarget);
	class NotExistingFormException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
};
