/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 11:21:05 by tbehra            #+#    #+#             */
/*   Updated: 2019/05/23 21:02:02 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"


void describe(const ClapTrap & c) {
	std::cout << "getHitPoints: " << c.getHitPoints() << std::endl;
	std::cout << "getMaxHitPoints: " << c.getMaxHitPoints() << std::endl;
	std::cout << "getEnergyPoints: " << c.getEnergyPoints() << std::endl;
	std::cout << "getMaxEnergyPoints: " << c.getMaxEnergyPoints() << std::endl;
	std::cout << "getLevel: " << c.getLevel() << std::endl;
	std::cout << "getName: " << c.getName() << std::endl;
	std::cout << "getMeleeDamage: " << c.getMeleeDamage() << std::endl;
	std::cout << "getRangedDamage: " << c.getRangedDamage() << std::endl;
	std::cout << "getArmor: " << c.getArmor() << std::endl;
}

int main(void) {

	FragTrap Alan("Alan");
	FragTrap Bob("Bob");
	FragTrap Alain("Alain");
	FragTrap Bobby("Bobby");


	Bobby.rangedAttack("Bob");
	Bob.takeDamage(Bobby.getRangedDamage());
	Alain.meleeAttack("Bob");
	Bob.takeDamage(Alain.getMeleeDamage());
	Alain.meleeAttack("Bob");
	Bob.takeDamage(Alain.getMeleeDamage());
	Alan.meleeAttack("Bob");
	Bob.takeDamage(Alan.getMeleeDamage());
	Alan.meleeAttack("Bob");
	Bob.takeDamage(Alan.getMeleeDamage());

	Bobby.vaulthunter_dot_exe("Alain");
	Alain.takeDamage(35);
	Bobby.vaulthunter_dot_exe("Alain");
	Alain.takeDamage(35);
	Bobby.vaulthunter_dot_exe("Alain");
	Alain.takeDamage(35);
	Bobby.vaulthunter_dot_exe("Alain");
	Alain.takeDamage(35);
	Bobby.vaulthunter_dot_exe("Alain");
	Alan.vaulthunter_dot_exe("Alain");
	Alain.takeDamage(35);



	ScavTrap Gontran("Gontran");
	ScavTrap Lio("Lio");
	Lio.challengeNewcomer("Gontran");
	Lio.meleeAttack("Gontran");
	Gontran.takeDamage(Lio.getMeleeDamage());
}
