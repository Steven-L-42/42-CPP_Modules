/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slippert <slippert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 11:16:26 by slippert          #+#    #+#             */
/*   Updated: 2024/01/23 19:04:03 by slippert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Form.hpp"

Form::Form() : name("noname"), is_signed(false), req_grade(150), req_ex_grade(150)
{
}

Form::Form(const Form &ref) : name(ref.name), is_signed(false), req_grade(ref.req_grade), req_ex_grade(ref.req_ex_grade)
{
	if (this->GetExecGrade() > 150 || this->GetGrade() > 150)
		throw(Form::GradeTooLowException());
	else if (this->GetExecGrade() < 1 || this->GetGrade() < 1)
		throw(Form::GradeTooHighException());
}

Form::Form(std::string _name, int _req_grade, int _req_ex_grade) : name(_name),
																   is_signed(false), req_grade(_req_grade), req_ex_grade(_req_ex_grade)
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

// Form &Form::operator=(const Form &ref)
// {
// 	*this = ref;
// 	return (*this);
// }

const char *Form::GradeTooHighException::what() const throw()
{
	std::string error = red + std::string("your grade is too high") + reset;
	const char *message = error.c_str();
	return (message);
}

const char *Form::GradeTooLowException::what() const throw()
{
	std::string error = red + std::string("your grade is too low") + reset;
	const char *message = error.c_str();
	return (message);
}

const std::string &Form::GetName(void) const
{
	return (this->name);
}
bool Form::GetSign(void) const
{
	return (this->is_signed);
}
int Form::GetGrade(void) const
{
	return (this->req_grade);
}
int Form::GetExecGrade(void) const
{
	return (this->req_ex_grade);
}

std::ostream &operator<<(std::ostream &os, const Form &ref)
{
	os << "Form Name: " << ref.GetName();
	os << ".	signed state: " << (ref.GetSign() ? "true" : "false");
	os << ".	Required Grade is: " << ref.GetGrade();
	os << ".	Required Exec Grade is " << ref.GetExecGrade() << ".";
	return (os);
}