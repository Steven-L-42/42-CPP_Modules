/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slippert <slippert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 16:08:02 by slippert          #+#    #+#             */
/*   Updated: 2024/01/15 14:01:36 by slippert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : grade(150), name("noname") {}

Bureaucrat::Bureaucrat(std::string _name, int _grade) : grade(_grade),
	name(_name)
{
	if (_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (_grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		grade = _grade;
}

Bureaucrat::Bureaucrat(Bureaucrat &ref) : name(ref.getName()), grade(ref.getGrade()) {}
Bureaucrat::~Bureaucrat() {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &ref)
{
	*this = ref;
	return (*this);
}

const std::string& Bureaucrat::getName() const
{
	return (this->name);
}

int Bureaucrat::getGrade() const
{
	return (this->grade);
}

void Bureaucrat::IncrementGrade()
{
	if (this->grade > 1)
		this->grade -= 1;
}

void Bureaucrat::DecrementGrade()
{
	if (this->grade < 150)
		this->grade += 1;
}

const char*	Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("your grade is too high");
}

const char*	Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("your grade is too low");
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& src) {
	os << "Bureucrat Name: " << src.getName() << ".";
	os << "	Level: " << src.getGrade() << ".";
	return os;
}

void Bureaucrat::signForm(Form &ref)
{
	ref.beSigned(*this);
}