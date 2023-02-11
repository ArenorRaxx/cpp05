/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikoraxx <nikoraxx@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 13:29:07 by nikoraxx          #+#    #+#             */
/*   Updated: 2023/02/11 14:25:48 by nikoraxx         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <exception>
#include <iostream>
#include <string>

class Form;

#include "Bureaucrat.hpp"

class Form
{
	private:
		std::string	const	_name;
		std::string const	_target;
		int					_auth_grade;
		int					_exec_grade;
		bool				_is_signed;
	public:
		Form(void);
		Form(Form const&);
		Form(std::string const&, std::string const&, int, int);

		virtual ~Form(void);

	//	Operators

		Form &operator = (Form const&);

	//	Exceptions

		class GradeTooLowException;
		class GradeTooHighException;
		class UnapprovedFormException;
	
	//	Get

		std::string	const	&getName(void) 		const;
		std::string	const	&getTarget(void)	const;
		int					getAuthGrade(void)	const;
		int					getExecGrade(void)	const;
		bool				getSignState(void)	const;
	
	//	Methods

		void	beSigned(Bureaucrat const&);
virtual	void	execute(Bureaucrat const&) const = 0;
};

std::ostream &operator << (std::ostream&, Form const&);

class Form::GradeTooLowException: public std::exception
{
	public:
		const char* what() const throw();
};

class Form::GradeTooHighException: public std::exception
{
	public:
		const char* what() const throw();
};

class Form::UnapprovedFormException: public std::exception
{
	public:
		const char* what() const throw();
};

#endif