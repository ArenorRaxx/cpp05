/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikoraxx <nikoraxx@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 20:38:02 by nikoraxx          #+#    #+#             */
/*   Updated: 2023/02/12 00:09:26 by nikoraxx         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "heads/Intern.hpp"
#include "heads/Bureaucrat.hpp"

int	main(void)
{
	Bureaucrat				Chad("Chad", 1);
	Bureaucrat				Taylor("Taylor", 16);
	Intern					Timmy;
	Form					*new_form;

	new_form = Timmy.makeForm("Shrubbery Creation", "Miss Sweety' garden");
	Taylor.signForm(*new_form);
	Chad.executeForm(*new_form);
	delete new_form;
}

