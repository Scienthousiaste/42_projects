/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Asteroid.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 11:34:24 by gsmith            #+#    #+#             */
/*   Updated: 2019/05/26 13:02:25 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASTEROID_HPP
# define ASTEROID_HPP

# include "const.hpp"
# include "APhysic.hpp"

class Asteroid : public APhysic {
public:
	Asteroid(int y, int x);
	virtual ~Asteroid(void);


	virtual void		display(int offsetY, int offsetX) const;
	virtual t_pos		update(void);
	Asteroid(Asteroid const & ent);

private:
	Asteroid(void);

	Asteroid &			operator =(Asteroid const & ent);
};

#endif
