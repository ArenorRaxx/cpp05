/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikoraxx <nikoraxx@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 20:38:02 by nikoraxx          #+#    #+#             */
/*   Updated: 2023/02/11 23:25:05 by nikoraxx         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "heads/Bureaucrat.hpp"
#include "heads/PresidentialPardonForm.hpp"
#include "heads/RobotomyRequestForm.hpp"
#include "heads/ShrubberyCreationForm.hpp"

int	main(void)
{
	Bureaucrat				Chad("Chad", 1);
	Bureaucrat				Taylor("Taylor", 16);
	Bureaucrat				Timmy("Timmy", 145);
	ShrubberyCreationForm	shruberryForm("Miss Sweety' garden");
	RobotomyRequestForm		robotomyForm("Doggo");
	PresidentialPardonForm	presidentialForm("Dieudonné");

	Timmy.signForm(shruberryForm);
	Timmy.executeForm(shruberryForm);

	std::cout << "\t----\n";

	Taylor.executeForm(shruberryForm);

	Timmy.signForm(robotomyForm);
	
	std::cout << "\t----\n";

	Taylor.signForm(robotomyForm);
	
	std::cout << "\t----\n";
	
	Taylor.executeForm(robotomyForm);
	Taylor.executeForm(robotomyForm);

	std::cout << "\t----\n";

	Taylor.signForm(presidentialForm);
	Taylor.executeForm(presidentialForm);

	std::cout << "\t----\n";

	Chad.executeForm(presidentialForm);

	std::cout << "\t----\n";
}