/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 13:24:24 by tbehra            #+#    #+#             */
/*   Updated: 2019/05/27 15:55:22 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(std::string name, unsigned int gradeSign, unsigned int gradeExecute) :
   	_name(name),
	_signed(false),
	_gradeSign(gradeSign),
	_gradeExecute(gradeExecute) {
	if (this->_gradeSign > 150 || this->_gradeExecute > 150)
		throw Form::GradeTooLowException();
	if (this->_gradeSign <= 0 || this->_gradeExecute <= 0)
		throw Form::GradeTooHighException();
}

Form::~Form(void) {

}

std::ostream & operator<<(std::ostream & o, Form const & f) {
	o << "Form " << f.getName() << ", " << ((f.getSigned()) ? "signed" : "unsigned")
	   	<< ", grade to sign: " << f.getGradeSign() << ", grade to execute: "
		<< f.getGradeExecute() << std::endl;
	return o;
}

std::string Form::getName() const {
	return this->_name;
}
bool Form::getSigned() const {
	return this->_signed;
}
unsigned int Form::getGradeSign() const {
	return this->_gradeSign;
}
unsigned int Form::getGradeExecute() const {
	return this->_gradeExecute;
}

void Form::beSigned(Bureaucrat const & b) {
	if (b.getGrade() > this->_gradeSign) {
		throw Form::GradeTooLowException();
	}
	else {
		this->_signed = true;
	}
}
