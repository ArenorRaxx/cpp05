/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikoraxx <nikoraxx@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 19:07:14 by nikoraxx          #+#    #+#             */
/*   Updated: 2023/02/11 19:22:14 by nikoraxx         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include <string>
#include "Form.hpp"

class PresidentialPardonForm: public Form
{
	public:
	//	Constructors

		PresidentialPardonForm(void);
		PresidentialPardonForm(PresidentialPardonForm const&);
		PresidentialPardonForm(std::string const&);
	
	//	Destructor
	
		~PresidentialPardonForm(void);

	//	Operators

		PresidentialPardonForm &operator = (PresidentialPardonForm const&);
		
	//	Methods

		void execute(Bureaucrat const&) const;
};

#endif