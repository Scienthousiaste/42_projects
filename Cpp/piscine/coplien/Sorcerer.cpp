/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 10:23:05 by tbehra            #+#    #+#             */
/*   Updated: 2019/05/24 10:31:15 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sorcerer.hpp"

Sorcerer::Sorcerer(std::string name, std::string title) : 
	_name(name),
	_title(title) {
	
}

Sorcerer::~Sorcerer(void) {

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
