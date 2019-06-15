/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AEntity.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 10:38:00 by gsmith            #+#    #+#             */
/*   Updated: 2019/05/26 14:34:00 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AENTITY_HPP
# define AENTITY_HPP

# include "const.hpp"

class AEntity {
public:
	AEntity(int y, int x, int tickLimit, int size);
	virtual ~AEntity(void);

	virtual void		display(int offsetY, int offsetX) const = 0;
	virtual t_pos		update(void) = 0;
	t_pos				getPos(void);

protected:
	int				_y;
	int				_x;
	int				_size;
	char *			_form;

	bool			_updateTick(void);

private:
	AEntity(void);
	AEntity(AEntity const & ent);

	AEntity &			operator =(AEntity const & ent);

	int				_tick;
	int const		_tickLimit;
};

#endif
