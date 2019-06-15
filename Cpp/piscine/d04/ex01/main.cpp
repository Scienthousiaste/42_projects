/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 12:56:40 by tbehra            #+#    #+#             */
/*   Updated: 2019/05/24 23:50:51 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AWeapon.hpp"
#include "PlasmaRifle.hpp"
#include "RadScorpion.hpp"
#include "PowerFist.hpp"
#include "Enemy.hpp"
#include "Character.hpp"
#include "SuperMutant.hpp"

int main()
{
	Character* zaz = new Character("zaz");
	std::cout << *zaz;
	Enemy* b = new RadScorpion();
	AWeapon* pr = new PlasmaRifle();
	AWeapon* pf = new PowerFist();
	zaz->equip(pr);
	std::cout << *zaz;
	zaz->equip(pf);
	zaz->attack(b);
	std::cout << *zaz;
	zaz->equip(pr);
	std::cout << *zaz;
	zaz->attack(b);
	std::cout << *zaz;
	zaz->attack(b);
	std::cout << *zaz;

	Character* Norman = new Character("Norman");
	Norman->equip(pf);
	Enemy* Mutant = new SuperMutant();
	std::cout << *Norman;
	Norman->attack(Mutant);
	std::cout << *Norman;
	zaz->attack(Mutant);
	std::cout << "HP SuperMutant : " << Mutant->getHP() << std::endl;
	zaz->attack(Mutant);
	std::cout << "HP SuperMutant : " << Mutant->getHP() << std::endl;
	zaz->attack(Mutant);
	zaz->attack(Mutant);
	zaz->attack(Mutant);
	zaz->attack(Mutant);
	std::cout << *zaz;
	zaz->recoverAP();
	std::cout << "(zaz recovered AP)" << std::endl;
	std::cout << *zaz;
	zaz->attack(Mutant);

	Norman->attack(Mutant);
	std::cout << *Norman;
	std::cout << *zaz;

	return 0;
}
