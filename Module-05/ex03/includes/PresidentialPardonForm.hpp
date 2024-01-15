/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slippert <slippert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 12:09:57 by slippert          #+#    #+#             */
/*   Updated: 2024/01/15 13:40:09 by slippert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
  private:
  public:
	PresidentialPardonForm();
	PresidentialPardonForm(std::string home);
	PresidentialPardonForm(const PresidentialPardonForm &ref);
	PresidentialPardonForm &operator=(const PresidentialPardonForm &ref);
	~PresidentialPardonForm();
	virtual void action() const;
};
