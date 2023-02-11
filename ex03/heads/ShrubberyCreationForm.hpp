/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikoraxx <nikoraxx@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 19:07:14 by nikoraxx          #+#    #+#             */
/*   Updated: 2023/02/11 22:30:35 by nikoraxx         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include <fstream>
#include <string>
#include "Form.hpp"

class ShrubberyCreationForm: public Form
{
	private:
		void	_createShrubbery(void) const;
	public:
	//	Constructors

		ShrubberyCreationForm(void);
		ShrubberyCreationForm(ShrubberyCreationForm const&);
		ShrubberyCreationForm(std::string const&);
	
	//	Destructor
	
		~ShrubberyCreationForm(void);

	//	Operators

		ShrubberyCreationForm &operator = (ShrubberyCreationForm const&);
		
	//	Methods

		void execute(Bureaucrat const&) const;
};

#endif