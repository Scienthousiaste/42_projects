/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Explosion.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 18:50:18 by gsmith            #+#    #+#             */
/*   Updated: 2019/05/26 19:20:57 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include "Explosion.hpp"

Explosion::Explosion(int y, int x, int start) : ABackground(y, x, TICK_EXPLOSION, 2), \
	_frame(0) {
	this->_form[start % 4] = '#';
	this->_form[(start + 1) % 4] = '*';
	this->_form[(start + 2) % 4] = '%';
	this->_form[(start + 3) % 4] = '@';
}

Explosion::~Explosion(void) {

}

void		Explosion::display(int offsetY, int offsetX) const {
	attron(COLOR_PAIR(COLOR_PAIR_EXPLOD));
	mvaddch(this->_y + offsetY, this->_x + offsetX, this->_form[this->_frame % 4]);
	attroff(COLOR_PAIR(COLOR_PAIR_EXPLOD));
}
t_pos		Explosion::update(void) {
	t_pos	pos;

	if (this->_updateTick()) {
		this->_frame++;
	}
	if (this->_frame == FRAME_EXPLOSION) {
		pos.y = GAME_HEIGHT + 1;
		pos.x = GAME_WIDTH + 1;
		return (pos);
	}
	pos.y = this->_y;
	pos.x = this->_x;
	return (pos);
}
