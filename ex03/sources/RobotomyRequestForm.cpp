/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikoraxx <nikoraxx@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 19:10:09 by nikoraxx          #+#    #+#             */
/*   Updated: 2023/02/11 19:59:08 by nikoraxx         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../heads/RobotomyRequestForm.hpp"

/*		CONSTRUCTORS		*/

bool RobotomyRequestForm::_coin(true);

RobotomyRequestForm::RobotomyRequestForm(void): Form("[TEMPLATE] Robotomy Request", "?", 72, 45)
{
	// std::cout << "RobotomyRequestForm Default constructor.\n";
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &to_copy): Form(to_copy)
{
	// std::cout << "RobotomyRequestForm Copy constructor.\n";
	*this = to_copy;
}

RobotomyRequestForm::RobotomyRequestForm(std::string const &target): Form("Robotomy Request", target, 72, 45)
{
	// std::cout << "RobotomyRequestForm Full constructor.\n";
}

/*		DESTRUCTOR		*/

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	// std::cout << "RobotomyRequestForm Destructor.\n";
}

/*		OPERATORS		*/

RobotomyRequestForm &RobotomyRequestForm::operator = (RobotomyRequestForm const &to_set_to)
{
	// std::cout << "RobotomyRequestForm Assignation constructor.\n";
	Form::operator = (to_set_to);
	return (*this);
}

/*		METHODS			*/

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > this->getExecGrade())
		throw Form::GradeTooLowException();
	if (this->getSignState() == false)
		throw Form::UnapprovedFormException();
	std::cout << "* Electromecanic sounds emphasizing *\n";
	if (this->_coin == true)
		std::cout << this->getTarget() << " has been robotomized. Lucky " << this->getTarget() << ".\n";
	else
		std::cout << "The operation failed. Too bad. " << this->getTarget() << " had 50% chances.\n";
	RobotomyRequestForm::_flip_coin();
}

  /*------------------*/
 /*		 PRIVATE	 */
/*------------------*/

void RobotomyRequestForm::_flip_coin(void)
{
	RobotomyRequestForm::_coin = !RobotomyRequestForm::_coin;
}
