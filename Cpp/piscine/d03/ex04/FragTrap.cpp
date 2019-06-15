/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 10:40:46 by tbehra            #+#    #+#             */
/*   Updated: 2019/05/23 21:05:25 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name) {

	this->_quotes[DEATH_QUOTES_INDEX] = flagtrap_death_quotes;
	this->_quotes[CONSTRUCTOR_QUOTES_INDEX] = flagtrap_constructor_quotes;
	this->_quotes[DESTRUCTOR_QUOTES_INDEX] = flagtrap_destructor_quotes;
	hashQuote(name, this->_quotes[CONSTRUCTOR_QUOTES_INDEX], "FragTrap " + name);
}

FragTrap::~FragTrap(void) {
	hashQuote(this->_name, this->_quotes[DESTRUCTOR_QUOTES_INDEX],
			"~FragTrap " + this->_name);
}

FragTrap::FragTrap(FragTrap const & f) : ClapTrap(f){
	*this = FragTrap(f._name);
	return;
}

void FragTrap::vaulthunter_dot_exe(std::string const & target) {
	
	if ((this->_energyPoints) < ENERGY_VAULT) {
		std::cout << this->_name << " has not enough energy to launch the vaulthunter."
			<< std::endl;
	}
	else {
		std::string entropyString = std::string(this->_name);
		entropyString[0] = (entropyString[0] + this->_energyPoints) % 255;
		this->_energyPoints -= ENERGY_VAULT;
		std::cout << this->_name << " launches the vaulthunter on "
			<< target << ", spends " << ENERGY_VAULT << " energy and has "
			<< this->_energyPoints << " left." << std::endl;
		hashQuote(entropyString, vault_quotes, "vaulthunter.exe");
	}
}
