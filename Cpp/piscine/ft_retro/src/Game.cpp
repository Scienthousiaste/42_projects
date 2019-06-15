/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 10:37:46 by gsmith            #+#    #+#             */
/*   Updated: 2019/05/26 19:28:45 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include <unistd.h>
#include <ctime>
#include "Game.hpp"
#include "Explosion.hpp"
#include "DistantStar.hpp"
#include "Spaceship.hpp"
#include "Projectile.hpp"

Game::Game(void) : _run(true), \
	_limitBodies(GAME_LIMITBODIES), _limitBck(GAME_LIMITBCKGRND), \
	_playerShip(new Spaceship()), _bodies(new APhysic*[GAME_LIMITBODIES]), \
	_backgrounds(new ABackground*[GAME_LIMITBCKGRND]), _score(0), _offsetY(0), \
	_offsetX(0), _reloadTime(0), _bossFight(0), _bossCountDown(BOSS_COUNTDOWN),\
	_scoreTriggerBoss(SCORE_TRIGGER_BOSS){
	this->_genEnemy = new EnemyGenerator(SPAWN_ENEMY, *this);
	this->_alienWeapon = new AlienWeapon(*this);
	this->_genBckgrnd = new BackgroundGenerator(SPAWN_BACKGROUND);

	int		i = -1;
	while (++i < GAME_LIMITBODIES) {
		this->_bodies[i] = NULL;
	}
	i = -1;
	while (++i < GAME_WIDTH * GAME_HEIGHT) {
		this->_map[i / GAME_WIDTH][i % GAME_WIDTH] = NULL;
	}
	i = -1;
	while (++i < GAME_LIMITBCKGRND) {
		this->_backgrounds[i] = NULL;
	}
	i = -1;
	while (++i < GAME_HEIGHT / (SPAWN_BACKGROUND / TICK_DISTANTSTAR)) {
		this->_pushBackground(new DistantStar(i * \
			(SPAWN_BACKGROUND / TICK_DISTANTSTAR), rand() % GAME_WIDTH));
	}
	this->_pushBody(this->_playerShip);
}

Game::~Game(void) {
	int		i = -1;
	while (++i < this->_limitBodies) {
		delete this->_bodies[i];
	}
	delete [] this->_bodies;
	i = -1;
	while (++i < this->_limitBck) {
		delete this->_backgrounds[i];
	}
	delete [] this->_backgrounds;
	delete this->_genBckgrnd;
	delete this->_genEnemy;
	delete this->_alienWeapon;
}

void			Game::run(int height, int width) {
	long double		frame;
	this->_offsetY = (height - GAME_HEIGHT) / 2;
	this->_offsetX = (width - GAME_WIDTH) / 2;
	while (this->_run) {
		frame = time(0);
		this->_readInput();
		this->_updateEntities();
		this->_refreshDisplay();
		usleep(GAME_FREQ - (time(0) - frame));
	}
}

void			Game::_pushBody(APhysic *ent) {
	int 		i = -1;

	while (++i < this->_limitBodies) {
		if (this->_bodies[i] == NULL) {
			this->_bodies[i] = ent;
			return ;
		}
	}
	int newLimitBodies = this->_limitBodies * 2;
	APhysic ** newBodies = new APhysic*[newLimitBodies];
	i = -1;
	while (++i < this->_limitBodies) {
		newBodies[i] = this->_bodies[i];
	}
	newBodies[i] = ent;
	while (++i < newLimitBodies) {
		newBodies[i] = NULL;
	}
	this->_limitBodies = newLimitBodies;
	delete [] this->_bodies;
	this->_bodies = newBodies;
}

void			Game::_pushBackground(ABackground *bck) {
	int 		i = -1;

	while (++i < this->_limitBck) {
		if (this->_backgrounds[i] == NULL) {
			this->_backgrounds[i] = bck;
			return ;
		}
	}
	int newLimitBck = this->_limitBck * 2;
	ABackground ** newBackground = new ABackground*[newLimitBck];
	i = -1;
	while (++i < this->_limitBck) {
		newBackground[i] = this->_backgrounds[i];
	}
	newBackground[i] = bck;
	while (++i < newLimitBck) {
		newBackground[i] = NULL;
	}
	this->_limitBck = newLimitBck;
	delete [] this->_backgrounds;
	this->_backgrounds = newBackground;
}

void			Game::pushProjectile(Projectile *p) {
	this->_pushBody(p);
}

int				Game::_getBodyIndex(APhysic *ent) const {
	int		j = -1;

	while (++j < this->_limitBodies) {
		if (ent == this->_bodies[j]) {
			return (j);
		}
	}
	return (-1);
}

void			Game::_readInput(void) {
	static t_input	input[6] = {{'q', &Game::_quit}, {' ', &Game::_shoot}, \
		{KEY_UP, &Game::_move}, {KEY_DOWN, &Game::_move}, \
		{KEY_LEFT, &Game::_move}, {KEY_RIGHT, &Game::_move}};
	int			i;
	int			ch;

	if ((ch = getch()) != ERR) {
		i = -1;
		while (++i < 6) {
			if (ch == input[i].key) {
				(this->*input[i].callback)(ch);
			}
		}
		if (ch == 'q')
			this->_run = false;
	}
}

void			Game::_damageBody(APhysic **bdy_ptr) {
	APhysic *	body = *bdy_ptr;
	t_pos		pos = body->getPos();
	int			size = body->getSize();
	int			i = -1;

	if (!body->takeDamage(DMG_SIMPLE))
		return ;
	if (body == this->_playerShip) {
		this->_playerShip = NULL;
		this->_quit(0);
		return ;
	}
	while (++i < size * size) {
		if (body == this->_map[pos.y + i / size][pos.x + i % size])
			this->_pushBackground(new Explosion(pos.y + i / size, \
				pos.x + i % size, rand()));
	}
	body->clearForm(this->_map, pos);
	this->_score += body->getScore();
	delete body;
	*bdy_ptr = NULL;
}


void			Game::_updateBackground(void) {
	t_pos		newpos;
	t_pos		oldpos;
	int			size;
	int			i = -1;

	while (++i < this->_limitBck) {
		if (this->_backgrounds[i] != NULL) {
			oldpos = this->_backgrounds[i]->getPos();
			newpos = this->_backgrounds[i]->update();
			if (oldpos.x == newpos.x && oldpos.y == newpos.y)
				continue ;
			size = this->_backgrounds[i]->getSize();
			if (newpos.y + size - 1 < 0 || newpos.y >= GAME_HEIGHT) {
				delete this->_backgrounds[i];
				this->_backgrounds[i] = NULL;
				continue ;
			}
		}
	}
}

void			Game::_updateEntities(void) {
	t_pos		newpos;
	t_pos		oldpos;
	t_collision	crash;
	int			size;
	int			i = -1;
	int			j;

	while (++i < this->_limitBodies) {
		if (this->_bodies[i] != NULL) {
			oldpos = this->_bodies[i]->getPos();
			newpos = this->_bodies[i]->update();
			if (oldpos.x == newpos.x && oldpos.y == newpos.y)
				continue ;
			size = this->_bodies[i]->getSize();
			this->_bodies[i]->clearForm(this->_map, oldpos);
			if (newpos.y + size - 1 < 0 || newpos.y >= GAME_HEIGHT) {
				delete this->_bodies[i];
				this->_bodies[i] = NULL;
				continue ;
			}
			crash = this->_bodies[i]->checkCollision(this->_map);
			if (crash.is_damaged)
				this->_damageBody(&this->_bodies[i]);
			if (crash.other_body_damaged != NULL) {
				if ((j = this->_getBodyIndex(crash.other_body_damaged)) != -1) {
					this->_damageBody(&this->_bodies[j]);
				} else
					this->_damageBody(&crash.other_body_damaged);
			}
		}
	}

	if (this->_bossFight < 2 && this->_score >= this->_scoreTriggerBoss) {
		this->_bossFight = 1;
	}
	if (this->_bossFight == 1 && this->_bossCountDown <= 0) {
		this->_bossFight = 2;
		this->_pushBody(new Boss(this->_alienWeapon, *this));
	}

	this->_updateBackground();
	if (this->_reloadTime > 0)
		this->_reloadTime--;

	if (!this->_bossFight) {
		if (this->_genEnemy->_updateTick()) {
			this->_pushBody(this->_genEnemy->trigger());
		}
	}
	else if (this->_bossFight == 1){
		this->_bossCountDown--;
	}
	if (this->_genBckgrnd->_updateTick()) {
		this->_pushBackground(this->_genBckgrnd->trigger());
	}
}

void			Game::_displayHUD(void) {
	attron(COLOR_PAIR(COLOR_PAIR_SCORE));
	mvprintw(GAME_HEIGHT + this->_offsetY, 3 + this->_offsetX, "Score : %i", \
		this->_score);
	mvprintw(GAME_HEIGHT + this->_offsetY + 2, 3 + this->_offsetX, "Vie   : %i", \
		this->_playerShip != NULL ? this->_playerShip->getHP() : 0);
	attroff(COLOR_PAIR(COLOR_PAIR_SCORE));
}

void			Game::_refreshDisplay(void) {
	int		i = -1;

	clear();
	attron(COLOR_PAIR(COLOR_PAIR_BCKGRND));
	while (++i < this->_limitBck) {
		if (this->_backgrounds[i] != NULL) {
			this->_backgrounds[i]->display(this->_offsetY, this->_offsetX);
		}
	}
	attroff(COLOR_PAIR(COLOR_PAIR_BCKGRND));
	i = -1;
	while (++i < GAME_WIDTH * GAME_HEIGHT) {
		if (this->_map[i / GAME_WIDTH][i % GAME_WIDTH] != NULL) {
			mvprintw(i / GAME_WIDTH + this->_offsetY, \
				i % GAME_WIDTH + this->_offsetX, ".");
		}
	}
	i = -1;
	while (++i < this->_limitBodies) {
		if (this->_bodies[i] != NULL) {
			this->_bodies[i]->display(this->_offsetY, this->_offsetX);
		}
	}
	this->_displayHUD();
	refresh();
}

void			Game::setBossFight(int bf) {
	this->_bossFight = bf;
}
void			Game::setCountDown(int cd) {
	this->_bossCountDown = cd;
}
void			Game::setScoreTriggerBoss(int score) {
	this->_scoreTriggerBoss = this->_score + score;
}

void			Game::_quit(int key) {
	(void)key;
	this->_run = false;
}

void			Game::_shoot(int key) {
	(void)key;

	if (this->_reloadTime > 0)
		return ;
	t_pos pos =	this->_playerShip->getPos();
	this->_pushBody(new Projectile(pos.y - 1, pos.x + 1, DIRECTION_UP));
	this->_reloadTime = RELOAD_PLAYER;
}

void			Game::_move(int key) {
	int		direction;
	if (key == KEY_UP)
		direction = DIRECTION_UP;
	else if (key == KEY_DOWN)
		direction = DIRECTION_DOWN;
	else if (key == KEY_LEFT)
		direction = DIRECTION_LEFT;
	else if (key == KEY_RIGHT)
		direction = DIRECTION_RIGHT;
	else
		return ;
	this->_playerShip->requireMove(direction);
}
