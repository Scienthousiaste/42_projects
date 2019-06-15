/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ABackground.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 13:43:57 by gsmith            #+#    #+#             */
/*   Updated: 2019/05/26 15:15:56 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ABACKGROUND_HPP
# define ABACKGROUND_HPP

#include "const.hpp"
#include "AEntity.hpp"

class ABackground: public AEntity {
public:
	ABackground(int y, int x, int tickLimit, int size);
	virtual ~ABackground(void);

	int					getSize(void) const;

private:
	ABackground(void);
	ABackground(ABackground const & ent);

	ABackground &			operator=(ABackground const & ent);
};

#endif
