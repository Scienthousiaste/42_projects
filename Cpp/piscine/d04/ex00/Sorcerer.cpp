/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 10:23:05 by tbehra            #+#    #+#             */
/*   Updated: 2019/05/24 23:30:23 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sorcerer.hpp"

Sorcerer::Sorcerer(std::string name, std::string title) : 
	_name(name),
	_title(title) {
	std::cout << this->_name << ", " << this->_title << ", is born !" << std::endl;	
}

Sorcerer::Sorcerer(void) : 
	_name("Anon"),
	_title("Ymous") {
	std::cout << this->_name << ", " << this->_title << ", is born !" << std::endl;	
}

Sorcerer::~Sorcerer(void) {
	std::cout << this->_name << ", " << this->_title << ", is dead."
	 	<< " Consequences will never be the same !" << std::endl;	
}

Sorcerer::Sorcerer(Sorcerer const & s) {
	*this = s;
	return;
}

Sorcerer & Sorcerer::operator=(Sorcerer const & s) {
	this->setName(s.getName());
	this->setTitle(s.getTitle());
	return *this;
}

std::string Sorcerer::introduceThyself(void) const {
	return ("I am " + this->_name + ", " + this->_title + ", and I like ponies !");
}

void Sorcerer::setName(std::string name) {
	this->_name = name;
}
void Sorcerer::setTitle(std::string title) {
	this->_title = title;
}
std::string Sorcerer::getName(void) const {
	return this->_name;
}
std::string Sorcerer::getTitle(void) const {
	return this->_title;
}

std::ostream & operator<<(std::ostream &o, Sorcerer const & s) {
	o << s.introduceThyself() << std::endl;
	return o;
}

void Sorcerer::polymorph(Victim const & v) const {
	v.getPolymorphed();
}
