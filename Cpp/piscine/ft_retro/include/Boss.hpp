/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Boss.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 16:21:54 by tbehra            #+#    #+#             */
/*   Updated: 2019/05/26 18:47:45 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BOSS_HPP 
# define BOSS_HPP

# include "const.hpp"
# include "APhysic.hpp"
# include "AlienWeapon.hpp"

class AlienWeapon;

class Boss : public APhysic {
public:
	Boss(AlienWeapon * weapon, Game & game);
	~Boss(void);

	virtual void		display(int offsetY, int offsetX) const;
	virtual t_pos		update(void);

private:
	int				_tickShoot;
	int				_tickLimitShoot;
	AlienWeapon * 	_weapon;
	bool			_updateTickShoot(void);
	Game	&		_game;

	Boss(Boss const & ent);

	Boss(void);
	Boss &			operator =(Boss const & ent);
};

#endif
