/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spitul <spitul@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 16:29:02 by spitul            #+#    #+#             */
/*   Updated: 2025/06/30 07:32:09 by spitul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string target)	:
	AForm("PresidentialPardonForm", _SIGNGRADE, _EXECGRADE), _target(target)
{
	
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &other)	:
	AForm(other), _target(other._target)
{
	
}

PresidentialPardonForm&	PresidentialPardonForm::operator=(PresidentialPardonForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		_target = other._target;
	}
	return *this;
}

void	PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
	std::cout << _target + " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
