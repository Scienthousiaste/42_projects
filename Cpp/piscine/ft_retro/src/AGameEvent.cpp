/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AGameEvent.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 18:28:14 by tbehra            #+#    #+#             */
/*   Updated: 2019/05/25 19:21:01 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AGameEvent.hpp"

AGameEvent::AGameEvent(int tickLimit) :
		_tick(0),
		_tickLimit(tickLimit) {
}

AGameEvent::~AGameEvent(void) {
}

bool	AGameEvent::_updateTick(void) {
	this->_tick++;
	if (this->_tick >= this->_tickLimit) {
		this->_tick = 0;
		return (true);
	}
	return (false);
}
