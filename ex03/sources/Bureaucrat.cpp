/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikoraxx <nikoraxx@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 13:48:09 by nikoraxx          #+#    #+#             */
/*   Updated: 2023/02/11 19:58:36 by nikoraxx         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../heads/Bureaucrat.hpp"

/*		CONSTRUCTORS		*/

Bureaucrat::Bureaucrat(void): _name(""), _grade(0)
{
	// std::cout << "Bureaucrat Default constructor.\n";
}

Bureaucrat::Bureaucrat(Bureaucrat const &to_copy): _name(to_copy._name)
{
	// std::cout << "Bureaucrat Copy constructor.\n";
	*this = to_copy;
}

Bureaucrat::Bureaucrat(std::string const &name, int grade): _name(name)
{
	// std::cout << "Bureaucrat Full constructor.\n";
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	_grade = grade;
}

/*		DESTRUCTOR		*/

Bureaucrat::~Bureaucrat(void)
{
	// std::cout << "Bureaucrat Destructor.\n";
}

/*		OPERATORS		*/

Bureaucrat &Bureaucrat::operator = (Bureaucrat const &to_set_to)
{
	// std::cout << "Bureaucrat Assignation constructor.\n";
	this->_grade = to_set_to._grade;
	return (*this);
}

Bureaucrat &Bureaucrat::operator ++ (void)
{
	if (this->_grade - 1 < 1)
		throw GradeTooHighException();
	this->_grade -= 1;
	std::cout << "Bureaucrat " << this->_name << " has been promoted to grade " << this->_grade << ". Congratulations.\n";
	return (*this);
}

Bureaucrat &Bureaucrat::operator -- (void)
{
	if (this->_grade + 1 > 150)
		throw GradeTooLowException();
	this->_grade += 1;
	std::cout << "Bureaucrat " << this->_name << " has been demoted to grade " << this->_grade << ". What a shame.\n";
	return (*this);
}

std::ostream &operator << (std::ostream &out, Bureaucrat const &object)
{
	out << object.getName() << ", no." << object.getGrade() << "\n";
	return (out);
}

/*		EXCEPTIONS		*/

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade Too High: You can't, and should not ever give a Bureaucrat that much power.\n");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade Too Low: You can't treat human beings like that, sadly. They might revolt.\n");
}

/*		GET			*/

int Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

std::string const &Bureaucrat::getName(void) const
{
	return (this->_name);
}

/*		METHODS		*/

void Bureaucrat::signForm(Form &to_sign)
{
	if (to_sign.getSignState() == true)
	{
		std::cout << "Double-signing a contract? What for? Extras?\n";
		return ;
	}
	try
	{
		to_sign.beSigned(*this);
		std::cout << this->_name << " has approved a " << to_sign.getName() << " form.\n";
	}
	catch(Form::GradeTooLowException &error)
	{
		std::cout << "\n\t----WARNING BROADCAST----\n";
		std::cout << "\tNOXIOUS ACTIVITY DETECTED\n\n";
		std::cout << "TARGET:\t\t" << *this;
		std::cout << "WRONGDOING:\tAttempt to fraud and falsification.\n\n";
		try {
			--*this;
		} catch (std::exception &error) {
			std::cout << error.what();
		}
		std::cout << '\n';
	}
	
}

void Bureaucrat::executeForm(Form const &to_sign)
{
	try {
		to_sign.execute(*this);
		std::cout << this->_name << " has successfully executed a " << to_sign.getName() << " form.\n";
		++*this;
	} catch (std::exception &error) {
		std::cout << error.what();
	}
}
