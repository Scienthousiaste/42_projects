/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AlienShip.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <tbehra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 12:00:55 by tbehra            #+#    #+#             */
/*   Updated: 2019/05/26 18:09:20 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include "AlienShip.hpp"

AlienShip::AlienShip(int y, int x, AlienWeapon * weapon) : 
	APhysic(y, x, TICK_ALIENSHIP, 3,
	SCORE_ALIENSHIP, HP_ALIENSHIP, false),
	_tickShoot(0),
	_tickLimitShoot(TICK_SHOOT_ALIEN){

	this->_weapon = weapon;
	this->_form[0] = 'W';
	this->_form[1] = '|';
	this->_form[2] = 'W';
	this->_form[4] = 'V';
}

AlienShip::~AlienShip(void) {

}

void				AlienShip::display(int offsetY, int offsetX) const {
	attron(COLOR_PAIR(COLOR_PAIR_ALSHIP));
	mvprintw(this->_y + offsetY, this->_x + offsetX, "%c%c%c", this->_form[0],\
			this->_form[1], this->_form[2]);
	if (this->_y + 1 >= GAME_HEIGHT) {
		attroff(COLOR_PAIR(COLOR_PAIR_ALSHIP));
		return ;
	}
	mvprintw(this->_y + 1 + offsetY, this->_x + offsetX, " %c",			\
			this->_form[4]);
	attroff(COLOR_PAIR(COLOR_PAIR_ALSHIP));
}

bool				AlienShip::_updateTickShoot(void) {
	this->_tickShoot++;
	if (this->_tickShoot >= this->_tickLimitShoot) {
		this->_tickShoot = 0;
		return true;
	}
	return false;
}

t_pos				AlienShip::update(void) {
	t_pos	pos;
	t_pos	pos_shoot;

	if (this->_updateTick()) {
		this->_y++;
	}
	pos.y = this->_y;
	pos.x = this->_x;
	if (this->_updateTickShoot()) {
		pos_shoot.x = pos.x + 1;
		pos_shoot.y = pos.y + 1;
		this->_weapon->shoot(pos_shoot);
	}
	return (pos);
}
