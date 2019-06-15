/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 13:20:12 by tbehra            #+#    #+#             */
/*   Updated: 2019/05/21 13:58:22 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Human.hpp"

Human::Human(void) : _brain(new Brain(42)) {
}

Human::~Human(void) {

}

std::string Human::identify(void) const{
	return (this->_brain->identify());
}

const Brain& Human::getBrain(void) {
	return *(this->_brain);
}
