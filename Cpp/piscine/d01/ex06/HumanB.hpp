/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 15:01:11 by tbehra            #+#    #+#             */
/*   Updated: 2019/05/21 15:08:59 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_H
# define HUMANB_H

# include <iostream>
# include "Weapon.hpp"

class HumanB {

public:
	void attack(void) const;
	HumanB(std::string name);
	~HumanB(void);
	void setWeapon(Weapon& weapon);

private:
	std::string _name;
	Weapon* _weapon;
};

#endif
