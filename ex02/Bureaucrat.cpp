/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spitul <spitul@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 21:39:29 by spitul            #+#    #+#             */
/*   Updated: 2025/06/30 07:27:10 by spitul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <iostream>

Bureaucrat::Bureaucrat(void)	: _name("default"), _grade(LOWEST_GR)
{
}

Bureaucrat::Bureaucrat(std::string name, unsigned int grade)	: _name(name)
{
	if (grade > LOWEST_GR)
		throw GradeTooLowException();
	if (grade < HIGHEST_GR)
		throw GradeTooHighException();
	_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)	: _name(other._name), _grade(other._grade)
{
}
		
Bureaucrat&	Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
	{
		_grade = other._grade;
	}
	return *this;
}

Bureaucrat::~Bureaucrat(void)
{
}

const std::string	Bureaucrat::getName(void) const
{
	return this->_name;
}
unsigned int	Bureaucrat::getGrade(void) const
{
	return this->_grade;
}

void	Bureaucrat::incrementGrade(void)
{
	if (_grade == 1)
		throw Bureaucrat::GradeTooHighException();
	_grade --;
}

void	Bureaucrat::decrementGrade(void)
{
	if (_grade == 150)
		throw Bureaucrat::GradeTooLowException();
	_grade ++;
}

const char	*Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Exception: Grade too high";
}


const char	*Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Exception: Grade too low";
}

std::ostream	&operator<<(std::ostream &out, Bureaucrat const &other)
{
	out << other.getName() << ", bureaucrat grade: " << other.getGrade() << std::endl;
	return out;
}

void	Bureaucrat::executeForm(AForm const & form)
{
	try
	{
		form.execute(*this);
	}
	catch(AForm::GradeTooLowException &e)
	{
		std::cout << *this << "\n: grade does not authorize them to execute " << form.getNameForm() 
		<< "." << e.what() << std::endl;
	}
	catch(AForm::FormUnsignedException &e)
	{
		std::cout << form.getNameForm() << "is unsigned. Execution not possible without signiture:" 
		<< e.what() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
