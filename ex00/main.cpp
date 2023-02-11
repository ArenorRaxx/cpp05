/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikoraxx <nikoraxx@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 20:38:02 by nikoraxx          #+#    #+#             */
/*   Updated: 2023/02/11 14:51:57 by nikoraxx         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "heads/Bureaucrat.hpp"

int	main(void)
{
	try {
		Bureaucrat	Jean("Jean", -1);
	} catch (std::exception &error) {
		std::cout << "Exception: " << error.what();
	}

	try {
		Bureaucrat	Jeanne("Jeanne", 167);
	} catch (std::exception &error) {
		std::cout << "Exception: " << error.what();
	}
	
	std::cout << "\t----\n";
	
	Bureaucrat Jean("Jean", 5);
	Bureaucrat Jeanne("Jeanne", 145);
	
	std::cout << "\t----\n";
	
	try {
		for (int i = 0; i < 10; i++)
			++Jean;
	} catch (std::exception &error) {
		std::cout << "Exception: " << error.what();
	}

	try {
		for (int i = 0; i < 10; i++)
			--Jeanne;
	} catch (std::exception &error) {
		std::cout << "Exception: " << error.what();
	}

	std::cout << Jean;
	std::cout << Jeanne;

	std::cout << "\t----\n";
}