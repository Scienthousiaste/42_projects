/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Exceptions.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 15:29:51 by tbehra            #+#    #+#             */
/*   Updated: 2019/06/17 14:57:06 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Exceptions.hpp"

Exception::~Exception(void) throw(){

}

Exception::Exception(void) {

}

Exception::Exception(std::string str) : _content(str) {
}

EmptyStackException::EmptyStackException(void) { 
	this->_content = std::string("Tried to pop an empty stack");
}

AssertIsFalseException::AssertIsFalseException(void) { 
	this->_content = std::string("Assert is wrong");
}

NotAnInt8Exception::NotAnInt8Exception(void) { 
	this->_content = std::string("The element on top of the stack is not an int 8");
}

/*
 
 InvalidValueException::InvalidValueException(void) : 
	Exception(std::string("Valeur invalide"))
{
}


*/
