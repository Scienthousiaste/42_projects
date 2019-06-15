/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 20:25:01 by tbehra            #+#    #+#             */
/*   Updated: 2019/05/23 21:05:51 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NinjaTrap.hpp"

NinjaTrap::NinjaTrap(std::string name) : ClapTrap(name) {
	this->setHitPoints(60);
	this->setMaxHitPoints(60);
	this->setEnergyPoints(120);
	this->setMaxEnergyPoints(120);
	this->setMeleeDamage(60);
	this->setRangedDamage(5);
	this->setArmor(0);
	
	hashQuote(name, this->_quotes[CONSTRUCTOR_QUOTES_INDEX], "NinjaTrap " + name);
}

NinjaTrap::~NinjaTrap(void) {
	hashQuote(this->_name, this->_quotes[DESTRUCTOR_QUOTES_INDEX], "~NinjaTrap " + this->_name);
}

NinjaTrap::NinjaTrap(NinjaTrap const & f) : ClapTrap(f) {
	*this = NinjaTrap(f._name);
	return;
}

void NinjaTrap::ninjaShoebox(NinjaTrap const & target) {
	std::cout << this->_name << " meets " << target.getName()
		<< "; 2 ninjas together will NINJA till dawn!" << std::endl; 
}
void NinjaTrap::ninjaShoebox(ClapTrap const & target) {
	std::cout << this->_name << " mystifies " << target.getName()
		<< " and persuades him to buy BitCoin on margin." << std::endl; 
}
void NinjaTrap::ninjaShoebox(ScavTrap const & target) {
	std::cout << this->_name << " scorns " << target.getName()
		<< " for not being a cat ScavTrap." << std::endl; 
}
void NinjaTrap::ninjaShoebox(FragTrap const & target) {
	std::cout << this->_name << " scorns " << target.getName()
		<< " for not being a dog FragTrap." << std::endl; 
}
