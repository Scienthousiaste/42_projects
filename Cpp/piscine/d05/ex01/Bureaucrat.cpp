/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 11:42:53 by tbehra            #+#    #+#             */
/*   Updated: 2019/05/27 16:01:51 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"



Bureaucrat::Bureaucrat(std::string name, unsigned int grade) : _name(name) {
	if (grade <= 0)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade = grade;
}

Bureaucrat::~Bureaucrat(void) {

}

void Bureaucrat::incrementGrade(void) {
	this->_grade--;
	if (this->_grade <= 0)
		throw Bureaucrat::GradeTooHighException();
}
void Bureaucrat::decrementGrade(void) {
	this->_grade++;
	if (this->_grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

std::ostream & operator<<(std::ostream & o, Bureaucrat const & b) {
	o << b.getName() << ", bureaucrat grade " << b.getGrade() << std::endl;
	return o;
}

std::string Bureaucrat::getName() const {
	return this->_name;
}
unsigned int Bureaucrat::getGrade() const {
	return this->_grade;
}

void Bureaucrat::signForm(Form & toSign) const {
	try {
		toSign.beSigned(*this);
		std::cout << this->_name << " signs " << toSign.getName() << std::endl;
	}	
	catch (std::exception & e) {
		std::cout << this->_name << " cannot sign " << toSign.getName()
			<< " because " << e.what() << std::endl;
	}
}
