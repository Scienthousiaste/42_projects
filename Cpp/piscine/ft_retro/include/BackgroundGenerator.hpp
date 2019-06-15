/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BackgroundGenerator.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 14:54:58 by gsmith            #+#    #+#             */
/*   Updated: 2019/05/26 15:15:49 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BACKGROUNDGENERATOR_HPP
# define BACKGROUNDGENERATOR_HPP

#include "Game.hpp"
#include "AGameEvent.hpp"
#include <time.h>


class Game;

class BackgroundGenerator : public AGameEvent {
public:
	BackgroundGenerator(int tickLimit);
	virtual ~BackgroundGenerator(void);

	virtual ABackground *	trigger();

private:
	BackgroundGenerator(void);
	BackgroundGenerator(BackgroundGenerator const & ent);
	BackgroundGenerator &			operator =(BackgroundGenerator const & ent);
};

#endif
