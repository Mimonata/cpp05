/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spitul <spitul@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 21:35:35 by spitul            #+#    #+#             */
/*   Updated: 2025/06/21 14:56:17 by spitul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

#include <iostream>

int	main(void)
{
	try
	{
		Bureaucrat	a("Ret", 160);
	}
	catch(Bureaucrat::GradeTooHighException& e)
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
