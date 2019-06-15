/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PlasmaRifle.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 12:48:29 by tbehra            #+#    #+#             */
/*   Updated: 2019/05/24 23:38:58 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PlasmaRifle.hpp"

PlasmaRifle::PlasmaRifle() :
   AWeapon("Plasma Rifle", 5, 21) {

}

PlasmaRifle::~PlasmaRifle(void) {
}

PlasmaRifle::PlasmaRifle(PlasmaRifle const & p) : AWeapon(p) {
	*this = PlasmaRifle();
	return;
}

PlasmaRifle & PlasmaRifle::operator=(PlasmaRifle const & w) {
	this->setName(w.getName());
	this->setAPCost(w.getAPCost());
	this->setDamage(w.getDamage());
	return *this;
}

void PlasmaRifle::attack(void) const { 
	std::cout << "* piouuu piouuu piouuu *" << std::endl;
}
