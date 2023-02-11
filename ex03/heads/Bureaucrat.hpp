/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikoraxx <nikoraxx@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 13:29:07 by nikoraxx          #+#    #+#             */
/*   Updated: 2023/02/11 19:31:13 by nikoraxx         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <exception>
#include <iostream>
#include <string>

class Bureaucrat;

#include "Form.hpp"

class Bureaucrat
{
	private:
		std::string	const	_name;
		int					_grade;
	public:
		Bureaucrat(void);
		Bureaucrat(Bureaucrat const&);
		Bureaucrat(std::string const&, int);

		~Bureaucrat(void);

	//	Operators

		Bureaucrat &operator = (Bureaucrat const&);
		Bureaucrat &operator ++ (void);
		Bureaucrat &operator -- (void);

	//	Exceptions

		class GradeTooLowException;
		class GradeTooHighException;
	
	//	Get

		int					getGrade(void)	const;
		std::string	const	&getName(void)	const;

	//	Methods

		void				signForm(Form&);
		void				executeForm(Form const&);
};

std::ostream &operator << (std::ostream&, Bureaucrat const&);

class Bureaucrat::GradeTooLowException: public std::exception
{
	const char* what() const throw();
};

class Bureaucrat::GradeTooHighException: public std::exception
{
	const char* what() const throw();
};

#endif