/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikoraxx <nikoraxx@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 19:07:14 by nikoraxx          #+#    #+#             */
/*   Updated: 2023/02/11 19:22:14 by nikoraxx         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include <string>
#include "Form.hpp"

class RobotomyRequestForm: public Form
{
	private:
		static	bool	_coin;
		static	void	_flip_coin(void);
	public:
	//	Constructors

		RobotomyRequestForm(void);
		RobotomyRequestForm(RobotomyRequestForm const&);
		RobotomyRequestForm(std::string const&);
	
	//	Destructor
	
		~RobotomyRequestForm(void);

	//	Operators

		RobotomyRequestForm &operator = (RobotomyRequestForm const&);
		
	//	Methods

		void execute(Bureaucrat const&) const;
};

#endif