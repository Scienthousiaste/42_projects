/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TacticalMarine.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 16:12:22 by tbehra            #+#    #+#             */
/*   Updated: 2019/05/24 18:00:54 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TacticalMarine.hpp"

TacticalMarine::TacticalMarine() {
	std::cout << "Tactical Marine ready for battle" << std::endl;
}

TacticalMarine::~TacticalMarine() {
	std::cout << "Aaargh ..." << std::endl;
}

TacticalMarine* TacticalMarine::clone() const {
	return(new TacticalMarine(*this));
}

TacticalMarine::TacticalMarine(TacticalMarine const & m) {
	(void)m;
	std::cout << "Tactical Marine ready for battle" << std::endl;
}

TacticalMarine & TacticalMarine::operator=(TacticalMarine const & m) {
	(void)m;
	return *this;
}

void TacticalMarine::battleCry() const {
	std::cout << "For the holy PLOT !" << std::endl;
}
void TacticalMarine::rangedAttack() const {
	std::cout << "* attacks with bolter *" << std::endl;
}
void TacticalMarine::meleeAttack() const {
	std::cout << "* attacks with chainsword *" << std::endl;
}

