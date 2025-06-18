/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucreat.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spitul <spitul@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 21:35:44 by spitul            #+#    #+#             */
/*   Updated: 2025/06/18 21:43:30 by spitul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCREAT_HPP
#define BUREAUCREAT_HPP

#include <string>

class Bureaucreat
{
	private:
		const std::string	_name;
		unsigned int	_grade;

	public:
		Bureaucreat (unsigned int grade);
		Bureaucreat (Bureaucreat &other);
		Bureaucreat&	operator=(Bureaucreat &other);
		~Bureaucreat(void);

		const std::string	getName(void);
		unsigned int	getGrade(void);

		void	incrementGrade(void);
		void	decrementGrade(void);

		void	operator<<();
};

#endif
