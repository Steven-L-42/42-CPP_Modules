/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slippert <slippert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 13:38:50 by slippert          #+#    #+#             */
/*   Updated: 2024/01/23 19:08:23 by slippert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("default_form", 145, 137)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string home) : AForm(home,
	145, 137)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &ref) : AForm(ref.GetName(),
	145, 137)
{
}

// ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &ref)
// {
// 	*this = ref;
// 	return (*this);
// }

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

void ShrubberyCreationForm::action() const
{
	std::string name_File = GetName() + "_shrubbery";
	std::ofstream of_File(name_File.c_str());
	if (!of_File.is_open())
		throw std::exception();
	of_File << "    ▲    " << std::endl;
	of_File << "   ▲▲▲   " << std::endl;
	of_File << "  ▲▲▲▲▲  " << std::endl;
	of_File << " ▲▲▲▲▲▲▲ " << std::endl;
	of_File << "▲▲▲▲▲▲▲▲▲" << std::endl;
	of_File << "   〉〈   " << std::endl;
	of_File << "   〉〈   " << std::endl;
	of_File << "   〉〈   " << std::endl;
}
