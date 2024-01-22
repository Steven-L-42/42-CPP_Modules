/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slippert <slippert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 11:16:26 by slippert          #+#    #+#             */
/*   Updated: 2024/01/22 13:35:45 by slippert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AForm.hpp"

AForm::AForm() : name("noname"), req_grade(150), req_ex_grade(150),
	is_signed(false)
{
}

AForm::AForm(const AForm &ref) : name(ref.name), req_grade(ref.req_grade),
	req_ex_grade(ref.req_ex_grade), is_signed(false)
{
	if (this->GetExecGrade() > 150 || this->GetGrade() > 150)
		throw(AForm::GradeTooLowException());
	else if (this->GetExecGrade() < 1 || this->GetGrade() < 1)
		throw(AForm::GradeTooHighException());
}

AForm::AForm(std::string _name, int _req_grade,
	int _req_ex_grade) : name(_name), req_grade(_req_grade),
	req_ex_grade(_req_ex_grade), is_signed(false)
{
	if (this->GetExecGrade() > 150 || this->GetGrade() > 150)
		throw(AForm::GradeTooLowException());
	else if (this->GetExecGrade() < 1 || this->GetGrade() < 1)
		throw(AForm::GradeTooHighException());
}

void AForm::beSigned(Bureaucrat &ref)
{
	if (ref.getGrade() > this->GetGrade())
		throw(AForm::GradeTooLowException());
	else if (this->GetSign() == false)
	{
		this->is_signed = true;
		std::cout << ref.getName() << " signed " << this->GetName() << std::endl;
	}
	else
		std::cout << ref.getName() << " couldn't sign " << this->GetName() << " because it is already signed." << std::endl;
}

AForm::~AForm()
{
}

AForm &AForm::operator=(const AForm &ref)
{
	*this = ref;
	return (*this);
}

const char *AForm::NotSignedException::what() const throw()
{
	std::string error = red + std::string("your form is not signed") + reset;
	const char *message = error.c_str();
	return (message);
}

const char *AForm::GradeTooHighException::what() const throw()
{
	std::string error = red + std::string("your grade is too high") + reset;
	const char *message = error.c_str();
	return (message);
}

const char *AForm::GradeTooLowException::what() const throw()
{
	std::string error = red + std::string("your grade is too low") + reset;
	const char *message = error.c_str();
	return (message);
}

const std::string &AForm::GetName(void) const
{
	return (this->name);
}
const bool AForm::GetSign(void) const
{
	return (this->is_signed);
}
const int AForm::GetGrade(void) const
{
	return (this->req_grade);
}
const int AForm::GetExecGrade(void) const
{
	return (this->req_ex_grade);
}

std::ostream &operator<<(std::ostream &os, const AForm &ref)
{
	os << "Form Name: " << ref.GetName();
	os << ".	signed state: " << (ref.GetSign() ? "true" : "false");
	os << ".	Required Grade is: " << ref.GetGrade();
	os <<  ".	Required Exec Grade is " << ref.GetExecGrade() << ".";
	return (os);
}
void AForm::execute(Bureaucrat const &executor) const
{
	if (this->GetSign() == false)
		throw(AForm::NotSignedException());
	if (this->GetExecGrade() < executor.getGrade())
		throw(AForm::GradeTooLowException());
	this->action();
}
