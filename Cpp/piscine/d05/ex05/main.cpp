/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 12:09:27 by tbehra            #+#    #+#             */
/*   Updated: 2019/05/28 10:07:52 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "OfficeBlock.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

void tryBureaucracy(OfficeBlock & o, std::string s1, std::string s2) {
	try {
		o.doBureaucracy(s1, s2);
	}
	catch (std::exception e) {
		std::cout << e.what();
	}
}

int main(void) {
	OfficeBlock o1;
	Bureaucrat *Francis = new Bureaucrat("Francis", 10);
	Bureaucrat *Fabienne = new Bureaucrat("Fabienne", 149);
	Bureaucrat *Chef = new Bureaucrat("Chef", 2);
	Intern *i = new Intern();
	OfficeBlock *o2 = new OfficeBlock(i, Francis, Chef);
	

	tryBureaucracy(*o2, "ShrubberyCreationForm", "Polygencil");

	tryBureaucracy(*o2, "PresidentialPardonForm", "Martin Shkrely"); 
	o1.setIntern(new Intern());
	o1.setSigner(Fabienne);
	o1.setExecutor(Chef);

	tryBureaucracy(o1, "RobotomyRequestForm", "Martin Shrely");
	tryBureaucracy(o1, "RobotomyRequestForm", "BisouX");

	delete o2;
	delete Francis;
	delete Fabienne;
	delete Chef;
	delete i;
}

