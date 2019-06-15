/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EnemyGenerator.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <tbehra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 18:33:05 by tbehra            #+#    #+#             */
/*   Updated: 2019/05/26 18:43:07 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "EnemyGenerator.hpp"
#include "Asteroid.hpp"
#include "BigAsteroid.hpp"
#include "AlienShip.hpp"

EnemyGenerator::EnemyGenerator(int tickLimit, Game & game) :
	AGameEvent(tickLimit),
	_game(game){
	srand (time(NULL));
}

EnemyGenerator::~EnemyGenerator(void) {

}

APhysic *EnemyGenerator::trigger(void) {
	int probas[3] = {10, 70, 100};
	int sizes[3] = {4, 1, 2};

	int r = rand() % 100;

	if (r <= probas[0]) {
		return new BigAsteroid(0, rand() % (GAME_WIDTH - sizes[0]));
	}
	if (r <= probas[1]) {
		return new Asteroid(0, rand() % GAME_WIDTH);
	}
	return new AlienShip(0, rand() % (GAME_WIDTH - sizes[2]),
			this->_game._alienWeapon);
}
