/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spitul <spitul@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 21:35:35 by spitul            #+#    #+#             */
/*   Updated: 2025/06/25 07:32:59 by spitul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

#include <iostream>

int	main(void)
{
	try
	{
		AForm	a("ZN25", 160, 4);
	}
	catch(AForm::GradeTooHighException& e)
	{
		std::cerr << ABG << e.what() << std::endl;
	}
	catch(AForm::GradeTooLowException& e)
	{
		std::cerr << ABG << e.what() << std::endl;
	}
	try
	{
		Bureaucrat	b("Ret", 45);
		AForm	f("SB23", 70, 70);
		std::cout << f << std::endl;
		f.beSigned(b);
		std::cout << f << std::endl;
	}
	catch(Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << ABG << e.what() << std::endl;
	}
	catch(Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << ABG << e.what() << std::endl;
	}
	
	
	
	Bureaucrat	c("Norman", 3);
	std::cout << ORG << c;
	
	try
	{
		c.incrementGrade();
		std::cout << EMG << c;
		c.incrementGrade();
		std::cout << EMG << c;
		c.incrementGrade();
		std::cout << EMG << c;
	}
	catch(Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << ABG << e.what() << std::endl;
	}
	catch(Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << ABG << e.what() << std::endl;
	}
	
	return 0;
}
