/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   APhysic.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 10:37:53 by gsmith            #+#    #+#             */
/*   Updated: 2019/05/26 10:51:23 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef APHYSIC_HPP
# define APHYSIC_HPP

#include <unistd.h>
# include "const.hpp"
# include "AEntity.hpp"

class APhysic;

typedef struct		s_collision {
	bool		is_damaged;
	APhysic *	other_body_damaged;
}					t_collision;

class APhysic : public AEntity {
public:
	APhysic(int y, int x, int tickLimit, int size, int score, int hp, bool friendly);
	virtual ~APhysic(void);

	int					getSize(void) const;
	bool				isFriendly(void) const;
	void				clearForm(APhysic* map[GAME_HEIGHT][GAME_WIDTH], t_pos oldpos);
	t_collision			checkCollision(APhysic* map[GAME_HEIGHT][GAME_WIDTH]);
	virtual t_collision	collide(APhysic* body);
	virtual bool		takeDamage(int damage);
	int					getScore(void) const;

protected:
	int _score;
	int _hp;

private:
	APhysic(void);
	APhysic(APhysic const & ent);

	APhysic &			operator=(APhysic const & ent);

	bool				_friendly;
};

#endif
