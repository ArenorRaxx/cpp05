/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikoraxx <nikoraxx@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 15:00:40 by nikoraxx          #+#    #+#             */
/*   Updated: 2023/02/11 18:43:05 by nikoraxx         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../heads/Form.hpp"

/*		CONSTRUCTORS		*/

Form::Form(void): _name("Template"), _auth_grade(150), _exec_grade(150), _is_signed(0)
{
	// std::cout << "Form Default constructor.\n";
}

Form::Form(Form const &to_copy): _name(to_copy._name)
{
	// std::cout << "Form Copy constructor.\n";
	*this = to_copy;
}

Form::Form(std::string const &name, int auth_grade, int exec_grade): _name(name), _is_signed(0)
{
	// std::cout << "Form Full constructor.\n";
	if (auth_grade < 1 || exec_grade < 1)
		throw GradeTooHighException();
	if (auth_grade > 150 || exec_grade > 150)
		throw GradeTooLowException();
	this->_auth_grade = auth_grade;
	this->_exec_grade = exec_grade;
}

/*		DESTRUCTOR		*/

Form::~Form(void)
{
	// std::cout << "Form Destructor.\n";
}

/*		OPERATORS		*/

Form &Form::operator = (Form const &to_set_to)
{
	// std::cout << "Form Assignation constructor.\n";
	this->_auth_grade = to_set_to._auth_grade;
	this->_exec_grade = to_set_to._exec_grade;
	this->_is_signed = to_set_to._is_signed;
	return (*this);
}

std::ostream &operator << (std::ostream &out, Form const &f)
{
	out << "\t----FORM----\n\n";
	out << "NAME:\t\t\t" << f.getName() << ";\n";
	out << "AUTH GRADE REQ.:\t" << f.getAuthGrade() << " or higher;\n";
	out << "EXEC GRADE REQ.:\t" << f.getExecGrade() << " or higher;\n";
	out << "\nAPPROVED FOR EXEC.";
	if (f.getSignState() == true)
		out << "\t☑";
	else
		out << "\t☐";
	out << "\n\n\t----FORM----\n";
	return (out);
}

/*		EXCEPTIONS		*/

const char* Form::GradeTooLowException::what(void) const throw()
{
	return "We surely can't let such low graded people handle these affairs. What are you thinking?\n";
}

const char* Form::GradeTooHighException::what(void) const throw()
{
	return "Don't waste paper, nothing belongs to this kind of grade. Nothing tangible, of course.\n";
}

/*		GET			*/

std::string const &Form::getName(void) const
{
	return (this->_name);
}

int Form::getAuthGrade(void) const
{
	return (this->_auth_grade);
}

int Form::getExecGrade(void) const
{
	return (this->_exec_grade);
}

bool Form::getSignState(void) const
{
	return (this->_is_signed);
}

/*		METHODS			*/

void Form::beSigned(Bureaucrat const &b)
{
	if (b.getGrade() > this->_auth_grade)
		throw GradeTooLowException();
	this->_is_signed = true;
}
