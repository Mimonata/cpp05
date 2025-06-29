/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spitul <spitul@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 16:28:23 by spitul            #+#    #+#             */
/*   Updated: 2025/06/29 20:42:42 by spitul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

bool	RobotomyRequestForm::_lastExec = 0;

RobotomyRequestForm::RobotomyRequestForm(const std::string target)	:
	AForm("RobotomyRequestForm", _SIGNGRADE, _EXECGRADE), _target(target)
{
	
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm &other)	:
	AForm(other), _target(other._target)
{
	
}

RobotomyRequestForm&	RobotomyRequestForm::operator=(RobotomyRequestForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		_target = other._target;
	}
	return *this;
}

/*Required grades: sign 72, exec 45
Makes some drilling noises, then informs that <target> has been robotomized
successfully 50% of the time. Otherwise, it informs that the robotomy failed.*/

void RobotomyRequestForm::execute(Bureaucrat const & executor)
{
	AForm::execute(executor);
	if (_lastExec)
	{
		std::cout << "NGGrrrRRRRrrrrr RRrrrrRRrrr" << std::endl;
		std::cout << _target + " has been robotomized successfully" << std::endl;
	}
	else 
		std::cout << _target + " robotomization failed" << std::endl;
	_lastExec = !_lastExec;
}
