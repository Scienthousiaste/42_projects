/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BackgroundGenerator.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 14:54:52 by gsmith            #+#    #+#             */
/*   Updated: 2019/05/26 14:57:57 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BackgroundGenerator.hpp"
#include "DistantStar.hpp"

BackgroundGenerator::BackgroundGenerator(int tickLimit) :
	AGameEvent(tickLimit) {
	srand (time(NULL));
}

BackgroundGenerator::~BackgroundGenerator(void) {

}

ABackground *	BackgroundGenerator::trigger(void) {
	return (new DistantStar(0, rand() % GAME_WIDTH));
}
