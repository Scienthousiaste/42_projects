/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 18:36:22 by tbehra            #+#    #+#             */
/*   Updated: 2019/05/24 22:59:02 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {
}

Cure::~Cure() {

}

Cure::Cure(Cure const & cure) : AMateria(cure) {
	*this = Cure(cure);
	return;
}

Cure & Cure::operator=(Cure const & cure) {
	this->xp_ = cure.getXP();
	return *this;
}

void Cure::use(ICharacter & target) {
	AMateria::use(target);
	std::cout << "* heals " << target.getName()
		<< "'s wounds *" << std::endl;
}

Cure *Cure::clone(void) const {
	Cure *newCure = new Cure;
	newCure->setXP(this->getXP());
	return newCure;
}
