/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 18:36:22 by tbehra            #+#    #+#             */
/*   Updated: 2019/05/24 22:53:21 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {
}

Ice::~Ice() {

}

Ice::Ice(Ice const & ice) : AMateria(ice){
	*this = Ice(ice);
	return;
}

Ice & Ice::operator=(Ice const & ice) {
	this->xp_ = ice.getXP();
	return *this;
}

void Ice::use(ICharacter & target) {
	AMateria::use(target);
	std::cout << "* shoots an ice bolt at "
		<< target.getName() <<" *" << std::endl;
}

Ice *Ice::clone(void) const{
	Ice *newIce = new Ice;
	newIce->setXP(this->getXP());
	return newIce;
}
