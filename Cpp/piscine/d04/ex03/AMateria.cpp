/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 18:36:22 by tbehra            #+#    #+#             */
/*   Updated: 2019/05/24 22:55:37 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(std::string const & type) : xp_(0), type_(type){
}

AMateria::~AMateria() {

}

AMateria::AMateria(AMateria const & a) {
	this->xp_ = a.xp_;
	this->type_ = a.type_;
}

AMateria & AMateria::operator=(AMateria const & a) {
	this->xp_ = a.xp_;
	this->type_ = a.type_;
	return *this;
}

void AMateria::use(ICharacter & target) {
	this->xp_ += 10;
	(void) target;
}


std::string const & AMateria::getType() const {
	return this->type_;
}

unsigned int AMateria::getXP() const {
	return this->xp_;
}

void AMateria::setXP(unsigned int xp) {
	this->xp_ = xp;
}
