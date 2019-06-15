/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperMutant.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 13:18:42 by tbehra            #+#    #+#             */
/*   Updated: 2019/05/24 13:31:13 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "SuperMutant.hpp"


SuperMutant::SuperMutant() : Enemy(170, "SuperMutant") { 
	std::cout << "Gaaah. Me wat smash heads !" << std::endl;
}

SuperMutant::~SuperMutant(void) {
}

SuperMutant::SuperMutant(SuperMutant const & e) : Enemy(e){
	*this = SuperMutant(e);
	return;
}

SuperMutant & SuperMutant::operator=(SuperMutant const & e) {
	this->setHP(e.getHP());
	this->setType(e.getType());
	return *this;
}

void SuperMutant::takeDamage(int amount) {
	amount -= 3;
	if (amount < 0)
		return ;
	this->_hp = this->_hp - amount;
	if (this->_hp <= 0)
		this->dies();
}

void SuperMutant::dies(void) const {
	std::cout << "Aaargh ..." << std::endl;
}
