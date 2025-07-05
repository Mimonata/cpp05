/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spitul <spitul@student.42berlin.de >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 21:35:35 by spitul            #+#    #+#             */
/*   Updated: 2025/07/05 14:39:22 by spitul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <iostream>

int	main(void)
{
	Intern Ferrie;
	AForm	*r;
	Bureaucrat	b("Olle", 1);
	
	r = Ferrie.makeForm("shrubbery creation", "garden");
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
		catch(const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
		
		r->beSigned(b);
		r->execute(b);
		delete (r);
	}
	r = Ferrie.makeForm("robotomy request", "Harzer str");
	if (r != NULL)
	{
		r->beSigned(b);
		r->execute(b);
		delete (r);
	}
	r = Ferrie.makeForm("test", "mars");
	if (r == NULL)
		std::cout << "Form NULL" << std::endl;
	return 0;
}
