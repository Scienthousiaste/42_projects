/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 10:40:46 by tbehra            #+#    #+#             */
/*   Updated: 2019/05/23 21:00:09 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : 
		_hitPoints(100),
		_maxHitPoints(100),
		_energyPoints(100),
		_maxEnergyPoints(100),
		_level(1),
		_name(name),
		_meleeDamage(30),
		_rangedDamage(20),
		_armor(5) {
	
	hashQuote(name, constructor_quotes, "FragTrap " + name);
}

FragTrap::~FragTrap(void) {
	hashQuote(this->_name, destructor_quotes, "~FragTrap " + this->_name);
}

FragTrap::FragTrap(FragTrap const & f) {
	*this = f;
	return;
}

unsigned int extend_byte(unsigned char c) {
	unsigned int ret;

	ret = c + (((c * 37) % 256 << 8))
			+ (((c * 11) % 256 << 16))
			+ (((c * 7) % 256 << 24));
	return (ret);
}

void FragTrap::hashQuote(std::string const & entropy,
		std::string const arr_quotes[QUOTES],
		std::string func_name) {
	unsigned int hash = 0x12345678;
	size_t i = 0;
	while (i < entropy.length()) {
		hash = hash ^ extend_byte((unsigned char) entropy[i]); 
		i++;
	}
	std::cout << "(" << func_name << ") " << arr_quotes[hash % QUOTES] << std::endl;
}

FragTrap & FragTrap::operator=(FragTrap const & f) {
	this->setHitPoints(f.getHitPoints());
	this->setMaxHitPoints(f.getMaxHitPoints());
	this->setEnergyPoints(f.getEnergyPoints());
	this->setMaxEnergyPoints(f.getMaxEnergyPoints());
	this->setLevel(f.getLevel());
	this->setName(f.getName());
	this->setMeleeDamage(f.getMeleeDamage());
	this->setRangedDamage(f.getRangedDamage());
	this->setArmor(f.getArmor());
	return *this;
}

void FragTrap::rangedAttack(std::string const & target) {
	std::cout << "FR4G-TP " << this->_name << " attacks " << target
		<< " at range, causing " << this->_rangedDamage << " points of damage ! ";
}
void FragTrap::meleeAttack(std::string const & target) {
	std::cout << "FR4G-TP " << this->_name << " attacks " << target
		<< " in melee, causing " << this->_meleeDamage << " points of damage ! ";
}
void FragTrap::takeDamage(unsigned int amount) {
	amount = amount - this->_armor;

	if (this->_hitPoints > (int)amount) {
		this->_hitPoints -= amount;
		std::cout << this->_name << " takes " << amount
			<< " damage and has " << this->_hitPoints << " left!" <<  std::endl;
	}
	else if (this->_hitPoints > 0 && this->_hitPoints <= (int)amount) {
		std::cout << this->_name << " takes " << amount
			<< " damage and DIES. ";
		this->_hitPoints = 0;	
		hashQuote(this->_name, death_quotes, "takeDamage");
	}
	else {
		std::cout << "No, nothing else can be down with " << this->_name
			<<"'s smelly carcass." << std::endl;
	}
}
void FragTrap::beRepaired(unsigned int amount) {
	this->_hitPoints = (this->_hitPoints + (int)amount  > this->_maxHitPoints) ? 
		this->_maxHitPoints : this->_hitPoints + amount;
	std::cout << this->_name << " gets repaired " << amount
		<< " and has now " << this->_hitPoints << " left!" <<  std::endl;
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

int FragTrap::getHitPoints(void) const {
	return this->_hitPoints;
}
int FragTrap::getMaxHitPoints(void) const {
	return this->_maxHitPoints;
}
int FragTrap::getEnergyPoints(void) const {
	return this->_energyPoints;
}
int FragTrap::getMaxEnergyPoints(void) const {
	return this->_maxEnergyPoints;
}
int FragTrap::getLevel(void) const {
	return this->_level;
}
std::string FragTrap::getName(void) const {
	return this->_name;
}
int FragTrap::getMeleeDamage(void) const {
	return this->_meleeDamage;
}
int FragTrap::getRangedDamage(void) const {
	return this->_rangedDamage;
}
int FragTrap::getArmor(void) const {
	return this->_armor;
}

void FragTrap::setHitPoints(int n) {
	this->_hitPoints = n;
}
void FragTrap::setMaxHitPoints(int n) {
	this->_maxHitPoints = n;
}
void FragTrap::setEnergyPoints(int n) {
	this->_energyPoints = n;
}
void FragTrap::setMaxEnergyPoints(int n) {
	this->_maxEnergyPoints = n;
}
void FragTrap::setLevel(int n) {
	this->_level = n;
}
void FragTrap::setName(std::string name) {
	this->_name = name;
}
void FragTrap::setMeleeDamage(int n) {
	this->_meleeDamage = n;
}
void FragTrap::setRangedDamage(int n) {
	this->_rangedDamage = n;
}
void FragTrap::setArmor(int n) {
	this->_armor = n;
}
