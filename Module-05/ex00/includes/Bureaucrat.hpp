/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slippert <slippert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 16:08:04 by slippert          #+#    #+#             */
/*   Updated: 2024/01/13 17:59:38 by slippert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Bureaucrat
{
  private:
	const std::string name;
	int grade;

  public:
	Bureaucrat();
	Bureaucrat(std::string _name, int _grade);
	Bureaucrat(Bureaucrat &ref);
	Bureaucrat &operator=(const Bureaucrat &ref);
	~Bureaucrat();
	const std::string &getName() const;
	int getGrade() const;
	void IncrementGrade();
	void DecrementGrade();
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

std::ostream &operator<<(std::ostream &os, const Bureaucrat &obj);