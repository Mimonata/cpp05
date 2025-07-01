/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spitul <spitul@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 23:46:22 by spitul            #+#    #+#             */
/*   Updated: 2025/06/30 23:52:32 by spitul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>

#include "AForm.hpp"

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
