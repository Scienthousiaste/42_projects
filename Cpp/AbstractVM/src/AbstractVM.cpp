/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AbstractVM.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 18:12:33 by tbehra            #+#    #+#             */
/*   Updated: 2019/06/17 17:02:13 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "AbstractVM.hpp"

AbstractVM::AbstractVM(void) {
}

AbstractVM::~AbstractVM(void) {
}

IterStack< const IOperand* > & AbstractVM::getStack(void) {
	return this->_stack;
}

Factory & AbstractVM::getFactory(void) {
	return this->_factory;
}

void AbstractVM::push(const IOperand *op) {
	(this->getStack()).push(op);
}

void AbstractVM::pop(void) throw(){
	if (this->getStack().empty())
		throw EmptyStackException(); 
	else {
		this->getStack().pop();
	}
}

void AbstractVM::dump(void) {
	IterStack< std::string > strStack;

	if (this->getStack().empty())
		return;

	IterStack< const IOperand* >::iterator it = this->getStack().begin();
	IterStack< const IOperand* >::iterator ite = this->getStack().end();
	while (it != ite)
	{
		strStack.push((*it)->toString() + "\n");
		++it;
	}

	IterStack< std::string >::iterator its = strStack.begin();
	IterStack< std::string >::iterator itse = strStack.end();
	while (its != itse)
	{
		std::cout << *its;
		++its;
	}
}

void AbstractVM::assert(const IOperand *op) throw() {
	if (op->toString() != this->getStack().top()->toString()
		|| (op->getType() != this->getStack().top()->getType()))
		throw AssertIsFalseException(); 
}

void AbstractVM::add(void) throw(){
	if (this->getStack().empty())
		throw EmptyStackException();
	IOperand const * o1 = this->getStack().top();
	this->getStack().pop();
	IOperand const * o2 = this->getStack().top();
	this->getStack().pop();
	this->push(*o2 + *o1);	
	delete o1;
	delete o2;
}

void AbstractVM::sub(void) throw(){
	if (this->getStack().empty())
		throw EmptyStackException();
	IOperand const * o1 = this->getStack().top();
	this->getStack().pop();
	IOperand const * o2 = this->getStack().top();
	this->getStack().pop();
	this->push(*o2 - *o1);	
	delete o1;
	delete o2;
}

void AbstractVM::mul(void) throw(){
	if (this->getStack().empty())
		throw EmptyStackException();
	IOperand const * o1 = this->getStack().top();
	this->getStack().pop();
	IOperand const * o2 = this->getStack().top();
	this->getStack().pop();
	this->push(*o2 * *o1);	
	delete o1;
	delete o2;
}

void AbstractVM::div(void) throw(){
	if (this->getStack().empty())
		throw EmptyStackException();
	IOperand const * o1 = this->getStack().top();
	this->getStack().pop();
	IOperand const * o2 = this->getStack().top();
	this->getStack().pop();

	//TODO : check /0 , check what do with float/double
	this->push(*o2 / *o1);	
	delete o1;
	delete o2;
}

void AbstractVM::mod(void) throw(){
	if (this->getStack().empty())
		throw EmptyStackException();
	IOperand const * o1 = this->getStack().top();
	this->getStack().pop();
	IOperand const * o2 = this->getStack().top();
	this->getStack().pop();

	//TODO : check /0 , check what do with float/double
	this->push(*o2 % *o1);	
	delete o1;
	delete o2;
}

void AbstractVM::print(void) throw() {
	if (this->getStack().top()->getType() != Int8)
		throw NotAnInt8Exception();

	std::cout << static_cast<char>(std::stoi(this->getStack().top()->toString()));

}
