/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spitul <spitul@student.42berlin.de >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 07:42:02 by spitul            #+#    #+#             */
/*   Updated: 2025/06/29 17:37:55 by spitul           ###   ########.fr       */
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
		std::string	_target;
		
	public:
			ShrubberyCreationForm(std::string target);
			~ShrubberyCreationForm();
			ShrubberyCreationForm(ShrubberyCreationForm &other);
			ShrubberyCreationForm&	operator=(ShrubberyCreationForm &other);

			void execute(Bureaucrat const & executor);

			void	drawShrub(std::ofstream &outfile);
};


#endif
