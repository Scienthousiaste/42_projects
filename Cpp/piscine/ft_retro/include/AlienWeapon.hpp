/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AlienWeapon.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 14:07:42 by tbehra            #+#    #+#             */
/*   Updated: 2019/05/26 15:16:26 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALIENWEAPON_HPP
# define ALIENWEAPON_HPP

# include "Projectile.hpp"
# include "Game.hpp"


class Game;
class AlienWeapon {

public:
	AlienWeapon(Game &);
	~AlienWeapon(void);
	void shoot(t_pos pos);
	bool _updateTickShoot(void);

private:
	Game & _game;
	int _tickShoot;
	int _tickShootLimit;
	AlienWeapon(void);
	AlienWeapon &			operator =(AlienWeapon const & ent);
};

#endif
