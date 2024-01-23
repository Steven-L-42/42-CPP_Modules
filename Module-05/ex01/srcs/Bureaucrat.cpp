/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slippert <slippert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 16:08:02 by slippert          #+#    #+#             */
/*   Updated: 2024/01/23 19:02:22 by slippert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("noname"), grade(150){}

Bureaucrat::Bureaucrat(std::string _name, int _grade) : name(_name), grade(_grade)

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

// Bureaucrat &Bureaucrat::operator=(const Bureaucrat &ref)
// {
// 	*this = ref;
// 	return (*this);
// }

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
	else
		throw (Bureaucrat::GradeTooHighException());
}

void Bureaucrat::DecrementGrade()
{
	if (this->grade < 150)
		this->grade += 1;
	else
		throw (Bureaucrat::GradeTooLowException());
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	std::string error = red + std::string("your grade is too high") + reset;
	const char *message = error.c_str();
	return (message);
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	std::string error = red + std::string("your grade is too low") + reset;
	const char *message = error.c_str();
	return (message);
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
