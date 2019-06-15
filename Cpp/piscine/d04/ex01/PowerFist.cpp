/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PowerFist.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 13:00:37 by tbehra            #+#    #+#             */
/*   Updated: 2019/05/24 13:02:18 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# include "PowerFist.hpp"

PowerFist::PowerFist() :
   AWeapon("Power Fist", 8, 50) {

}

PowerFist::~PowerFist(void) {
}

PowerFist::PowerFist(PowerFist const & p) : AWeapon(p) {
	*this = PowerFist();
	return;
}

PowerFist & PowerFist::operator=(PowerFist const & w) {
	this->setName(w.getName());
	this->setAPCost(w.getAPCost());
	this->setDamage(w.getDamage());
	return *this;
}

void PowerFist::attack(void) const { 
	std::cout << "* pschhh... SBAM! *" << std::endl;
}
