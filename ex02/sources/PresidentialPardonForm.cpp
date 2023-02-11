/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikoraxx <nikoraxx@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 19:10:09 by nikoraxx          #+#    #+#             */
/*   Updated: 2023/02/11 19:59:08 by nikoraxx         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../heads/PresidentialPardonForm.hpp"

/*		CONSTRUCTORS		*/

PresidentialPardonForm::PresidentialPardonForm(void): Form("[TEMPLATE] Presidential Pardon", "?", 25, 5)
{
	// std::cout << "PresidentialPardonForm Default constructor.\n";
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &to_copy): Form(to_copy)
{
	// std::cout << "PresidentialPardonForm Copy constructor.\n";
	*this = to_copy;
}

PresidentialPardonForm::PresidentialPardonForm(std::string const &target): Form("Presidential Pardon", target, 25, 5)
{
}

/*		DESTRUCTOR		*/

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	// std::cout << "PresidentialPardonForm Destructor.\n";
}

/*		OPERATORS		*/

PresidentialPardonForm &PresidentialPardonForm::operator = (PresidentialPardonForm const &to_set_to)
{
	// std::cout << "PresidentialPardonForm Assignation constructor.\n";
	Form::operator = (to_set_to);
	return (*this);
}

/*		METHODS			*/

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > this->getExecGrade())
		throw Form::GradeTooLowException();
	if (this->getSignState() == false)
		throw Form::UnapprovedFormException();
	std::cout << "His grace the Supreme President Head and Chief of State have indulgingly pardonned " << this->getTarget() << ". May they walk out safe.\n";
}
