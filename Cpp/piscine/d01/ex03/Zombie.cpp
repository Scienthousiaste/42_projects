/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 09:57:45 by tbehra            #+#    #+#             */
/*   Updated: 2019/05/21 12:42:43 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie (void) {
}

Zombie::~Zombie (void) {
	std::cout << this->_name << " is dead. Again." << std::endl;
}

void Zombie::init_zombie(std::string name, std::string type) {
	this->_name = name;
	this->_type = type;
}

void Zombie::announce(void) const {
	std::cout << this->_name << " (" << this->_type << " zombie) has something to share "
	 << "to enlighten us:" << std::endl <<	"\t\"Braaaaaaiiiiinns..\"" << std::endl;
}
