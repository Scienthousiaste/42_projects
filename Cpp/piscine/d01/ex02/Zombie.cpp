/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 09:57:45 by tbehra            #+#    #+#             */
/*   Updated: 2019/05/21 10:57:32 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie (std::string name, std::string type) :
	_name(name),
	_type(type){
}

Zombie::~Zombie (void) {
	std::cout << this->_name << " is dead. Again." << std::endl;
}

void Zombie::announce(void) const {
	std::cout << this->_name << " (" << this->_type << " zombie) has something to share "
	 << "to enlighten us:" << std::endl <<	"\t\"Braaaaaaiiiiinns..\"" << std::endl;
}
