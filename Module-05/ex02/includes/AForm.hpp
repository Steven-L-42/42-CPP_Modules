/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slippert <slippert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 17:43:31 by slippert          #+#    #+#             */
/*   Updated: 2024/01/14 18:15:51 by slippert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
  private:
	const std::string name;
	bool is_signed;
	const int grade;

  public:
	AForm();
	AForm(std::string _name, int _grade);
	AForm(const AForm &ref);
	AForm &operator=(const AForm &ref);
	~AForm();
	const std::string &GetName() const;
	const int GetGrade() const;
	bool GetSign() const;
	void beSigned(Bureaucrat &ref);

	void execute(Bureaucrat const & executor);
	class GradeTooHighException : public std::exception
	{
		public:
		virtual const char *what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		public:
		virtual const char *what() const throw();
	};
};


