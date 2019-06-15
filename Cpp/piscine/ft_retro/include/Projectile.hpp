/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Projectile.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <tbehra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 15:21:58 by tbehra            #+#    #+#             */
/*   Updated: 2019/05/26 16:48:03 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROJECTILE_HPP
# define PROJECTILE_HPP

# include "const.hpp"
# include "APhysic.hpp"

class Projectile : public APhysic {
public:
	Projectile(int y, int x, int direction);
	virtual ~Projectile(void);

	virtual void		display(int offsetY, int offsetX) const;
	virtual t_pos		update(void);

private:
	int		_direction;
	int		_color;

	Projectile(void);
	Projectile(Projectile const & p);
	Projectile & operator=(Projectile const & p);
};

#endif
