/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spitul <spitul@student.42berlin.de >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 17:12:54 by spitul            #+#    #+#             */
/*   Updated: 2025/06/29 16:56:29 by spitul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(std::string formName, unsigned int signGrade, unsigned int execGrade)
	: _name(formName), _signed(false), _signGrade(signGrade), _execGrade(execGrade)
{
	if (_signGrade > lowestGrade || _execGrade > lowestGrade)
		throw GradeTooLowException();
	else if (_signGrade < highestGrade || _execGrade < highestGrade)
		throw GradeTooHighException();
}

AForm::~AForm()
{
}

AForm& AForm::operator=(const AForm &other)
{
	if (this != &other)
	{
		_signed = other._signed; // ??
	}
	return *this;
}
	
AForm::AForm(const AForm &other)
	: _name(other._name), _signed(other._signed), _signGrade(other._signGrade), _execGrade(other._execGrade)
{
	
}

std::string	AForm::getNameForm() const
{
	return _name;
}

bool	AForm::getSigned() const
{
	return _signed;
}

unsigned int	AForm::getSignGrade() const
{
	return _signGrade;
}

unsigned int	AForm::getExecGrade() const
{
	return _execGrade;
}

void	AForm::beSigned(Bureaucrat &b)
{
	if (_signGrade >= b.getGrade())
		_signed = true;
	else
		throw GradeTooLowException();
}

std::ostream	&operator<<(std::ostream &out, AForm &form)
{
	out << "Form " << form.getNameForm() << " requires the grades:\n\t" 
	<< form.getSignGrade() << " for signing\n\t" << form.getExecGrade() << " for execution.";
	if (form.getSigned())
		out << "\nForm is signed";
	else
		out << "\nForm is unsigned";
	return out;
}

const char	*AForm::GradeTooHighException::what() const throw()
{
	return "Exception: grade too high";
}

const char	*AForm::GradeTooLowException::what() const throw()
{
	return "Exception: grade too low";
}

const char	*AForm::FormUnsignedException::what() const throw()
{
	return "Exception: form unsigned";
}

void AForm::execute(Bureaucrat const & executor)
{
	if (!_signed)
		throw FormUnsignedException();
	if (executor.getGrade() > _execGrade)
		throw GradeTooLowException();
}
