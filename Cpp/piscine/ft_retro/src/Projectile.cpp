/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Projectile.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <tbehra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 15:27:07 by tbehra            #+#    #+#             */
/*   Updated: 2019/05/26 17:14:01 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include "Projectile.hpp"

Projectile::Projectile(int y, int x, int direction) : APhysic(y, x, \
		TICK_PROJECTILE, 1, 0, 1, direction == DIRECTION_UP), \
		_direction(direction), \
		_color(direction != DIRECTION_UP ? COLOR_PAIR_PROJ_R : COLOR_PAIR_PROJ_G) {
	this->_form[0] = '|';
}

Projectile::~Projectile(void) {
}


void				Projectile::display(int offsetY, int offsetX) const {
	attron(COLOR_PAIR(this->_color));
	mvaddch(this->_y + offsetY, this->_x + offsetX, this->_form[0]);
	attroff(COLOR_PAIR(this->_color));
}

t_pos				Projectile::update(void) {
	t_pos pos;
	if (this->_updateTick()) {
		if (this->_direction == DIRECTION_UP)
			this->_y--;
		if (this->_direction == DIRECTION_DOWN)
			this->_y++;
	}
	pos.y = this->_y;
	pos.x = this->_x;
	return (pos);
}
