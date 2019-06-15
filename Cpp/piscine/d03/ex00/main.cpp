/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 11:21:05 by tbehra            #+#    #+#             */
/*   Updated: 2019/05/23 20:58:55 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

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
	Alain.beRepaired(50);
	Bobby.vaulthunter_dot_exe("Alain");
	Alain.takeDamage(35);
	Bobby.vaulthunter_dot_exe("Alain");
	Alain.takeDamage(35);
	Bobby.vaulthunter_dot_exe("Alain");
	Alain.takeDamage(35);
	Bobby.vaulthunter_dot_exe("Alain");
	Alan.vaulthunter_dot_exe("Alain");
	Alain.takeDamage(40);
}
