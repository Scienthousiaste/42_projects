/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 21:47:55 by tbehra            #+#    #+#             */
/*   Updated: 2019/05/25 00:14:14 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"


MateriaSource::MateriaSource() : IMateriaSource(){
	for (int i = 0; i < INVENTORY_SIZE; i++) {
		this->store_[i] = NULL;
	}
}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < INVENTORY_SIZE; i++) {
		if (this->store_[i])
			delete this->store_[i];
	}
}

MateriaSource::MateriaSource(MateriaSource const & a) {
	*this = MateriaSource(a);
}

MateriaSource & MateriaSource::operator=(MateriaSource const & ms) {
	for (int i = 0; i < INVENTORY_SIZE; i++) {
		this->store_[i] = ms.store_[i];
	}
	return *this;
}

void MateriaSource::learnMateria(AMateria *m) {
	if (!m)
		return;
	for (int i = 0; i < INVENTORY_SIZE; i++) {
		if (!this->store_[i]) {
			this->store_[i] = m;
			break;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const & type) {
	for (int i = 0; i < INVENTORY_SIZE; i++) {
		if (this->store_[i]->getType() == type) {
			return (this->store_[i]->clone());
		}
	}
	return (NULL);
}
