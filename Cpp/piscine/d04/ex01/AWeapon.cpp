/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWeapon.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 11:48:39 by tbehra            #+#    #+#             */
/*   Updated: 2019/05/24 23:49:47 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AWeapon.hpp"

AWeapon::AWeapon() : _name("none"),
	_apcost(1),
	_damage(1) {

}

AWeapon::AWeapon(std::string const & name, int apcost, int damage) : 
	_name(name),
	_apcost(apcost),
	_damage(damage) {
}

AWeapon::~AWeapon(void) {
}

AWeapon::AWeapon(AWeapon const & w) {
	*this = w;
	return;
}

AWeapon & AWeapon::operator=(AWeapon const & w) {
	this->setName(w.getName());
	this->setAPCost(w.getAPCost());
	this->setDamage(w.getDamage());
	return *this;
}

void AWeapon::setName(std::string name) {
	this->_name = name;
}
void AWeapon::setAPCost(int apcost) {
	this->_apcost = apcost;
}
void AWeapon::setDamage(int damage) {
	this->_damage = damage;
}
std::string AWeapon::getName(void) const {
	return this->_name;
}
int AWeapon::getAPCost(void) const {
	return this->_apcost;
}
int AWeapon::getDamage(void) const {
	return this->_damage;
}

