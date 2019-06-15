/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Explosion.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 18:50:23 by gsmith            #+#    #+#             */
/*   Updated: 2019/05/26 19:20:56 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPLOSION_HPP
# define EXPLOSION_HPP

# include "const.hpp"
# include "ABackground.hpp"

class Explosion : public ABackground {
public:
	Explosion(int y, int x, int start);
	virtual ~Explosion(void);

	virtual void		display(int offsetY, int offsetX) const;
	virtual t_pos		update(void);

private:
	Explosion(void);
	Explosion(Explosion const & ent);

	Explosion &			operator =(Explosion const & ent);

	int					_frame;
};

#endif
