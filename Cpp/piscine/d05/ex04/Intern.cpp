/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 21:30:56 by tbehra            #+#    #+#             */
/*   Updated: 2019/05/27 21:47:57 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

Intern::Intern(void) {

}
Intern::~Intern(void) {

}

Form *Intern::makeForm(std::string formName, std::string formTarget) {
	Form *ret = NULL;

	if (formName == "ShrubberyCreationForm") 
		ret = new ShrubberyCreationForm(formTarget);
	if (formName == "PresidentialPardonForm") 
		ret = new PresidentialPardonForm(formTarget);
	if (formName == "RobotomyRequestForm") 
		ret = new RobotomyRequestForm(formTarget);
	if (ret)
		std::cout << "Intern creates " << formName << " on " << formTarget << std::endl;
	else
		std::cout << "The intern looked everywhere in the cellar, he couldn't find any form named " << formName << std::endl;
	return (ret);
}
