/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AssaultTerminator.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 16:12:22 by tbehra            #+#    #+#             */
/*   Updated: 2019/05/24 18:02:31 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AssaultTerminator.hpp"

AssaultTerminator::AssaultTerminator() {
	std::cout << "* teleports from space *" << std::endl;
}

AssaultTerminator::~AssaultTerminator() {
	std::cout << "I'll be back ..." << std::endl;
}

AssaultTerminator* AssaultTerminator::clone() const {
	return(new AssaultTerminator(*this));
}

AssaultTerminator::AssaultTerminator(AssaultTerminator const & m) {
	(void)m;
	std::cout << "* teleports from space *" << std::endl;
}

AssaultTerminator & AssaultTerminator::operator=(AssaultTerminator const & m) {
	(void) m;
	return *this;
}

void AssaultTerminator::battleCry() const {
	std::cout << "This code is unclean. PURIFY IT !" << std::endl;
}
void AssaultTerminator::rangedAttack() const {
	std::cout << "* does nothing *" << std::endl;
}
void AssaultTerminator::meleeAttack() const {
	std::cout << "* attacks with chainfists *" << std::endl;
}

