/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 10:31:38 by tbehra            #+#    #+#             */
/*   Updated: 2019/05/21 11:24:59 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include "ZombieEvent.hpp"

int main (int ac, char **av) {
	(void) ac;
	(void) av;
	Zombie stackZombie("Stacky", "smelly");
	ZombieEvent z1;
	ZombieEvent *z2;

	stackZombie.announce();
	z1.setZombieType("running");
	z2 = new ZombieEvent();
	z2->setZombieType("crawling");

	Zombie *a = z1.newZombie("Francis");
	a->announce();
	Zombie *b = z1.randomChump();
	Zombie *c = z2->randomChump();
	Zombie *d = z2->newZombie("Gontran");
	d->announce();

	delete a;
	delete b;
	delete c;
	delete d;
	delete z2;
	return (0);
}
