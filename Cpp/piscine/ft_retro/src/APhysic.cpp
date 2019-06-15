/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   APhysic.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 12:08:02 by gsmith            #+#    #+#             */
/*   Updated: 2019/05/26 13:47:57 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "APhysic.hpp"

APhysic::APhysic(int y, int x, int tickLimit, int size, int score, int hp, \
	bool friendly) : AEntity(y, x, tickLimit, size), _score(score), _hp(hp), \
	_friendly(friendly) {

}

APhysic::~APhysic(void) {

}

int		APhysic::getSize() const {
	return (this->_size);
}

bool	APhysic::isFriendly() const {
	return (this->_friendly);
}

void		APhysic::clearForm(APhysic* map[GAME_HEIGHT][GAME_WIDTH], t_pos oldpos) {
	int			i = -1;
	APhysic **	cell;

	while (++i < this->_size * this->_size) {
		if (this->_y + i / this->_size > GAME_HEIGHT \
				|| this->_x + i % this->_size >= GAME_WIDTH)
			continue ;
		cell = &(map[oldpos.y + i / this->_size][oldpos.x + i % this->_size]);
		if (*cell == this)
			*cell = NULL;
	}
}

t_collision	APhysic::checkCollision(APhysic* map[GAME_HEIGHT][GAME_WIDTH]) {
	int			i = -1;
	APhysic **	cell;

	while (++i < this->_size * this->_size) {
		if (this->_form[(i / this->_size) * this->_size + i % this->_size] == 0 \
				|| this->_y + i / this->_size >= GAME_HEIGHT \
				|| this->_x + i % this->_size >= GAME_WIDTH)
			continue ;
		cell = &(map[this->_y + i / this->_size][this->_x + i % this->_size]);
		if (*cell != NULL && *cell != this)
			return (this->collide(*cell));
	}
	i = -1;
	while (++i < this->_size * this->_size) {
		if (!this->_form[(i / this->_size) * this->_size + i % this->_size] \
				|| this->_y + i / this->_size >= GAME_HEIGHT \
				|| this->_x + i % this->_size >= GAME_WIDTH)
			continue ;
		map[this->_y + i / this->_size][this->_x + i % this->_size] = this;
	}

	t_collision	res;
	res.is_damaged = false;
	res.other_body_damaged = NULL;
	return (res);
}

t_collision	APhysic::collide(APhysic* body) {
	t_collision	res;
	bool		otherFriendly = body->isFriendly();
	int			otherSize = body->getSize();

	res.is_damaged = true;
	res.other_body_damaged = body;
	if (otherFriendly == this->_friendly) {
		if (otherSize < this->_size)
			res.is_damaged = false;
		else
			res.other_body_damaged = NULL;
	}
	return (res);
}


bool		APhysic::takeDamage(int damage) {
	this->_hp -= damage;
	if (this->_hp <= 0)
		return (true);
	return (false);
}

int			APhysic::getScore(void) const {
	return (this->_score);
}
