/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucreat.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spitul <spitul@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 21:35:44 by spitul            #+#    #+#             */
/*   Updated: 2025/06/19 21:34:53 by spitul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCREAT_HPP
#define BUREAUCREAT_HPP

#define	HIGHEST_GR 1
#define LOWEST_GR 150

#include <string>

class Bureaucreat
{
	private:
		const std::string	_name;
		unsigned int	_grade;

	public:
		Bureaucreat (std::string name, unsigned int grade);
		Bureaucreat (Bureaucreat &other);
		Bureaucreat&	operator=(Bureaucreat &other);
		~Bureaucreat(void);

		const std::string	getName(void);
		unsigned int	getGrade(void);

		void	incrementGrade(void);
		void	decrementGrade(void);

		class	GradeTooHighException	: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class	GradeTooLowException	: public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};
};

std::ostream	operator<<(std::ostream &out, Bureaucreat const &other);

#endif
