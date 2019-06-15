/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 10:25:30 by tbehra            #+#    #+#             */
/*   Updated: 2019/05/23 20:58:41 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLAGTRAP_H
# define FLAGTRAP_H

# include <iostream> 

# define QUOTES 6
# define ENERGY_VAULT 25

class FragTrap {

	public:
		FragTrap(std::string name);
		~FragTrap(void);
		FragTrap(FragTrap const & f);

		void rangedAttack(std::string const & target);
		void meleeAttack(std::string const & target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		void vaulthunter_dot_exe(std::string const & target);
		static void hashQuote(std::string const & entropy,
				std::string const arr_quotes[QUOTES],
				std::string func_name);
		FragTrap & operator=(FragTrap const & f);

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

const std::string constructor_quotes[QUOTES] = {
	"Hey everybody! Check out my package!",
	"Let's get this party started!",
	"Glitching weirdness is a term of endearment, right?",
	"Recompiling my combat code!",
	"This time it'll be awesome, I promise!",
	"Look out everybody! Things are about to get awesome!"
};

const std::string destructor_quotes[QUOTES] = {
	"I'll die the way I lived: annoying!",
	"Come back here! I'll gnaw your legs off!",
	"You look like something a skag barfed up!",
	"What's that smell? Oh wait, it's just you!",
	"Yo momma's so dumb, she couldn't think of a good ending for this 'yo momma' joke!",
	"You're one screw short of a screw!",
};

const std::string vault_quotes[QUOTES] = {
	"You can't just program this level of excitement!",
	"Glitchy weirdness is term of endearment, right?",
	"Push this button, flip this dongle, voila! Help me!",
	"square the I, carry the 1... YES!",
	"Look out everybody, things are about to get awesome!",
	"Round and around and around she goes!"
};

const std::string death_quotes[QUOTES] = {
	"Oh, quit falling to pieces.",
	"Is that what people look like inside?",
	"Ooh, squishy bits!",
	"Meat confetti!",
	"Huh, robot's don't do that.",
	"Personfetti."
};

#endif
