/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 17:17:24 by tbehra            #+#    #+#             */
/*   Updated: 2019/05/23 21:01:10 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : 
		_hitPoints(100),
		_maxHitPoints(100),
		_energyPoints(100),
		_maxEnergyPoints(100),
		_level(1),
		_name(name),
		_meleeDamage(30),
		_rangedDamage(20),
		_armor(5) {
	
	this->_quotes[DEATH_QUOTES_INDEX] = claptrap_death_quotes;
	this->_quotes[CONSTRUCTOR_QUOTES_INDEX] = claptrap_constructor_quotes;
    this->_quotes[DESTRUCTOR_QUOTES_INDEX] = claptrap_destructor_quotes;
	hashQuote(name, this->_quotes[CONSTRUCTOR_QUOTES_INDEX], "ClapTrap " + name);
}

ClapTrap::~ClapTrap(void) {
	hashQuote(this->_name, this->_quotes[DESTRUCTOR_QUOTES_INDEX],
			"~ClapTrap " + this->_name);
}

ClapTrap::ClapTrap(ClapTrap const & f) {
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

void ClapTrap::hashQuote(std::string const & entropy,
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

ClapTrap & ClapTrap::operator=(ClapTrap const & f) {
	this->setHitPoints(f.getHitPoints());
	this->setMaxHitPoints(f.getMaxHitPoints());
	this->setEnergyPoints(f.getEnergyPoints());
	this->setMaxEnergyPoints(f.getMaxEnergyPoints());
	this->setLevel(f.getLevel());
	this->setName(f.getName());
	this->setMeleeDamage(f.getMeleeDamage());
	this->setRangedDamage(f.getRangedDamage());
	this->setArmor(f.getArmor());
	
	this->_quotes[DEATH_QUOTES_INDEX] = claptrap_death_quotes;
	this->_quotes[CONSTRUCTOR_QUOTES_INDEX] = claptrap_constructor_quotes;
    this->_quotes[DESTRUCTOR_QUOTES_INDEX] = claptrap_destructor_quotes;
	return *this;
}

void ClapTrap::rangedAttack(std::string const & target) {
	std::cout << "FR4G-TP " << this->_name << " attacks " << target
		<< " at range, causing " << this->_rangedDamage << " points of damage ! ";
}
void ClapTrap::meleeAttack(std::string const & target) {
	std::cout << "FR4G-TP " << this->_name << " attacks " << target
		<< " in melee, causing " << this->_meleeDamage << " points of damage ! ";
}
void ClapTrap::takeDamage(unsigned int amount) {
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
		hashQuote(this->_name, this->_quotes[DEATH_QUOTES_INDEX], "takeDamage");
	}
	else {
		std::cout << "No, nothing else can be down with " << this->_name
			<<"'s smelly carcass." << std::endl;
	}
}
void ClapTrap::beRepaired(unsigned int amount) {
	this->_hitPoints = (this->_hitPoints + (int)amount  > this->_maxHitPoints) ? 
		this->_maxHitPoints : this->_hitPoints + amount;
	std::cout << this->_name << " gets repaired " << amount
		<< " and has now " << this->_hitPoints << " left!" <<  std::endl;
}

int ClapTrap::getHitPoints(void) const {
	return this->_hitPoints;
}
int ClapTrap::getMaxHitPoints(void) const {
	return this->_maxHitPoints;
}
int ClapTrap::getEnergyPoints(void) const {
	return this->_energyPoints;
}
int ClapTrap::getMaxEnergyPoints(void) const {
	return this->_maxEnergyPoints;
}
int ClapTrap::getLevel(void) const {
	return this->_level;
}
std::string ClapTrap::getName(void) const {
	return this->_name;
}
int ClapTrap::getMeleeDamage(void) const {
	return this->_meleeDamage;
}
int ClapTrap::getRangedDamage(void) const {
	return this->_rangedDamage;
}
int ClapTrap::getArmor(void) const {
	return this->_armor;
}

void ClapTrap::setHitPoints(int n) {
	this->_hitPoints = n;
}
void ClapTrap::setMaxHitPoints(int n) {
	this->_maxHitPoints = n;
}
void ClapTrap::setEnergyPoints(int n) {
	this->_energyPoints = n;
}
void ClapTrap::setMaxEnergyPoints(int n) {
	this->_maxEnergyPoints = n;
}
void ClapTrap::setLevel(int n) {
	this->_level = n;
}
void ClapTrap::setName(std::string name) {
	this->_name = name;
}
void ClapTrap::setMeleeDamage(int n) {
	this->_meleeDamage = n;
}
void ClapTrap::setRangedDamage(int n) {
	this->_rangedDamage = n;
}
void ClapTrap::setArmor(int n) {
	this->_armor = n;
}
