/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slippert <slippert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 18:40:20 by slippert          #+#    #+#             */
/*   Updated: 2024/01/14 18:47:04 by slippert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
  private:
  public:
	PresidentialPardonForm();
	PresidentialPardonForm(const PresidentialPardonForm &ref);
	PresidentialPardonForm &operator=(const PresidentialPardonForm &ref);
	PresidentialPardonForm(AForm &ref);
	~PresidentialPardonForm();
};

PresidentialPardonForm::PresidentialPardonForm()
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &ref)
{
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &ref)
{
	*this = ref;
	return (*this);
}

PresidentialPardonForm::PresidentialPardonForm(AForm &ref)
{
	if 
	ref.beSigned()
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}
