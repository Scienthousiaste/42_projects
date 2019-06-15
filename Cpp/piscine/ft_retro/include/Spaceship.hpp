/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Spaceship.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <tbehra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 14:01:50 by tbehra            #+#    #+#             */
/*   Updated: 2019/05/26 18:39:02 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPACESHIP_HPP
# define SPACESHIP_HPP

#include <ncurses.h>
# include "const.hpp"
#include "APhysic.hpp"

class Spaceship : public APhysic {

public:
	Spaceship(void);
	~Spaceship(void);

	virtual void	display(int offsetY, int offsetX) const;
	virtual t_pos	update(void);
	void			requireMove(int input);
	int				getHP(void) const;

private:
	bool	_readyToMove;
	int		_direction;
	bool	_halfVertical;

	Spaceship & operator=(Spaceship const & s);
	Spaceship (Spaceship const & s);
};


#endif
