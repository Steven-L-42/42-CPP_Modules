/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slippert <slippert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 13:39:24 by slippert          #+#    #+#             */
/*   Updated: 2024/01/22 13:25:47 by slippert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("default_form", 72, 45)
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string home) : AForm(home, 72, 45)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &ref) : AForm(ref.GetName(), 72, 45)
{
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &ref)
{
	*this = ref;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

void RobotomyRequestForm::action() const
{
	if (clock() % 2)
		std::cout << GetName() << " has been robotomized successfully 50\% of the time." << std::endl;
	else
		std::cout << red << "robotomy failed!" << reset << std::endl;
}
