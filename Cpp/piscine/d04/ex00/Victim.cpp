/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Victim.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 11:15:34 by tbehra            #+#    #+#             */
/*   Updated: 2019/05/24 23:27:19 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Victim.hpp"

Victim::Victim(void) : _name("Anonymous") {
	std::cout << "Some random victim called " << this->_name << " just popped !"
		<< std::endl;
}

Victim::Victim(std::string name) : 
	_name(name) {
	std::cout << "Some random victim called " << this->_name << " just popped !"
		<< std::endl;
}

Victim::~Victim(void) {
	std::cout << "Victim " << this->_name << " just died for no apparent reason !"
		<< std::endl;
}

Victim::Victim(Victim const & v) {
	*this = v;
	return;
}

Victim & Victim::operator=(Victim const & v) {
	this->setName(v.getName());
	return *this;
}

std::string Victim::introduceThyself(void) const {
	return ("I am " + this->_name + " and I like otters !");
}

void Victim::setName(std::string name) {
	this->_name = name;
}
std::string Victim::getName(void) const {
	return this->_name;
}

void Victim::getPolymorphed(void) const {
	std::cout << this->_name << " has been turned into a cute little sheep !" << std::endl;
}

std::ostream & operator<<(std::ostream &o, Victim const & v) {
	o << v.introduceThyself() << std::endl;
	return o;
}
