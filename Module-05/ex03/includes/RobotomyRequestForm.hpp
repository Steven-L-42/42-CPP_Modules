/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slippert <slippert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 12:09:31 by slippert          #+#    #+#             */
/*   Updated: 2024/01/15 13:39:39 by slippert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
  private:
  public:
	RobotomyRequestForm();
	RobotomyRequestForm(std::string home);
	RobotomyRequestForm(const RobotomyRequestForm &ref);
	RobotomyRequestForm &operator=(const RobotomyRequestForm &ref);
	~RobotomyRequestForm();
	virtual void action() const;
};
