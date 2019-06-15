/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 15:13:59 by tbehra            #+#    #+#             */
/*   Updated: 2019/05/23 19:05:28 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_H
# define SCAVTRAP_H

# include <iostream> 

# define SCAV_QUOTES 6

class ScavTrap {

	public:
		ScavTrap(std::string name);
		~ScavTrap(void);
		ScavTrap(ScavTrap const & f);

		void rangedAttack(std::string const & target);
		void meleeAttack(std::string const & target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		void challengeNewcomer(std::string const & target);
		static void hashQuote(std::string const & entropy,
				std::string const arr_quotes[SCAV_QUOTES],
				std::string func_name);
		ScavTrap & operator=(ScavTrap const & f);

		int getHitPoints(void) const;
		int getMaxHitPoints(void) const;
		int getEnergyPoints(void) const;
		int getMaxEnergyPoints(void) const;
		int getLevel(void) const;
		std::string getName(void) const;
		int getMeleeDamage(void) const;
		int getRangedDamage(void) const;
		int getArmor(void) const;

		void setHitPoints(int n);
		void setMaxHitPoints(int n);
		void setEnergyPoints(int n);
		void setMaxEnergyPoints(int n);
		void setLevel(int n);
		void setName(std::string name);
		void setMeleeDamage(int n);
		void setRangedDamage(int n);
		void setArmor(int n);

	private:
		int _hitPoints;
		int _maxHitPoints;
		int _energyPoints;
		int _maxEnergyPoints;
		int _level;
		std::string _name;
		int _meleeDamage;
		int _rangedDamage;
		int _armor;

};

const std::string scav_constructor_quotes[SCAV_QUOTES] = {
	"Hey everybody! Check out my package!",
	"Let's get this party started!",
	"Glitching weirdness is a term of endearment, right?",
	"Recompiling my combat code!",
	"This time it'll be awesome, I promise!",
	"Look out everybody! Things are about to get awesome!"
};

const std::string scav_destructor_quotes[SCAV_QUOTES] = {
	"What is that smell? Oh, never mind... it's just you!",
	"I'm leaking!",
	"Good thing I don't have a soul!",
	"Aww!",
	"Aww! Come on!",
	"You can't kill me!",
};

const std::string challenges_quotes[SCAV_QUOTES] = {
	"You versus me! Me versus you! Either way!",
	"I will prove to you my robotic superiority!",
	"Dance battle! Or, you know... regular battle.",
	"Man versus machine! Very tiny streamlined machine!", 
	"Care to have a friendly duel?",
	"Did you know you can't use your tongue to lick your tongue?",
};

const std::string scav_death_quotes[SCAV_QUOTES] = {
	"There is now gunk on my chassis.",
	"Oooh! Gigabits!",
	"Ooooh! Terrabits!",
	"Meatsplosion!",
	"Flesh fireworks!",
	"Oh, quit falling to pieces."
};

#endif
