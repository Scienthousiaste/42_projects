/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AlienWeapon.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <tbehra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 14:10:53 by tbehra            #+#    #+#             */
/*   Updated: 2019/05/26 18:12:04 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AlienWeapon.hpp"


AlienWeapon::AlienWeapon(Game & game) : _game(game),
	_tickShoot(0),
	_tickShootLimit(TICK_SHOOT_ALIEN){
}

AlienWeapon::~AlienWeapon(void) {
	
}

void AlienWeapon::shoot(t_pos pos) {
	this->_game.pushProjectile(new Projectile(pos.y, pos.x, DIRECTION_DOWN));
}

bool AlienWeapon::_updateTickShoot(void) {
	this->_tickShoot++;
	if (this->_tickShoot >= this->_tickShootLimit) {
		this->_tickShoot = 0;
		return (true);
	}
	return (false);
}
