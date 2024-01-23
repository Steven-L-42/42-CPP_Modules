/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slippert <slippert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 13:39:53 by slippert          #+#    #+#             */
/*   Updated: 2024/01/23 19:08:14 by slippert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("default_form", 25, 5)
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string home) : AForm(home, 25, 5)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &ref) : AForm(ref.GetName(), 25, 5)
{
}

// PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &ref)
// {
// 	*this = ref;
// 	return (*this);
// }

PresidentialPardonForm::~PresidentialPardonForm()
{
}

void PresidentialPardonForm::action() const
{
	std::cout << GetName() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
