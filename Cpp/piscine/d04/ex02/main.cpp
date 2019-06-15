/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 15:59:45 by tbehra            #+#    #+#             */
/*   Updated: 2019/05/24 23:55:57 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TacticalMarine.hpp"
#include "AssaultTerminator.hpp"
#include "Squad.hpp"
#include "ISpaceMarine.hpp"
#include "ISquad.hpp"
#include <iostream>

int main() {
	ISpaceMarine* bob = new TacticalMarine;
	ISpaceMarine* jim = new AssaultTerminator;
	Squad* vlc = new Squad;
	
	vlc->push(bob);
	vlc->push(jim);
	
	vlc->push(jim); //no effect;
	vlc->push(NULL); //no effect;	
	
	
	for (int i = 0; i < vlc->getCount(); ++i)
	{
		ISpaceMarine* cur = vlc->getUnit(i);
		cur->battleCry();
		cur->rangedAttack();
		cur->meleeAttack();
	}

	vlc->push(bob->clone());
	vlc->push(bob->clone());
	vlc->push(bob->clone());

	Squad *vlc2 = new Squad;
	*vlc2 = *vlc;

	delete vlc2;
	delete vlc;
	return 0;
}
