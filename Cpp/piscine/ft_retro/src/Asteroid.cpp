/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Asteroid.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 11:36:15 by gsmith            #+#    #+#             */
/*   Updated: 2019/05/26 17:21:03 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include "Asteroid.hpp"

Asteroid::Asteroid(int y, int x) : APhysic(y, x, TICK_ASTEROID, 2, \
	SCORE_ASTEROID, HP_ASTEROID, false) {
	this->_form[0] = '/';
	this->_form[1] = '#';
	this->_form[2] = 'v';
	this->_form[3] = 0;
}

Asteroid::~Asteroid(void) {

}

void				Asteroid::display(int offsetY, int offsetX) const {
	attron(COLOR_PAIR(COLOR_PAIR_ASTERO));
	mvprintw(this->_y + offsetY, this->_x + offsetX, "%c%c", \
		this->_form[0], this->_form[1]);
	if (this->_y + 1 >= GAME_HEIGHT) {
		attroff(COLOR_PAIR(COLOR_PAIR_ASTERO));
		return ;
	}
	mvprintw(this->_y + 1 + offsetY, this->_x + offsetX, "%c%c", \
		this->_form[2], this->_form[3]);
	attroff(COLOR_PAIR(COLOR_PAIR_ASTERO));
}

t_pos				Asteroid::update(void) {
	t_pos	pos;

	if (this->_updateTick()) {
		this->_y++;
	}
	pos.y = this->_y;
	pos.x = this->_x;
	return (pos);
}
