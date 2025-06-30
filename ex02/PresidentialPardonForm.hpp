/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spitul <spitul@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 16:29:33 by spitul            #+#    #+#             */
/*   Updated: 2025/06/30 07:32:16 by spitul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

#include <string>

class PresidentialPardonForm	: public AForm
{
	private:
		enum
		{
			_SIGNGRADE = 25,
			_EXECGRADE = 5
		};
		std::string	_target;
		
	public:
			PresidentialPardonForm(std::string target);
			~PresidentialPardonForm();
			PresidentialPardonForm(PresidentialPardonForm &other);
			PresidentialPardonForm&	operator=(PresidentialPardonForm &other);

			void execute(Bureaucrat const & executor) const;
};

#endif
