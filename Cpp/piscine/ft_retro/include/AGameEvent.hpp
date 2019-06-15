/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AGameEvent.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <tbehra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 17:56:40 by tbehra            #+#    #+#             */
/*   Updated: 2019/05/26 14:58:23 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AGAME_EVENT_HPP
# define AGAME_EVENT_HPP

#include "APhysic.hpp"


class AGameEvent {
public:
	AGameEvent(int tickLimit);
	virtual ~AGameEvent(void);
	virtual AEntity *			trigger() = 0;
	bool			_updateTick(void);

protected:
	int						_tick;
	int const				_tickLimit;

private:
	AGameEvent(void);
	AGameEvent(AGameEvent const & ent);
	AGameEvent &			operator =(AGameEvent const & ent);
};

#endif
