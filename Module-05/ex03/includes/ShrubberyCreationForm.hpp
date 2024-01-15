/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slippert <slippert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 12:07:39 by slippert          #+#    #+#             */
/*   Updated: 2024/01/15 13:39:08 by slippert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm
{
  private:
  public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(std::string home);
	ShrubberyCreationForm(const ShrubberyCreationForm &ref);
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &ref);
	~ShrubberyCreationForm();
	virtual void action() const;
};
