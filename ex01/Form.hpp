/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spitul <spitul@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 17:13:11 by spitul            #+#    #+#             */
/*   Updated: 2025/06/23 08:14:37 by spitul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>

class Bureaucrat;

class Form
{
	private:
		enum
		{
			highestGrade = 1,
			lowestGrade = 150
		};
		const std::string	_name;
		bool				_signed;
		const unsigned int	_signGrade;
		const unsigned int 	_execGrade;
		
	public:
		Form(std::string formName, unsigned int signGrade, unsigned int execGrade);
		~Form();
		Form& operator=(const Form &other);
		Form(const Form &other);

		std::string	getNameForm() const;
		bool	getSigned();
		unsigned int	getSignGrade() const;
		unsigned int	getExecGrade() const;

		void	beSigned(Bureaucrat &b);

		class GradeTooLowException	: public std::exception
		{
			virtual const char *what() const throw();
		};

		class GradeTooHighException	:public std::exception
		{
			virtual const char	*what() const throw();
		};
};

std::ostream	&operator<<(std::ostream &out, Form &form);

#endif
