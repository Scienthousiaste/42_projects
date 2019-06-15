/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 09:08:39 by tbehra            #+#    #+#             */
/*   Updated: 2019/05/21 09:48:47 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.hpp"

void Pony::describe(void) const {
	std::cout << ((this->_is_a_unicorn) ? "Unicorn" : "Normal poney") << " who eats "
		<< this->_favorite_marshmallow << " marshmallows, smells like "
		<< this->_smell << ", has a brightness of " << this->_brightness
		<< " and a cleanliness of " << this->_cleanliness << ((this->_cleanliness 			<= 0) ? " (GROSS!)" : " (JRHNBR!)") << std::endl;
}

void Pony::play(void) const {
	std::cout << "Pony plays! The air fills with a smell of " << this->_smell
		<< std::endl;
}

Pony::Pony(bool is_a_unicorn, std::string favorite_marshmallow, std::string smell,
	             int brightness, int cleanliness) :
	_is_a_unicorn(is_a_unicorn),
	_favorite_marshmallow(favorite_marshmallow),
	_smell(smell),
	_brightness(brightness),
	_cleanliness(cleanliness) {
	std::cout << "Pony Created: "<< std::endl;

	this->describe();
}

Pony::~Pony(void) {
	std::cout << "Let's take a look at the poney brought to the poney smasher:"
		<< std::endl;
	this->describe();
	std::cout << "Pony destroyed" << std::endl;
}


