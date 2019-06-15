/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Boss.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <tbehra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 16:23:48 by tbehra            #+#    #+#             */
/*   Updated: 2019/05/26 19:34:36 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Boss.hpp"
#include <string>

Boss::Boss(AlienWeapon * weapon, Game & game) :
		APhysic(0, GAME_WIDTH / 2 - 18, TICK_BOSS, 36,
			SCORE_BOSS, HP_BOSS, false),
		_tickShoot(0),
		_tickLimitShoot(TICK_SHOOT_BOSS),
		_weapon(weapon),
		_game(game) {

	std::strcpy(&this->_form[0], "\\_____/\\_____/       \\_____/\\_____/");
	std::strcpy(&this->_form[this->_size],"  \\V/    \\V/ |       | \\V/     \\V/  ");
	std::strcpy(&this->_form[this->_size * 2],"              \\_____/               ");
	std::strcpy(&this->_form[this->_size * 3],"                \\O/                 ");

	for (int i = 0; i < this->_size * 4; i++) {
		this->_form[i] = this->_form[i] == ' ' ? 0 : this->_form[i];
	}
}

Boss::~Boss(void) {
	this->_game.setBossFight(0);
	this->_game.setCountDown(BOSS_COUNTDOWN);
	this->_game.setScoreTriggerBoss(SCORE_TRIGGER_BOSS);
}

void				Boss::display(int offsetY, int offsetX) const {
	int i = -1;

	attron(COLOR_PAIR(COLOR_PAIR_ALSHIP));
	while (++i < (this->_size * this->_size))
		if (this->_form[i])
			mvaddch(this->_y + i / this->_size + offsetY, \
					this->_x + i % this->_size + offsetX, \
					this->_form[i]);
	attroff(COLOR_PAIR(COLOR_PAIR_ALSHIP));
}

bool				Boss::_updateTickShoot(void) {
	this->_tickShoot++;
	if (this->_tickShoot >= this->_tickLimitShoot) {
		this->_tickShoot = 0;
		return true;
	}
	return false;
}

t_pos				Boss::update(void) {
	t_pos	pos;
	t_pos	pos_shoot;
	int		r;

	if (this->_updateTick()) {
		this->_x += (rand() % 2) ? 1 : -1;
		this->_x = (this->_x < 0) ? 1 : this->_x;
		this->_x = this->_x > (GAME_WIDTH - this->_size) ? GAME_WIDTH - this->_size - 1 : this->_x;
	}

	pos.y = this->_y;
	pos.x = this->_x;
	if (this->_updateTickShoot()) {
		r = rand() % 5;

		pos_shoot.y = pos.y + 3;
		if (r < 2)
			pos_shoot.x = pos.x + BOSS_OFFSET_SHOOT + ((r == 2)? 8 : 0);
		else if (r > 2)
			pos_shoot.x = pos.x + this->_size - BOSS_OFFSET_SHOOT - ((r == 4)? 8 : 0);
		if (r == 2) {
			pos_shoot.x = pos.x + this->_size / 2;
			pos_shoot.y = pos.y + 5;
		}

		this->_weapon->shoot(pos_shoot);
	}
	return (pos);
}
