/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spitul <spitul@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 18:14:27 by spitul            #+#    #+#             */
/*   Updated: 2025/06/30 23:35:34 by spitul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>
#include <stdexcept>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target)	:
	AForm("ShrubberyCreationForm", _SIGNGRADE, _EXECGRADE), _target(target)
{
	
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm &other)	:
	AForm(other), _target(other._target)
{
	
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(ShrubberyCreationForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		_target = other._target;
	}
	return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	AForm::execute(executor);
	std::string	outName = _target + "_shrubbery";
	std::ofstream outfile(outName.c_str());
	if (!outfile.is_open())
		throw std::runtime_error("Error: file" + outName + "cannot be opened");
	
	drawShrub(outfile);
	
	if (!outfile.good())
	{
		outfile.close();
		throw std::runtime_error("Error: file " + outName + " corrupted");
	}
	outfile.close();
	std::cout << GRY << executor.getName() << " executed " << this->getNameForm()
		<< RST << std::endl; 
}

void	ShrubberyCreationForm::drawShrub(std::ofstream &outfile) const
{
	outfile << "\n               .     .  .    +     .      .          ." << std::endl;
    outfile << "         .       .      .   \"#\"       .           ." << std::endl;
    outfile << "            .      .       \"###\"           .      .      ." << std::endl;
    outfile << "          .      .   \"#:. .:##\"##:. .:#\"  .      ." << std::endl;
    outfile << "              .      . \"####\"###\"####\"  ." << std::endl;
    outfile << "           .     \"#:.    .:#\"###\"#:.    .:#\"  .        .       ." << std::endl;
    outfile << "     .             \"#########\"#########\"        .        ." << std::endl;
    outfile << "           .    \"#:.  \"####\"###\"####\"  .:#\"   .       ." << std::endl;
    outfile << "        .     .  \"#######\"\"##\"##\"\"#######\"                  ." << std::endl;
    outfile << "                .\"##\"#####\"#####\"##\"           .      ." << std::endl;
    outfile << "        .   \"#:. ...  .:##\"###\"###\"##:.  ... .:#\"     ." << std::endl;
    outfile << "          .     \"#######\"##\"#####\"##\"#######\"      .     ." << std::endl;
    outfile << "        .    .     \"#####\"\"#######\"\"#####\"    .      ." << std::endl;
    outfile << "                .     \"      000      \"    .     ." << std::endl;
    outfile << "           .         .   .   000     .        .       ." << std::endl;
    outfile << "   .. .. ..................O000O........................ ...... ..." << std::endl;
}
