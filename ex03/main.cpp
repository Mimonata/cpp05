/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spitul <spitul@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 21:35:35 by spitul            #+#    #+#             */
/*   Updated: 2025/06/30 23:29:32 by spitul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

#include <iostream>

int	main(void)
{
	AForm					*a = new ShrubberyCreationForm("garden");
	ShrubberyCreationForm	b("home");
	PresidentialPardonForm	pres("fine");
	RobotomyRequestForm		robo("book");
	Bureaucrat	mimo("Mimo", 3);
	Bureaucrat	olaf("Olaf", 40);
	
	mimo.executeForm(b);
	b.beSigned(olaf);
	mimo.executeForm(b);
	olaf.executeForm(pres);
	(*a).beSigned(mimo);
	mimo.executeForm(*a);
	pres.beSigned(mimo);
	robo.beSigned(mimo);
	mimo.executeForm(robo);
	olaf.executeForm(pres);
	olaf.executeForm(robo);
	mimo.executeForm(pres);
	
	delete a;
	return 0;
}
