/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 11:34:53 by tbehra            #+#    #+#             */
/*   Updated: 2019/05/21 12:57:19 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIEHORDE_H
# define ZOMBIEHORDE_H

# include <iostream>
# include <ctime>
# include "Zombie.hpp"

# define NB_NAME_PARTS 10

class ZombieHorde {
	
public: 
	ZombieHorde(int N);
	~ZombieHorde(void);
	void announce(void) const;

private:
	int _N;
	Zombie *_horde;
};


#endif
