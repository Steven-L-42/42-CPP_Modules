/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slippert <slippert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 11:16:26 by slippert          #+#    #+#             */
/*   Updated: 2024/01/15 14:01:52 by slippert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Form.hpp"

Form::Form() : name("noname"), req_grade(150), req_ex_grade(150),
	is_signed(false)
{
}

Form::Form(const Form &ref) : name(ref.name), req_grade(ref.req_grade),
	req_ex_grade(ref.req_ex_grade), is_signed(false)
{
	if (this->GetExecGrade() > 150 || this->GetGrade() > 150)
		throw(Form::GradeTooLowException());
	else if (this->GetExecGrade() < 1 || this->GetGrade() < 1)
		throw(Form::GradeTooHighException());
}

Form::Form(std::string _name, int _req_grade, int _req_ex_grade) : name(_name),
	req_grade(_req_grade), req_ex_grade(_req_ex_grade), is_signed(false)
{
	if (this->GetExecGrade() > 150 || this->GetGrade() > 150)
		throw(Form::GradeTooLowException());
	else if (this->GetExecGrade() < 1 || this->GetGrade() < 1)
		throw(Form::GradeTooHighException());
}

void Form::beSigned(Bureaucrat &ref)
{
	if (ref.getGrade() > this->GetGrade())
		throw(Form::GradeTooLowException());
	else if (this->GetSign() == false)
	{
		this->is_signed = true;
		std::cout << ref.getName() << " signed " << this->GetName() << std::endl;
	}
	else
		std::cout << ref.getName() << " couldn't sign " << this->GetName() << " because it is already signed." << std::endl;
}
Form::~Form()
{
}

Form &Form::operator=(const Form &ref)
{
	*this = ref;
	return (*this);
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Your grade is to high");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Your grade is to low");
}

const std::string &Form::GetName(void) const
{
	return (this->name);
}
const bool Form::GetSign(void) const
{
	return (this->is_signed);
}
const int Form::GetGrade(void) const
{
	return (this->req_grade);
}
const int Form::GetExecGrade(void) const
{
	return (this->req_ex_grade);
}

std::ostream &operator<<(std::ostream &os, const Form &ref)
{
	os << "Form Name: " << ref.GetName();
	os << ".	signed state: " << (ref.GetSign() ? "true" : "false");
	os << ".	Required Grade is: " << ref.GetGrade();
	os <<  ".	Required Exec Grade is " << ref.GetExecGrade() << ".";
	return (os);
}