/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 14:12:44 by tbehra            #+#    #+#             */
/*   Updated: 2019/05/21 15:10:32 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
# define WEAPON_H

# include <string>

class Weapon {

public:
	Weapon(std::string type);
	~Weapon(void);
	void setType(std::string s);
	std::string getType(void) const;

private:
	std::string _type;
};

#endif
