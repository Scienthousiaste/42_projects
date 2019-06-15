/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 13:07:53 by tbehra            #+#    #+#             */
/*   Updated: 2019/05/24 23:51:04 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.hpp"



Enemy::Enemy(int hp, std::string const & type) : 
	_hp(hp),
	_type(type) {

}
Enemy::Enemy() : _hp(10), _type("none") {

}
Enemy::~Enemy(void) {
}

Enemy::Enemy(Enemy const & e) {
	*this = e;
	return;
}

Enemy & Enemy::operator=(Enemy const & e) {
	this->setHP(e.getHP());
	this->setType(e.getType());
	return *this;
}

void Enemy::takeDamage(int amount) {
	if (amount < 0)
		return ;
	this->_hp = this->_hp - amount;
	if (this->_hp <= 0)
		this->dies();
}

void Enemy::dies(void) const {
	std::cout << "Enemy is dead" << std::endl;
}

void Enemy::setHP(int hp) {
	this->_hp = hp;
}
void Enemy::setType(std::string type) {
	this->_type = type;
}
int Enemy::getHP(void) const {
	return this->_hp;
}
std::string Enemy::getType(void) const {
	return this->_type;
}

