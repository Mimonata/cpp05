/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spitul <spitul@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 23:46:22 by spitul            #+#    #+#             */
/*   Updated: 2025/07/02 20:23:46 by spitul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>

class AForm;

class Intern
{
private:
	/* data */
public:
	Intern();
	~Intern();
	Intern	&operator=(const Intern &other);
	Intern(const Intern &other);

	AForm	*makeForm(std::string formName, std::string target);
};

#endif
