/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AlienShip.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 11:59:36 by tbehra            #+#    #+#             */
/*   Updated: 2019/05/26 15:11:50 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALIENSHIP_HPP
# define ALIENSHIP_HPP

# include "const.hpp"
# include "APhysic.hpp"
# include "AlienWeapon.hpp"

class AlienShip : public APhysic {
public:
	AlienShip(int y, int x, AlienWeapon * weapon);
	virtual ~AlienShip(void);

	virtual void		display(int offsetY, int offsetX) const;
	virtual t_pos		update(void);
	AlienShip(AlienShip const & ent);

private:
	int				_tickShoot;
	int				_tickLimitShoot;
	AlienWeapon * 	_weapon;
	bool			_updateTickShoot(void);

	AlienShip(void);
	AlienShip &			operator =(AlienShip const & ent);
};

#endif
