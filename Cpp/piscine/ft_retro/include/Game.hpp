/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 10:37:49 by gsmith            #+#    #+#             */
/*   Updated: 2019/05/26 19:07:46 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_HPP
# define GAME_HPP

# include "const.hpp"
# include "AEntity.hpp"
# include "APhysic.hpp"
# include "ABackground.hpp"
# include "Spaceship.hpp"
# include "EnemyGenerator.hpp"
# include "BackgroundGenerator.hpp"
# include "Projectile.hpp"
# include "AlienWeapon.hpp"
# include "Boss.hpp"
# include <stdlib.h>

typedef struct	s_input t_input;

class EnemyGenerator;
class BackgroundGenerator;
class AlienWeapon;

class Game {
public:
	Game(void);
	~Game(void);

	void			setBossFight(int bf);
	void			setCountDown(int cd);
	void			setScoreTriggerBoss(int score);
	void			pushProjectile(Projectile *p);
	void			run(int height, int width);
	AlienWeapon		*_alienWeapon;

private:
	Game(Game const & ent);

	Game &			operator =(Game const & ent);


	EnemyGenerator		*_genEnemy;
	BackgroundGenerator	*_genBckgrnd;
	bool				_run;
	int					_limitBodies;
	int					_limitBck;
	Spaceship			*_playerShip;
	APhysic				**_bodies;
	ABackground			**_backgrounds;
	APhysic				*_map[GAME_HEIGHT][GAME_WIDTH];
	int					_score;
	int					_offsetY;
	int					_offsetX;
	int					_reloadTime;
	int					_bossFight;
	int					_bossCountDown;
	int					_scoreTriggerBoss;

	void				_pushBody(APhysic *ent);
	void				_pushBackground(ABackground *bck);
	int					_getBodyIndex(APhysic *ent) const;
	void				_readInput(void);
	void				_damageBody(APhysic **bdy_ptr);
	void				_updateBackground(void);
	void				_updateEntities(void);
	void				_displayHUD(void);
	void				_refreshDisplay(void);
	void				_quit(int key);
	void				_shoot(int key);
	void				_move(int key);
};

typedef struct	s_input {
	int		key;
	void	(Game::*callback)(int);
}				t_input;

#endif
