/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ABackground.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 13:43:53 by gsmith            #+#    #+#             */
/*   Updated: 2019/05/26 15:16:16 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ABackground.hpp"

ABackground::ABackground(int y, int x, int tickLimit, int size) : \
	AEntity(y, x, tickLimit, size) {

}

ABackground::~ABackground(void) {

}

int				ABackground::getSize(void) const {
	return (this->_size);
}
