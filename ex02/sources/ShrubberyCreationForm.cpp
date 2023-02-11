/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikoraxx <nikoraxx@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 19:10:09 by nikoraxx          #+#    #+#             */
/*   Updated: 2023/02/11 22:59:07 by nikoraxx         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../heads/ShrubberyCreationForm.hpp"

/*		CONSTRUCTORS		*/

ShrubberyCreationForm::ShrubberyCreationForm(void): Form("[TEMPLATE] Shrubbery Creation", "?", 145, 137)
{
	// std::cout << "ShrubberyCreationForm Default constructor.\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &to_copy): Form(to_copy)
{
	// std::cout << "ShrubberyCreationForm Copy constructor.\n";
	*this = to_copy;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target): Form("Shrubbery Creation", target, 145, 137)
{
}

/*		DESTRUCTOR		*/

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	// std::cout << "ShrubberyCreationForm Destructor.\n";
}

/*		OPERATORS		*/

ShrubberyCreationForm &ShrubberyCreationForm::operator = (ShrubberyCreationForm const &to_set_to)
{
	// std::cout << "ShrubberyCreationForm Assignation constructor.\n";
	Form::operator = (to_set_to);
	return (*this);
}

/*		METHODS			*/

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > this->getExecGrade())
		throw Form::GradeTooLowException();
	if (this->getSignState() == false)
		throw Form::UnapprovedFormException();
	this->_createShrubbery();
}

  /*------------------*/
 /*		 PRIVATE	 */
/*------------------*/

void ShrubberyCreationForm::_createShrubbery(void) const
{
	std::string const	new_creation_name = this->getTarget() + "_shrubbery";
	std::ofstream		new_creation(new_creation_name.data());

	if (!new_creation.is_open())
	{
		std::cout << "Well. This soil seems unshrubberisable.";
		return ;
	}
	new_creation << "       _-_\n";
	new_creation << "    /~~   ~~\\\n";
	new_creation << " /~~         ~~\\\n";
	new_creation << "{               }\n";
	new_creation << " \\  _-     -_  /\n";
	new_creation << "   ~  \\\\ //  ~\n";
	new_creation << "_- -   | | _- _\n";
	new_creation << "  _ -  | |   -_\n";
	new_creation << "      // \\\\\n";
	new_creation.close();
}
