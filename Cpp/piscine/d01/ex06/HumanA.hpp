/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 14:14:22 by tbehra            #+#    #+#             */
/*   Updated: 2019/05/21 14:54:02 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_H
# define HUMANA_H

# include <iostream>
# include "Weapon.hpp"

class HumanA {

public:
	void attack(void) const;
	HumanA(std::string name, Weapon& weapon);
	~HumanA(void);

private:
	Weapon& _weapon;
	std::string _name;
};

#endif
