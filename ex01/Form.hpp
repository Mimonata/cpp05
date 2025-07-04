/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spitul <spitul@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 17:13:11 by spitul            #+#    #+#             */
/*   Updated: 2025/06/25 07:30:18 by spitul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>

class Bureaucrat;

class AForm
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
		AForm(std::string formName, unsigned int signGrade, unsigned int execGrade);
		~AForm();
		AForm& operator=(const AForm &other);
		AForm(const AForm &other);

		std::string	getNameForm() const;
		bool	getSigned() const;
		unsigned int	getSignGrade() const;
		unsigned int	getExecGrade() const;

		void	beSigned(Bureaucrat &b);

		class GradeTooLowException	: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class GradeTooHighException	:public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};
};

std::ostream	&operator<<(std::ostream &out, const AForm &form);

#endif
