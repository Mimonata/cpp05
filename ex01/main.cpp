/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spitul <spitul@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 21:35:35 by spitul            #+#    #+#             */
/*   Updated: 2025/06/24 08:26:27 by spitul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

#include <iostream>

int	main(void)
{
	try
	{
		Form	a("ZN25", 160, 4);
	}
	catch(Form::GradeTooHighException& e)
	{
		std::cerr << ABG << e.what() << std::endl;
	}
	catch(Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << ABG << e.what() << std::endl;
	}
	try
	{
		Bureaucrat	b("Ret", 0);
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
