/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DistantStar.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 14:36:37 by gsmith            #+#    #+#             */
/*   Updated: 2019/05/26 14:45:20 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include "DistantStar.hpp"

DistantStar::DistantStar(int y, int x) : ABackground(y, x, TICK_DISTANTSTAR, 1) {
	this->_form[0] = '*';
}

DistantStar::~DistantStar(void) {

}

void		DistantStar::display(int offsetY, int offsetX) const {
	mvaddch(this->_y + offsetY, this->_x + offsetX, this->_form[0]);
}
t_pos		DistantStar::update(void) {
	t_pos	pos;

	if (this->_updateTick()) {
		this->_y++;
	}
	pos.y = this->_y;
	pos.x = this->_x;
	return (pos);
}
