/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DistantStar.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 14:36:42 by gsmith            #+#    #+#             */
/*   Updated: 2019/05/26 14:39:58 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISTANTSTAR_HPP
# define DISTANTSTAR_HPP

# include "const.hpp"
# include "ABackground.hpp"

class DistantStar : public ABackground {
public:
	DistantStar(int y, int x);
	virtual ~DistantStar(void);

	virtual void		display(int offsetY, int offsetX) const;
	virtual t_pos		update(void);

private:
	DistantStar(void);
	DistantStar(DistantStar const & ent);

	DistantStar &			operator =(DistantStar const & ent);
};

#endif
