/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   const.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 18:20:00 by gsmith            #+#    #+#             */
/*   Updated: 2019/05/26 19:38:20 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONST_HPP
# define CONST_HPP

# define TICK_PROJECTILE    1
# define TICK_BIG_ASTEROID  12
# define TICK_ASTEROID      7
# define TICK_ALIENSHIP		15
# define TICK_SHOOT_ALIEN	75
# define TICK_SPACESHIP     1
# define TICK_DISTANTSTAR   25
# define TICK_EXPLOSION     5
# define TICK_BOSS			15
# define TICK_SHOOT_BOSS	10

# define FRAME_EXPLOSION    5

# define RELOAD_PLAYER      10

# define BOSS_OFFSET_SHOOT	3

# define SPAWN_ENEMY        50
# define SPAWN_BACKGROUND   100

# define PLAYER_HP          10

# define SCORE_BIGASTEROID  100
# define SCORE_ASTEROID     10
# define SCORE_ALIENSHIP    150
# define SCORE_BOSS			500
# define HP_BIGASTEROID     5
# define HP_ASTEROID        1
# define HP_ALIENSHIP       3
# define HP_BOSS			40

# define BOSS_COUNTDOWN		250
# define SCORE_TRIGGER_BOSS 750

# define DIRECTION_NONE     0
# define DIRECTION_UP       1
# define DIRECTION_DOWN     2
# define DIRECTION_LEFT     3
# define DIRECTION_RIGHT    4

# define GAME_LIMITBODIES   100
# define GAME_LIMITBCKGRND  100
# define GAME_HEIGHT        70
# define GAME_WIDTH         100
# define GAME_FREQ          16666

# define DMG_SIMPLE         1

# define COLOR_GRAY         50
# define COLOR_RED_D        51
# define COLOR_GREEN_D      52
# define COLOR_BLUE_D       53
# define COLOR_RED_B        54
# define COLOR_GREEN_B      55
# define COLOR_BLUE_B       56

# define COLOR_PAIR_SCORE   1
# define COLOR_PAIR_BCKGRND 2
# define COLOR_PAIR_ASTERO  3
# define COLOR_PAIR_ALSHIP  4
# define COLOR_PAIR_SPSHIP  5
# define COLOR_PAIR_PROJ_R  6
# define COLOR_PAIR_PROJ_G  7
# define COLOR_PAIR_PROJ_B  8
# define COLOR_PAIR_EXPLOD  9


typedef struct 				s_pos {
	int						x;
	int						y;
}							t_pos;

#endif
