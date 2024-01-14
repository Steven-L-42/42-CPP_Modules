/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slippert <slippert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 17:43:57 by slippert          #+#    #+#             */
/*   Updated: 2024/01/14 19:01:42 by slippert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Form.hpp"

Form::Form() : name("noname"), grade(150), is_signed(false), exec_grade(150)
{
}

Form::Form(std::string _name, int _grade, int _exec_grade) : name(_name), grade(_grade),
	is_signed(false), exec_grade(_exec_grade)
{
	if (this->GetGrade() > 150 || this->GetExecGrade() > 150)
		throw Form::GradeTooLowException();
	else if (this->GetGrade() < 1 || this->GetExecGrade() < 1)
		throw Form::GradeTooHighException();
}

Form::Form(const Form &ref) : name(ref.name), grade(ref.grade),
	is_signed(ref.is_signed), exec_grade(ref.exec_grade)
{
	if (ref.GetGrade() > 150 || ref.GetExecGrade() > 150)
		throw Form::GradeTooLowException();
	else if (ref.GetGrade() < 1 || ref.GetExecGrade() < 1)
		throw Form::GradeTooHighException();
}

Form::~Form()
{
}

std::ostream &operator<<(std::ostream &os, const Form &ref)
{
	os << "Name: " << ref.GetName() << ", Grade: " << ref.GetGrade() << ", Exec_Grade: " << ref.GetExecGrade()  << " Signed: " << ref.GetSign() << std::endl;
	return (os);
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("your grade is too high");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("your grade is too low");
}

Form &Form::operator=(const Form &ref)
{
	*this = ref;
	return (*this);
}

bool Form::GetSign() const
{
	return (this->is_signed);
}

void Form::beSigned(Bureaucrat &ref)
{
	if (ref.getGrade() > this->GetGrade())
		throw Form::GradeTooLowException();
	else if (this->GetSign())
		std::cout << this->GetName() << " : is already signed" << std::endl;
	else
	{
		this->is_signed = true;
		std::cout << this->GetName() << " : is now signed by " << ref.getName() << std::endl;
	}
}
const int Form::GetGrade() const
{
	return (this->grade);
}

const int Form::GetExecGrade() const
{
	return (this->exec_grade);
}

const std::string &Form::GetName() const
{
	return (this->name);
}