/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EnemyGenerator.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <tbehra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 18:30:54 by tbehra            #+#    #+#             */
/*   Updated: 2019/05/26 15:54:00 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_GENERATOR_HPP
# define ENEMY_GENERATOR_HPP

#include "Game.hpp"
#include "AGameEvent.hpp"
#include "AlienWeapon.hpp"
#include <time.h>


class Game;

class EnemyGenerator : public AGameEvent {
public:
	EnemyGenerator(int tickLimit, Game & game);
	virtual ~EnemyGenerator(void);
	virtual APhysic *trigger();

private:
	Game & _game;
	EnemyGenerator(void);
	EnemyGenerator(EnemyGenerator const & ent);
	EnemyGenerator &			operator =(EnemyGenerator const & ent);
};

#endif
