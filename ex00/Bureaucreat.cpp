/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucreat.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spitul <spitul@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 21:39:29 by spitul            #+#    #+#             */
/*   Updated: 2025/06/19 21:37:57 by spitul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucreat.hpp"

Bureaucreat::Bureaucreat(std::string name, unsigned int grade)	: _name(name)
{
	if (grade > LOWEST_GR)
		throw GradeTooLowException();
	if (grade < HIGHEST_GR)
		throw GradeTooHighException();
	_grade = grade;
}

Bureaucreat::Bureaucreat(Bureaucreat &other)	: _grade(other._grade)
{
}
		Bureaucreat&	operator=(Bureaucreat &other);
		~Bureaucreat(void);

		const std::string	getName(void);
		unsigned int	getGrade(void);

		void	incrementGrade(void);
		void	decrementGrade(void);

