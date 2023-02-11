/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikoraxx <nikoraxx@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 20:38:02 by nikoraxx          #+#    #+#             */
/*   Updated: 2023/02/11 18:52:14 by nikoraxx         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "heads/Bureaucrat.hpp"
#include "heads/Form.hpp"

int	main(void)
{
	Form		newForm("Price sheet", 3, 25);
	Bureaucrat	Josh("Josh", 2);

	std::cout << newForm;

	std::cout << "\t----\n";

	Josh.signForm(newForm);
	Josh.signForm(newForm);
	
	std::cout << "\t----\n";

	std::cout << newForm;

	Form		randomForm("Random sh*t", 45, 145);
	Bureaucrat	Timmy("Timmy", 145);

 	Timmy.signForm(randomForm);

	// for (int i = 0; i < 5; i++)
	// 	Timmy.signForm(randomForm);
}