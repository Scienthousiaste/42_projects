/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 12:09:27 by tbehra            #+#    #+#             */
/*   Updated: 2019/05/27 21:47:56 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"


void tryExec(Bureaucrat *b, Form *f) {
	b->executeForm(*f);
}	

void trySign(Bureaucrat *b, Form *f) {
	b->signForm(*f);
}	

int main(void) {
	Bureaucrat *Francis = new Bureaucrat("Francis", 10);
	Bureaucrat *Fabienne = new Bureaucrat("Fabienne", 149);
	Bureaucrat *Chef = new Bureaucrat("Chef", 2);
	

	Intern *i = new Intern();

	Form *f  = i->makeForm("ShrubberyCreationForm", "Polygencil");
	
 	Form *p = i->makeForm("PresidentialPardonForm", "Martin Shkrely"); 
	Form *ro = i->makeForm("RobotomyRequestForm", "Igrochka");

	tryExec(Francis, f);
	trySign(Fabienne, f);
	trySign(Francis, f);
	tryExec(Fabienne, f);
	tryExec(Francis, f);
	
	trySign(Francis, p);
	tryExec(Francis, p);
	tryExec(Chef, p);
	trySign(Chef, ro);
	tryExec(Chef, ro);
	tryExec(Fabienne, ro);
	tryExec(Chef, ro);
	tryExec(Chef, ro);

	delete f;
	delete p;
	delete ro;
	delete Francis;
	delete Fabienne;
	delete Chef;
	delete i;
}

