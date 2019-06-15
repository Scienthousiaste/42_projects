/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 13:24:24 by tbehra            #+#    #+#             */
/*   Updated: 2019/05/27 21:23:17 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(std::string name, unsigned int gradeSign, unsigned int gradeExecute,
		std::string target) :
   	_name(name),
	_signed(false),
	_gradeSign(gradeSign),
	_gradeExecute(gradeExecute),
	_target(target){
	if (this->_gradeSign > 150 || this->_gradeExecute > 150)
		throw Form::GradeTooLowException();
	if (this->_gradeSign <= 0 || this->_gradeExecute <= 0)
		throw Form::GradeTooHighException();
}

Form::~Form(void) {

}

std::ostream & operator<<(std::ostream & o, Form const & f) {
	o << f.getName() << " form." << std::endl
		<< ((f.getSigned()) ? "Signed" : "Unsigned") << std::endl
	   	<< "Grade to sign: " << f.getGradeSign() << std::endl
		<< "Grade to execute: " << f.getGradeExecute() << std::endl
		<< "Target: " << f.getTarget() << std::endl;
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
const std::string Form::getTarget() const {
	return this->_target;
}

void Form::beSigned(Bureaucrat const & b) {
	if (b.getGrade() > this->_gradeSign) {
		throw Form::GradeTooLowException();
	}
	else {
		this->_signed = true;
	}
}

void Form::checkExecution(Bureaucrat const & b) const {
	if (!(this->_signed)) {
		throw Form::UnsignedFormException();
	}
	if (b.getGrade() > this->_gradeExecute) {
		throw Form::GradeTooLowException();
	}
}
