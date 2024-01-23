/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slippert <slippert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 11:09:08 by slippert          #+#    #+#             */
/*   Updated: 2024/01/23 11:13:34 by slippert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Bureaucrat.hpp"

class	Bureaucrat;

class Form
{
  private:
	const std::string name;
	bool is_signed;
	const int req_grade;
	const int req_ex_grade;
  public:
	Form();
	Form(const Form &ref);
	Form &operator=(const Form &ref);
	~Form();
	Form(std::string _name, int _req_grade, int _req_ex_grade);
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
	const std::string &GetName() const;
	const bool GetSign() const;
	const int GetGrade() const;
	const int GetExecGrade() const;
	void beSigned(Bureaucrat &ref);
};

std::ostream &operator<<(std::ostream &os, const Form &ref);