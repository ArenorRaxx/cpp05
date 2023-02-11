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
		int					_auth_grade;
		int					_exec_grade;
		bool				_is_signed;
	public:
		Form(void);
		Form(Form const&);
		Form(std::string const&, int, int);

		~Form(void);

	//	Operators

		Form &operator = (Form const&);

	//	Exceptions

		class GradeTooLowException;
		class GradeTooHighException;
	
	//	Get

		std::string	const	&getName(void) 		const;
		int					getAuthGrade(void)	const;
		int					getExecGrade(void)	const;
		bool				getSignState(void)	const;
	
	//	Methods

		void	beSigned(Bureaucrat const&);
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

#endif