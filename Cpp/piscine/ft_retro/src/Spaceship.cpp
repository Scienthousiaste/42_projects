/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Spaceship.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <tbehra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 14:06:15 by tbehra            #+#    #+#             */
/*   Updated: 2019/05/26 18:46:30 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Spaceship.hpp"

Spaceship::Spaceship() :
	APhysic(GAME_HEIGHT - 12, GAME_WIDTH / 2 - 1, TICK_SPACESHIP, 3, 0, \
		PLAYER_HP, true), _readyToMove(true), _direction(DIRECTION_NONE), \
	_halfVertical(false) {
	this->_form[0] = '/';
	this->_form[1] = '^';
	this->_form[2] = '\\';
}

Spaceship::~Spaceship(void) {

}

void				Spaceship::display(int offsetY, int offsetX) const {
	attron(COLOR_PAIR(COLOR_PAIR_SPSHIP));
	mvprintw(this->_y+ offsetY, this->_x + offsetX, "%c%c%c", this->_form[0],
			this->_form[1],
			this->_form[2]);
}

t_pos				Spaceship::update(void) {
	t_pos	pos;

	if (this->_updateTick())
		this->_readyToMove = true;

	if (this->_direction && this->_readyToMove) {
		if (this->_direction == DIRECTION_UP \
				&& !(this->_halfVertical = !this->_halfVertical) \
				&& this->_y > 0)
			this->_y--;
		else if (this->_direction == DIRECTION_DOWN \
				&& !(this->_halfVertical = !this->_halfVertical) \
				&& this->_y < GAME_HEIGHT - 1)
			this->_y++;
		else if (this->_direction == DIRECTION_LEFT \
				&& this->_x > 0)
			this->_x--;
		else if (this->_direction == DIRECTION_RIGHT \
				&& this->_x < GAME_WIDTH - 3)
			this->_x++;
		this->_readyToMove = false;
	}
	pos.y = this->_y;
	pos.x = this->_x;
	return (pos);
}

void 		Spaceship::requireMove(int direction) {
	this->_direction = direction;
}

int			Spaceship::getHP(void) const {
	return (this->_hp);
}
