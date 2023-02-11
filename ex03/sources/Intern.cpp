/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikoraxx <nikoraxx@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 23:36:25 by nikoraxx          #+#    #+#             */
/*   Updated: 2023/02/12 00:08:55 by nikoraxx         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../heads/Intern.hpp"

const std::string Intern::_name_of_form[3] = {"Shrubbery Creation", "Robotomy Request", "Presidential Pardon"};

Intern::Intern(void)
{
	// std::cout << "Intern Default constructor.\n";
}

Intern::Intern(Intern const &to_copy)
{
	// std::cout << "Intern Copy constructor.\n";
	*this = to_copy;
}

Intern &Intern::operator = (Intern const&)
{
	// std::cout << "Intern Assignation constructor.\n";
	return (*this);
}

Intern::~Intern(void)
{
	// std::cout << "Intern Destructor.\n";
}

//	Methods

Form *Intern::makeForm(std::string const &form_to_create, std::string const &target)
{
	int		form_id = -1;
	Form	*new_form;

	while (++form_id < 3)
		if (Intern::_name_of_form[form_id].compare(form_to_create) == 0)
			break ;
	switch (form_id)
	{
		case 0:
			new_form = new ShrubberyCreationForm(target);
			break;
		
		case 1:
			new_form = new RobotomyRequestForm(target);
			break;
		
		case 2:
			new_form = new PresidentialPardonForm(target);
			break;

		default:
			std::cout << "Hum... S-Sorry, I d-don't think we.. Excuse me one m-moment....\n";
			return NULL;
	}
	std::cout << "Intern successfully created a new " << new_form->getName() << " form. Good intern.\n";
	return (new_form);
}
