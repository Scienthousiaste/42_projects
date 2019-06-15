/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BigAsteroid.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <tbehra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 16:44:00 by tbehra            #+#    #+#             */
/*   Updated: 2019/05/26 13:34:59 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef BIG_ASTEROID_HPP
# define BIG_ASTEROID_HPP

# include "const.hpp"
# include "APhysic.hpp"

class BigAsteroid : public APhysic {
public:
	BigAsteroid(int y, int x);
	virtual ~BigAsteroid(void);


	virtual void		display(int offsetY, int offsetX) const;
	virtual t_pos		update(void);

private:
	BigAsteroid(void);
	BigAsteroid(BigAsteroid const & ent);

	BigAsteroid &			operator =(BigAsteroid const & ent);
};

#endif
