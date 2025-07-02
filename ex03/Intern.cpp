/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spitul <spitul@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 23:48:17 by spitul            #+#    #+#             */
/*   Updated: 2025/07/02 21:24:15 by spitul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <cctype>

Intern::Intern(/* args */)
{
}

Intern::~Intern()
{
}

Intern&	Intern::operator=(const Intern &other)
{
	(void)other;
	return *this;
}

Intern::Intern(const Intern &other)
{
	(void)other;
}

AForm*	Intern::makeForm(std::string formName, std::string target)
{
	std::string	formType[] = 
		{"presidential pardon", "robotomy request", "shrubbery creation"};
	int	j = 0;
		
	for (size_t i = 0; i < formName.length(); i ++)
		std::tolower(formName[i]);
		
	while(j < 3)
	{
		if (formName.compare(formType[j]) == 0)
			break;
		j ++;
	}
	
	switch (j)
	{
		case 0:
			std::cout << "\033[38;2;169;92;104mIntern creates shrubbery creation form\033[0m" << std::endl;
			return new ShrubberyCreationForm(target);
		case 1:
			std::cout << "\033[38;2;169;92;104mIntern creates robotomy request form\033[0m" << std::endl;
			return new RobotomyRequestForm(target);
		case 2:
			std::cout << "\033[38;2;169;92;104mIntern creates presidential pardon form\033[0m" << std::endl;
			return new PresidentialPardonForm(target);
		default:
			std::cout << "Form unexistent" << std::endl;
			return NULL;
	}
	 
}
