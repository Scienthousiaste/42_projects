/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 15:13:59 by tbehra            #+#    #+#             */
/*   Updated: 2019/05/23 19:11:31 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_H
# define SCAVTRAP_H

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {

	public:
		ScavTrap(std::string name);
		~ScavTrap(void);
		ScavTrap(ScavTrap const & f);

		void challengeNewcomer(std::string const & target);
};

const std::string scavtrap_constructor_quotes[QUOTES] = {
	"Hey everybody! Check out my package!",
	"Let's get this party started!",
	"Glitching weirdness is a term of endearment, right?",
	"Recompiling my combat code!",
	"This time it'll be awesome, I promise!",
	"Look out everybody! Things are about to get awesome!"
};

const std::string scavtrap_destructor_quotes[QUOTES] = {
	"What is that smell? Oh, never mind... it's just you!",
	"I'm leaking!",
	"Good thing I don't have a soul!",
	"Aww!",
	"Aww! Come on!",
	"You can't kill me!",
};

const std::string challenges_quotes[QUOTES] = {
	"You versus me! Me versus you! Either way!",
	"I will prove to you my robotic superiority!",
	"Dance battle! Or, you know... regular battle.",
	"Man versus machine! Very tiny streamlined machine!",
	"Care to have a friendly duel?",
	"Did you know you can't use your tongue to lick your tongue?",
};

const std::string scavtrap_death_quotes[QUOTES] = {
	"There is now gunk on my chassis.",
	"Oooh! Gigabits!",
	"Ooooh! Terrabits!",
	"Meatsplosion!",
	"Flesh fireworks!",
	"Oh, quit falling to pieces."
};

#endif
