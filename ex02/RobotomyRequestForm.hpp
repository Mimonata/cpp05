/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spitul <spitul@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 16:26:48 by spitul            #+#    #+#             */
/*   Updated: 2025/06/29 20:35:02 by spitul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

#include <string>

class RobotomyRequestForm	: public AForm
{
	private:
		enum
		{
			_SIGNGRADE = 72,
			_EXECGRADE = 45
		};
		std::string	_target;

		static bool	_lastExec;
		
	public:
			RobotomyRequestForm(std::string target);
			~RobotomyRequestForm();
			RobotomyRequestForm(RobotomyRequestForm &other);
			RobotomyRequestForm&	operator=(RobotomyRequestForm &other);

			void execute(Bureaucrat const & executor);
};

#endif
