/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spitul <spitul@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 17:12:54 by spitul            #+#    #+#             */
/*   Updated: 2025/06/23 08:17:42 by spitul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

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

		std::string	getNameForm() const;
		bool	getSigned();
		unsigned int	getSignGrade() const;
		unsigned int	getExecGrade() const;

		void	beSigned(Bureaucrat &b);
