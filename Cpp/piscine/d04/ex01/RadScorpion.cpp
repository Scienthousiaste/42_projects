/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RadScorpion.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 13:32:39 by tbehra            #+#    #+#             */
/*   Updated: 2019/05/24 23:52:05 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "RadScorpion.hpp"

RadScorpion::RadScorpion() : Enemy(80, "RadScorpion") { 
	std::cout << "* click click click *" << std::endl;
}

RadScorpion::~RadScorpion(void) {
}

RadScorpion::RadScorpion(RadScorpion const & e) : Enemy(e){
	*this = RadScorpion(e);
	return;
}

RadScorpion & RadScorpion::operator=(RadScorpion const & e) {
	this->setHP(e.getHP());
	this->setType(e.getType());
	return *this;
}

void RadScorpion::dies(void) const {
	std::cout << "* SPROTCH *" << std::endl;
}
