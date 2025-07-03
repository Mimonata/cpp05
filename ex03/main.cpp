/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spitul <spitul@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 21:35:35 by spitul            #+#    #+#             */
/*   Updated: 2025/07/03 18:39:06 by spitul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <iostream>

int	main(void)
{
	Intern Maria;
	AForm	*r;
	Bureaucrat	b("Olle", 1);
	
	r = Maria.makeForm("shrubbery creation", "garden");
	if (r != NULL)
	{
		try
		{
			r->execute(b);
		}
		catch(const AForm::FormUnsignedException& e)
		{
			std::cerr << e.what() << '\n';
		}
		
		
		r->beSigned(b);
		r->execute(b);
		delete (r);
	}
	r = Maria.makeForm("robotomy request", "Harzer str");
	if (r != NULL)
	{
		//r->execute(b);
		r->beSigned(b);
		r->execute(b);
		delete (r);
	}
	r = Maria.makeForm("test", "mars");
	if (r == NULL)
		std::cout << "Form NULL" << std::endl;
	return 0;
}
