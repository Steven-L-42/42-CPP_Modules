/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slippert <slippert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 16:08:04 by slippert          #+#    #+#             */
/*   Updated: 2024/01/22 13:13:37 by slippert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "AForm.hpp"

#define blue "\033[2;34m"
#define orange "\033[2;33m"
#define red "\033[2;31m"
#define green "\033[2;32m"
#define reset "\033[0m"

class AForm;

class Bureaucrat
{
  private:
	const std::string name;
	int grade;

  public:
	Bureaucrat();
	Bureaucrat(std::string _name, int _grade);
	Bureaucrat(Bureaucrat &ref);
	Bureaucrat &operator=(const Bureaucrat &ref);
	~Bureaucrat();
	const std::string &getName() const;
	int getGrade() const;
	void IncrementGrade();
	void DecrementGrade();
	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
	void signForm(AForm &ref);
	void executeForm(const AForm &ref);
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &obj);