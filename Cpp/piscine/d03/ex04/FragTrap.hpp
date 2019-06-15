/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 10:25:30 by tbehra            #+#    #+#             */
/*   Updated: 2019/05/23 21:07:53 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLAGTRAP_HPP
# define FLAGTRAP_HPP

# include "ClapTrap.hpp"

# define ENERGY_VAULT 25

class FragTrap : public virtual ClapTrap {

	public:
		FragTrap(std::string name);
		~FragTrap(void);
		FragTrap(FragTrap const & f);
		void vaulthunter_dot_exe(std::string const & target);
};

const std::string flagtrap_constructor_quotes[QUOTES] = {
	"Hey everybody! Check out my package!",
	"Let's get this party started!",
	"Glitching weirdness is a term of endearment, right?",
	"Recompiling my combat code!",
	"This time it'll be awesome, I promise!",
	"Look out everybody! Things are about to get awesome!"
};

const std::string flagtrap_destructor_quotes[QUOTES] = {
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

const std::string flagtrap_death_quotes[QUOTES] = {
	"Oh, quit falling to pieces.",
	"Is that what people look like inside?",
	"Ooh, squishy bits!",
	"Meat confetti!",
	"Huh, robot's don't do that.",
	"Personfetti."
};

#endif
