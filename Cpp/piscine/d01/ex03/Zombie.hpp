/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 09:57:59 by tbehra            #+#    #+#             */
/*   Updated: 2019/05/21 12:42:46 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
# define ZOMBIE_H

#include <iostream>

class Zombie {

public:
	Zombie(void);
	~Zombie(void);
	void announce(void) const;
	void init_zombie(std::string name, std::string type);

private:
	std::string _name;
	std::string _type;

};

#endif
