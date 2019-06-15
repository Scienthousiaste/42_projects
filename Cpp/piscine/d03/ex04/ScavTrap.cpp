/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 10:40:46 by tbehra            #+#    #+#             */
/*   Updated: 2019/05/23 20:15:48 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	this->setEnergyPoints(50);
	this->setMaxEnergyPoints(50);
	this->setMeleeDamage(20);
	this->setRangedDamage(15);
	this->setArmor(3);
	
	this->_quotes[DEATH_QUOTES_INDEX] = scavtrap_death_quotes;
	this->_quotes[CONSTRUCTOR_QUOTES_INDEX] = scavtrap_constructor_quotes;
	this->_quotes[DESTRUCTOR_QUOTES_INDEX] = scavtrap_destructor_quotes;
	hashQuote(name, this->_quotes[CONSTRUCTOR_QUOTES_INDEX], "ScavTrap " + name);
}

ScavTrap::~ScavTrap(void) {
	hashQuote(this->_name, this->_quotes[DESTRUCTOR_QUOTES_INDEX], "~ScavTrap " + this->_name);
}

ScavTrap::ScavTrap(ScavTrap const & f) : ClapTrap(f) {
	*this = ScavTrap(f._name);
	return;
}

void ScavTrap::challengeNewcomer(std::string const & target) {
	std::cout << this->_name << " sends a challenge to " << target << std::endl;
	hashQuote(this->_name, challenges_quotes, "challengeNewcomer");
}
