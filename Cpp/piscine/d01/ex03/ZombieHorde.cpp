/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 11:34:44 by tbehra            #+#    #+#             */
/*   Updated: 2019/05/21 12:57:18 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieHorde.hpp"

ZombieHorde::ZombieHorde(int N) : _N(N) {
	int i;
	const std::string name_parts[NB_NAME_PARTS] = {"gu", "zra", "shrhhr", "mgnn",
		"skhriiii", "zzz", "pfff", "rk", "u", "euuu"};
	std::string random_name;
	std::srand(std::time(nullptr));

	this->_horde = new Zombie[N];
	i = 0;
	while (i < this->_N) {
		random_name = name_parts[rand() % NB_NAME_PARTS]
			+ name_parts[rand() % NB_NAME_PARTS];
		random_name[0] = random_name[0] - ('a' - 'A');
		this->_horde[i].init_zombie(random_name, "ugly");
		i++;
	}
}

ZombieHorde::~ZombieHorde(void) {
	delete [] this->_horde;
}

void ZombieHorde::announce(void) const {
	int i;
	
	i = 0;
	while (i < this->_N) {
		this->_horde[i].announce();
		i++;
	}
}
