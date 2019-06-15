/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 10:08:38 by tbehra            #+#    #+#             */
/*   Updated: 2019/05/21 11:05:27 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieEvent.hpp"

ZombieEvent::ZombieEvent(void) {
	this->_type = "";
	std::cout << "A NEW ZOMBIE EVENT IS UPON US!" << std::endl;
	std::srand(std::time(nullptr));
}

ZombieEvent::~ZombieEvent(void) {
	std::cout << "Pfeww, that zombie event involving " << this->_type
		<< " zombies is over." << std::endl;
}

Zombie *ZombieEvent::newZombie(std::string name) const {
	if (this->_type == "") {
		std::cout << "A type is required for this ZombieEvent to bring a zombie"
			<< std::endl;
		return (NULL);
	}
	return new Zombie(name, this->_type);
}

Zombie *ZombieEvent::randomChump(void) const {
	const std::string name_parts[NB_NAME_PARTS] = {"gu", "zra", "shrhhr", "mgnn",
		"skhriiii", "zzz", "pfff", "rk", "u", "euuu"};
	Zombie *z;
	std::string random_name;

	if (this->_type == "") {
		std::cout << "A type is required for this ZombieEvent to bring a chump"
			<< std::endl;
		return (NULL);
	}

	random_name = name_parts[rand() % NB_NAME_PARTS]
		+ name_parts[rand() % NB_NAME_PARTS];
	
	random_name[0] = random_name[0] - ('a' - 'A');
	z = this->newZombie(random_name);
	z->announce();
	return (z);
}

void ZombieEvent::setZombieType(std::string type) {
	this->_type = type;
}
