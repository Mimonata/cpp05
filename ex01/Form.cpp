/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spitul <spitul@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 17:12:54 by spitul            #+#    #+#             */
/*   Updated: 2025/06/24 08:24:19 by spitul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(std::string formName, unsigned int signGrade, unsigned int execGrade)
	: _name(formName), _signGrade(signGrade), _execGrade(execGrade), _signed(false)
{
	if (_signGrade > lowestGrade || _execGrade > lowestGrade)
		throw GradeTooLowException();
	else if (_signGrade < highestGrade || _execGrade < highestGrade)
		throw GradeTooHighException();
}

Form::~Form()
{
}

Form& Form::operator=(const Form &other)
{
	if (this != &other)
	{
		_signed = other._signed; // ??
	}
	return *this;
}
	
Form::Form(const Form &other)
	: _name(other._name), _signed(other._signed), _signGrade(other._signGrade), _execGrade(other._execGrade)
{
	
}

std::string	Form::getNameForm() const
{
	return _name;
}

bool	Form::getSigned()
{
	return _signed;
}

unsigned int	Form::getSignGrade() const
{
	return _signGrade;
}

unsigned int	Form::getExecGrade() const
{
	return _execGrade;
}

void	Form::beSigned(Bureaucrat &b)
{
	if (_signGrade >= b.getGrade())
		_signed = true;
	else
		throw GradeTooLowException();
}

std::ostream	&operator<<(std::ostream &out, Form &form)
{
	out << "Form " << form.getNameForm() << "requires the grades:\n\t" 
	<< form.getSignGrade() << " for signing\n\t" << form.getExecGrade() << " for execution.";
	if (form.getSigned())
		out << "\nIs signed";
	else
		out << "\n Is unsigned";
}
