/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slippert <slippert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 17:43:57 by slippert          #+#    #+#             */
/*   Updated: 2024/01/14 18:36:08 by slippert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AForm.hpp"

std::ostream &operator<<(std::ostream &os, const AForm &ref)
{
	os << "Name: " << ref.GetName() << ", Grade: " << ref.GetGrade() << "Signed: " << ref.GetSign() << std::endl;
	return (os);
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("your grade is too high");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("your grade is too low");
}

AForm::AForm() : name("noname"), grade(150), is_signed(false)
{
}

AForm::AForm(std::string _name, int _grade) : name(_name), grade(_grade),
	is_signed(false)
{
}

AForm::AForm(const AForm &ref) : name(ref.name), grade(ref.grade),
	is_signed(ref.is_signed)
{
}

AForm &AForm::operator=(const AForm &ref)
{
	*this = ref;
	return (*this);
}

AForm::~AForm()
{
}

bool AForm::GetSign() const
{
	return (this->is_signed);
}

void AForm::beSigned(Bureaucrat &ref)
{
	if (ref.getGrade() > this->GetGrade())
		throw AForm::GradeTooLowException();
	else if (this->GetSign())
		std::cout << this->GetName() << " : is already signed" << std::endl;
	else
	{
		this->is_signed = true;
		std::cout << this->GetName() << " : is now signed by " << ref.getName() << std::endl;
	}
}
const int AForm::GetGrade() const
{
	return (this->grade);
}

const std::string &AForm::GetName() const
{
	return (this->name);
}