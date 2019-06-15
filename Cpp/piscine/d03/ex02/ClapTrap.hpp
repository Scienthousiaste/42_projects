/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 16:35:20 by tbehra            #+#    #+#             */
/*   Updated: 2019/05/23 19:43:03 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_H 
# define CLAPTRAP_H

# include <iostream> 

# define QUOTES 6
# define DEATH_QUOTES_INDEX 0
# define CONSTRUCTOR_QUOTES_INDEX 1
# define DESTRUCTOR_QUOTES_INDEX 2

class ClapTrap {

	public:
		ClapTrap(std::string name);
		~ClapTrap(void);
		ClapTrap(ClapTrap const & f);

		void rangedAttack(std::string const & target);
		void meleeAttack(std::string const & target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

		static void hashQuote(std::string const & entropy,
				std::string const arr_quotes[QUOTES],
				std::string func_name);
		ClapTrap & operator=(ClapTrap const & f);

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
		const std::string *_quotes[3];

	protected:
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

const std::string claptrap_constructor_quotes[QUOTES] = {
	"Love bullets!",
	"Never fear, sugar!",
	"Nurse Clap is here!",
	"Poof, all better, doll!",
	"Sugar, this won't hurt a bit!",
	"Take these, gorgeous, you'll feel better!",
};

const std::string claptrap_destructor_quotes[QUOTES] = {
	"Crit-i-cal!",
	"I'll stop talking when I'm dead!",
	"I'll die the way I lived: annoying!",
	"Come back here! I'll gnaw your legs off!",
	"This could've gone better!",
	"Ooh yeah, watch me! Watch me go!"
};

const std::string claptrap_death_quotes[QUOTES] = {
	"Exploded!",
	"Eww! Cool.",
	"Heh heh heh, squishy bits!",
	"Disgusting. I love it!",
	"Meatsplosion",
	"Ooooh! Terrabits!",
};



#endif
