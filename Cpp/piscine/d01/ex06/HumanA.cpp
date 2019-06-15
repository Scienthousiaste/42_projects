/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 14:49:22 by tbehra            #+#    #+#             */
/*   Updated: 2019/05/21 15:00:44 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) :
	_weapon(weapon),
	_name(name)	{
}

HumanA::~HumanA(void) {
}

void HumanA::attack(void) const {
	std::cout << this->_name << " attacks with his "
		<< this->_weapon.getType() << std::endl;
}
