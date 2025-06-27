/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spitul <spitul@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 07:42:02 by spitul            #+#    #+#             */
/*   Updated: 2025/06/26 17:54:12 by spitul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

#include <string>

class ShrubberyCreationForm	: public AForm
{
	private:
		enum
		{
			_SIGNGRADE = 145,
			_EXECGRADE = 137
		};
	public:
			ShrubberyCreationForm();
			~ShrubberyCreationForm();
			ShrubberyCreationForm(ShrubberyCreationForm &other);
			ShrubberyCreationForm&	operator=(ShrubberyCreationForm &other);
};


#endif
