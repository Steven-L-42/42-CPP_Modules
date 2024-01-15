/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slippert <slippert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 11:09:08 by slippert          #+#    #+#             */
/*   Updated: 2024/01/15 12:41:48 by slippert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Bureaucrat.hpp"

class	Bureaucrat;

class AForm
{
  private:
	const std::string name;
	bool is_signed;
	const int req_grade;
	const int req_ex_grade;

  public:
	AForm();
	AForm(const AForm &ref);
	AForm &operator=(const AForm &ref);
	virtual ~AForm();
	AForm(std::string _name, int _req_grade, int _req_ex_grade);
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
	class NotSignedException : public std::exception
	{
		public:
		virtual const char *what() const throw();
	};
	const std::string &GetName() const;
	const bool GetSign() const;
	const int GetGrade() const;
	const int GetExecGrade() const;
	void beSigned(Bureaucrat &ref);

	virtual void execute(Bureaucrat const &executor) const;
	virtual void action(void) const = 0;
};

std::ostream &operator<<(std::ostream &os, const AForm &ref);