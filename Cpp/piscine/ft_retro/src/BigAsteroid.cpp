/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BigAsteroid.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <tbehra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 16:45:21 by tbehra            #+#    #+#             */
/*   Updated: 2019/05/26 17:22:16 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include <string>
#include "BigAsteroid.hpp"
#include "const.hpp"

BigAsteroid::BigAsteroid(int y, int x) : APhysic(y, x, TICK_BIG_ASTEROID, 5,
		SCORE_BIGASTEROID, HP_BIGASTEROID, false) {

	std::string		s = " ##  #``###```# #``#  ## ";

	for (size_t i = 0; i < s.length(); i++) {
		this->_form[i] = s[i] == ' ' ? 0 : s[i];
	}
}

BigAsteroid::~BigAsteroid(void) {

}

void				BigAsteroid::display(int offsetY, int offsetX) const {
	std::string		s;

	attron(COLOR_PAIR(COLOR_PAIR_ASTERO));
	int i = -1;
	while (++i < (this->_size * this->_size)) {
		if (this->_y + i / this->_size >= GAME_HEIGHT) {
			attroff(COLOR_PAIR(COLOR_PAIR_ASTERO));
			return ;
		}
		if (this->_form[i])
			mvaddch(this->_y + i / this->_size + offsetY, \
					this->_x + i % this->_size + offsetX, \
					this->_form[i]);
	}
	attroff(COLOR_PAIR(COLOR_PAIR_ASTERO));
}

t_pos				BigAsteroid::update(void) {
	t_pos			pos;

	if (this->_updateTick()) {
		this->_y++;
	}
	pos.y = this->_y;
	pos.x = this->_x;
	return (pos);
}
