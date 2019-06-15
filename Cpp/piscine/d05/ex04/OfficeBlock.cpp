/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OfficeBlock.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 22:00:48 by tbehra            #+#    #+#             */
/*   Updated: 2019/05/28 10:06:08 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "OfficeBlock.hpp"



OfficeBlock::OfficeBlock(Intern *intern, Bureaucrat *b1, Bureaucrat *b2) :
	_intern(intern), _b1(b1), _b2(b2) {
}


OfficeBlock::OfficeBlock(void) :
	_intern(NULL), _b1(NULL), _b2(NULL) {
}

OfficeBlock::~OfficeBlock() {

}

void	OfficeBlock::setIntern(Intern *i) {
	this->_intern = i;
}
void	OfficeBlock::setSigner(Bureaucrat *b) {
	this->_b1 = b;
}
void	OfficeBlock::setExecutor(Bureaucrat *b) {
	this->_b2 = b;
}

void 	OfficeBlock::doBureaucracy(std::string formName, std::string target) const {
	try {
		Form *f = this->_intern->makeForm(formName, target);
		if (f) {
			this->_b1->signForm(*f);
			this->_b2->executeForm(*f);		
			delete f;
		}
	}
	catch (std::exception & e) {
		throw(e);
	}
}
