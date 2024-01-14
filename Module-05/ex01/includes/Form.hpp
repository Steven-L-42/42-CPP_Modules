/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slippert <slippert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 17:43:31 by slippert          #+#    #+#             */
/*   Updated: 2024/01/14 18:56:46 by slippert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
  private:
	const std::string name;
	bool is_signed;
	const int grade;
	const int exec_grade;
  public:
	Form();
	Form(std::string _name, int _grade, int _exec_grade);
	Form(const Form &ref);
	Form &operator=(const Form &ref);
	~Form();
	const std::string &GetName() const;
	const int GetGrade() const;
	const int GetExecGrade() const;
	bool GetSign() const;
	void beSigned(Bureaucrat &ref);
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


