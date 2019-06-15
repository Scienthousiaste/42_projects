/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AEntity.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 10:37:57 by gsmith            #+#    #+#             */
/*   Updated: 2019/05/26 13:50:18 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AEntity.hpp"

AEntity::AEntity(int y, int x, int tickLimit, int size) : _y(y), _x(x), \
	_size(size), _form(new char[size * size]), _tick(0), _tickLimit(tickLimit) {
	int i = -1;

	while (++i < size * size) {
		this->_form[i] = 0;
	}
}

AEntity::~AEntity(void) {
	delete [] this->_form;
}

bool				AEntity::_updateTick(void) {
	this->_tick++;
	if (this->_tick >= this->_tickLimit) {
		this->_tick = 0;
		return (true);
	}
	return (false);
}

t_pos				AEntity::getPos(void) {
	t_pos	pos;

	pos.y = this->_y;
	pos.x = this->_x;
	return (pos);
}
