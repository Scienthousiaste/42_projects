/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 21:10:41 by tbehra            #+#    #+#             */
/*   Updated: 2019/05/25 00:11:14 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() {

}

Character::Character(std::string const & name) : name_(name) {
	for (int i = 0; i < INVENTORY_SIZE; i++) {
		this->inventory_[i] = NULL;
	}
}

Character::~Character() {
	for (int i = 0; i < INVENTORY_SIZE; i++) {
		if (this->inventory_[i])
			delete (this->inventory_[i]);
	}
}

Character::Character(Character const & a) {
	*this = Character(a);
}

Character & Character::operator=(Character const & a) {
	this->name_ = a.name_;
	for (int i = 0; i < INVENTORY_SIZE; i++) {
		this->inventory_[i] = a.inventory_[i]->clone();
	}
	return *this;
}

void Character::equip(AMateria *m) {
	if (!m)
		return;
	for (int i = 0; i < INVENTORY_SIZE; i++) {
		if (this->inventory_[i] == NULL) {
			this->inventory_[i] = m;
			break;
		}
	}
}

void Character::unequip(int idx) {
	if (idx > 0 && idx < INVENTORY_SIZE)
		this->inventory_[idx] = NULL;
}

void Character::use(int idx, ICharacter& target) {
	AMateria* m = NULL;
	if (idx >= 0 && idx < INVENTORY_SIZE) {
		m = this->inventory_[idx];
		idx++;
	}
	if (m) {
		m->use(target);
	}
}

std::string const & Character::getName() const {
	return this->name_;
}

AMateria* Character::getMateriaIndex(int idx) const {
	if (idx > 0 && idx < INVENTORY_SIZE)
		return this->inventory_[idx];
	else
		return NULL;
}
