/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 21:08:42 by tbehra            #+#    #+#             */
/*   Updated: 2019/05/24 10:12:04 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SuperTrap.hpp"


SuperTrap::SuperTrap(std::string name) :	ClapTrap(name),
											FragTrap(name), 
											NinjaTrap(name)
										  {
	this->setHitPoints(100);
	this->setMaxHitPoints(100);
	this->setEnergyPoints(120);
	this->setMaxEnergyPoints(120);
	this->setMeleeDamage(60);
	this->setRangedDamage(20);
	this->setArmor(5);
	
	hashQuote(name, this->_quotes[CONSTRUCTOR_QUOTES_INDEX], "SuperTrap " + name);
}

SuperTrap::~SuperTrap(void) {
	hashQuote(this->_name, this->_quotes[DESTRUCTOR_QUOTES_INDEX], "~SuperTrap " + this->_name);
}

SuperTrap::SuperTrap(SuperTrap const & f) : ClapTrap(f), FragTrap(f), NinjaTrap(f){
	*this = SuperTrap(f._name);
	return;
}
