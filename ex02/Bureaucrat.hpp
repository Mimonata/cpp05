/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spitul <spitul@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 21:35:44 by spitul            #+#    #+#             */
/*   Updated: 2025/06/29 20:57:36 by spitul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#define GRY "\033[38;5;67m"
#define SGG "\033[38;2;157;193;131m" // sage green
#define MVP "\033[38;2;224;176;255m"
#define ABG "\033[38;2;169;92;104m"
#define PBL "\033[38;2;125;127;255m"
#define ORG "\033[38;2;255;140;0m"
#define EMG "\033[38;2;80;200;120m"

#define	HIGHEST_GR 1
#define LOWEST_GR 150

#include <string>

class AForm;

class Bureaucrat
{
	private:
		const std::string	_name;
		unsigned int	_grade;

	public:
		Bureaucrat (void);
		Bureaucrat (std::string name, unsigned int grade);
		Bureaucrat (const Bureaucrat &other);
		Bureaucrat&	operator=(const Bureaucrat &other);
		~Bureaucrat(void);

		const std::string	getName(void) const;
		unsigned int	getGrade(void) const;

		void	incrementGrade(void);
		void	decrementGrade(void);

		void	executeForm(AForm const & form);

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

std::ostream	&operator<<(std::ostream &out, Bureaucrat const &other);

#endif
