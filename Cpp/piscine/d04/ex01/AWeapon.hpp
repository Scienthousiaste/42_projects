/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWeapon.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 11:42:30 by tbehra            #+#    #+#             */
/*   Updated: 2019/05/24 23:53:39 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AWEAPON_HPP 
# define AWEAPON_HPP

# include <iostream>

class AWeapon {
	
	public:
		AWeapon(std::string const & name, int apcost, int damage);
		virtual ~AWeapon(void);
		AWeapon(AWeapon const & s);
		AWeapon & operator=(AWeapon const & w);

		void virtual attack(void) const = 0;
		std::string virtual getName(void) const;
		int getAPCost(void) const;
		int getDamage(void) const;

		void setName(std::string name);
		void setAPCost(int apcost);
		void setDamage(int damage);

	
	private:
		AWeapon();

	protected:
		std::string _name;
		int _apcost;
		int _damage;

};

#endif
