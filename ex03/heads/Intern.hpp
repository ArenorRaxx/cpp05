/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikoraxx <nikoraxx@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 23:33:22 by nikoraxx          #+#    #+#             */
/*   Updated: 2023/02/12 00:04:22 by nikoraxx         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include <iostream>
#include <string>
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
	private:
		static std::string const	_name_of_form[3];
	public:
		Intern(void);
		Intern(Intern const&);

		Intern &operator = (Intern const&);
		
		~Intern(void);

	//	Methods
		Form	*makeForm(std::string const&, std::string const&);
};

#endif