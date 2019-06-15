/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 13:35:26 by tbehra            #+#    #+#             */
/*   Updated: 2019/05/24 23:47:38 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iostream>
# include <sstream>
# include "AWeapon.hpp"
# include "Enemy.hpp"


class Character {
	
	public:
		Character();
		Character(std::string const & name);
		~Character();
		Character(Character const & c);
		Character & operator=(Character const & c);

		std::string describe() const;
		void recoverAP();	
		void equip(AWeapon* w);
		void attack(Enemy* e);

		std::string getName(void) const;
		int getAP(void) const;
		AWeapon* getWeapon(void) const;
	
	
	protected:
		std::string _name;
		int _AP;
		AWeapon *_weapon;
};

std::ostream & operator<<(std::ostream & o, Character const & c);

#endif
