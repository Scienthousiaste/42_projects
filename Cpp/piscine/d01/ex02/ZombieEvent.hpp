/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 10:05:15 by tbehra            #+#    #+#             */
/*   Updated: 2019/05/21 10:54:10 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_EVENT_H
# define ZOMBIE_EVENT_H

#include <iostream>
#include <ctime>
#include "Zombie.hpp"
# define NB_NAME_PARTS 10

class ZombieEvent {

public:
	ZombieEvent(void);
	~ZombieEvent(void);
	void setZombieType(std::string type);
	Zombie *newZombie(std::string name) const;
	Zombie *randomChump(void) const;

private:
	std::string _type;
};


#endif
