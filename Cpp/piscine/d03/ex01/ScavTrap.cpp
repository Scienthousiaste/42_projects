/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 10:40:46 by tbehra            #+#    #+#             */
/*   Updated: 2019/05/23 15:44:38 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : 
		_hitPoints(100),
		_maxHitPoints(100),
		_energyPoints(50),
		_maxEnergyPoints(50),
		_level(1),
		_name(name),
		_meleeDamage(20),
		_rangedDamage(15),
		_armor(3) {
	
	hashQuote(name, scav_constructor_quotes, "ScavTrap " + name);
}

ScavTrap::~ScavTrap(void) {
	hashQuote(this->_name, scav_destructor_quotes, "~ScavTrap " + this->_name);
}

ScavTrap::ScavTrap(ScavTrap const & f) {
	*this = f;
	return;
}

unsigned int scav_extend_byte(unsigned char c) {
	unsigned int ret;

	ret = c + (((c * 91) % 256 << 8))
			+ (((c * 11) % 256 << 16))
			+ (((c * 3) % 256 << 24));
	return (ret);
}

void ScavTrap::hashQuote(std::string const & entropy,
		std::string const arr_quotes[SCAV_QUOTES],
		std::string func_name) {
	unsigned int hash = 0x12345678;
	size_t i = 0;
	while (i < entropy.length()) {
		hash = hash ^ scav_extend_byte((unsigned char) entropy[i]); 
		i++;
	}
	std::cout << "(" << func_name << ") " << arr_quotes[hash % SCAV_QUOTES] << std::endl;
}

ScavTrap & ScavTrap::operator=(ScavTrap const & f) {
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

void ScavTrap::rangedAttack(std::string const & target) {
	std::cout << "FR4G-TP " << this->_name << " attacks " << target
		<< " at range, causing " << this->_rangedDamage << " points of damage ! ";
}
void ScavTrap::meleeAttack(std::string const & target) {
	std::cout << "FR4G-TP " << this->_name << " attacks " << target
		<< " in melee, causing " << this->_meleeDamage << " points of damage ! ";
}
void ScavTrap::takeDamage(unsigned int amount) {
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
		hashQuote(this->_name, scav_death_quotes, "takeDamage");
	}
	else {
		std::cout << "No, nothing else can be down with " << this->_name
			<<"'s smelly carcass." << std::endl;
	}
}
void ScavTrap::beRepaired(unsigned int amount) {
	this->_hitPoints = (this->_hitPoints + (int)amount  > this->_maxHitPoints) ? 
		this->_maxHitPoints : this->_hitPoints + amount;
	std::cout << this->_name << " gets repaired " << amount
		<< " and has now " << this->_hitPoints << " left!" <<  std::endl;
}

void ScavTrap::challengeNewcomer(std::string const & target) {
	std::cout << this->_name << " sends a challenge to " << target << std::endl;
	hashQuote(this->_name, challenges_quotes, "challengeNewcomer");
}

int ScavTrap::getHitPoints(void) const {
	return this->_hitPoints;
}
int ScavTrap::getMaxHitPoints(void) const {
	return this->_maxHitPoints;
}
int ScavTrap::getEnergyPoints(void) const {
	return this->_energyPoints;
}
int ScavTrap::getMaxEnergyPoints(void) const {
	return this->_maxEnergyPoints;
}
int ScavTrap::getLevel(void) const {
	return this->_level;
}
std::string ScavTrap::getName(void) const {
	return this->_name;
}
int ScavTrap::getMeleeDamage(void) const {
	return this->_meleeDamage;
}
int ScavTrap::getRangedDamage(void) const {
	return this->_rangedDamage;
}
int ScavTrap::getArmor(void) const {
	return this->_armor;
}

void ScavTrap::setHitPoints(int n) {
	this->_hitPoints = n;
}
void ScavTrap::setMaxHitPoints(int n) {
	this->_maxHitPoints = n;
}
void ScavTrap::setEnergyPoints(int n) {
	this->_energyPoints = n;
}
void ScavTrap::setMaxEnergyPoints(int n) {
	this->_maxEnergyPoints = n;
}
void ScavTrap::setLevel(int n) {
	this->_level = n;
}
void ScavTrap::setName(std::string name) {
	this->_name = name;
}
void ScavTrap::setMeleeDamage(int n) {
	this->_meleeDamage = n;
}
void ScavTrap::setRangedDamage(int n) {
	this->_rangedDamage = n;
}
void ScavTrap::setArmor(int n) {
	this->_armor = n;
}
