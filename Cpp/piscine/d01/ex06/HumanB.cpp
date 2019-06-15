/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 15:03:05 by tbehra            #+#    #+#             */
/*   Updated: 2019/05/21 15:09:45 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) :
	_name(name), _weapon(NULL)	{
}

HumanB::~HumanB(void) {
}

void HumanB::setWeapon(Weapon& weapon) {
	this->_weapon = &weapon;
}

void HumanB::attack(void) const {
	if (this->_weapon) {
		std::cout << this->_name << " attacks with his "
			<< this->_weapon->getType() << std::endl;
	}
	else {
		std::cout << this->_name << " attacks with no weapon." 
		   << "It's not very effective!.";
	}
}
