/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 12:09:27 by tbehra            #+#    #+#             */
/*   Updated: 2019/05/27 13:19:36 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"


int main(void) {
	Bureaucrat *Francis = new Bureaucrat("Francis", 10);

	std::cout << *Francis;
	try {
		Bureaucrat *Bernard = new Bureaucrat("Bernard", 0);
		std::cout << *Bernard;
	}
	catch(Bureaucrat::GradeTooHighException & e) {
		std::cout << "Could not create the bureaucrat: "<< e.what() << std::endl;
	}
	catch(Bureaucrat::GradeTooLowException & e) {
		std::cout << "Could not create the bureaucrat: "<< e.what() << std::endl;
	}

	try {
		Bureaucrat *Grou = new Bureaucrat("grou", 151);
		std::cout << *Grou;
	}
	catch(Bureaucrat::GradeTooHighException & e) {
		std::cout << "Could not create the bureaucrat: "<< e.what() << std::endl;
	}
	catch(Bureaucrat::GradeTooLowException & e) {
		std::cout << "Could not create the bureaucrat: "<< e.what() << std::endl;
	}


	int i = 0;
	while (i < 100) {
		try {
			Francis->incrementGrade();
			std::cout << *Francis;
		}
		catch(Bureaucrat::GradeTooHighException & e) {
			std::cout << "Fail after increment: " << e.what() << std::endl;
			Francis->decrementGrade();
			break;
		}
		i++;
	}

	delete Francis;
}
