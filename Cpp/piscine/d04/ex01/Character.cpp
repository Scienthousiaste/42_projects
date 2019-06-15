/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 13:41:31 by tbehra            #+#    #+#             */
/*   Updated: 2019/05/24 23:48:55 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : _name("John Doe"),
	_AP(40),
	_weapon(NULL) {
}

Character::Character(std::string const & name) : 
	_name(name),
	_AP(40),
	_weapon(NULL) {
}

Character::~Character(void) {
}

Character::Character(Character const & e) {
	*this = e;
	return;
}

Character & Character::operator=(Character const & e) {
	this->_AP = e.getAP();
	this->_name = e.getName();
	this->_weapon = e.getWeapon();
	return *this;
}

void Character::recoverAP(void) {
	this->_AP += 10;
	if (this->_AP > 40)
		this->_AP = 40;
}
void Character::equip(AWeapon* w) {
	this->_weapon = w;
}
void Character::attack(Enemy* e) {
	if (!(this->_weapon))
		return;
	if (this->_AP >= this->_weapon->getAPCost()) {
		this->_AP -= this->_weapon->getAPCost();
		std::cout << this->_name << " attacks " << e->getType() << " with a "
			<< this->_weapon->getName() << std::endl;
		this->_weapon->attack();
		e->takeDamage(this->_weapon->getDamage());
		if (e->getHP() <= 0)
			delete e;
	}
	else {
		std::cout << this->_name << " doesn't have enough AP"
		   << " to operate his weapon" << std::endl;
	}
}

std::string Character::describe(void) const{
	std::stringstream ret;
	ret << this->_name << " has " << this->_AP << " AP and";
	if (this->_weapon)
		ret << " wields a " << this->_weapon->getName() << std::endl;
	else 
		ret << " is unarmed" << std::endl;
	return (ret.str());
}
std::string Character::getName(void) const {
	return this->_name;
}

int Character::getAP(void) const {
	return this->_AP;
}
AWeapon *Character::getWeapon(void) const {
	return this->_weapon;
}

std::ostream & operator<<(std::ostream &o, Character const & c) {
	o << c.describe() << std::endl;
	return o;
}

