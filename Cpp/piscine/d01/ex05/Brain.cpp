/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 13:05:51 by tbehra            #+#    #+#             */
/*   Updated: 2019/05/21 18:33:47 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <sstream>

Brain::Brain(int thoughts) : _thoughtsAboutDonuts(thoughts) {
	std::cout << "New brain, with " << this->_thoughtsAboutDonuts << " thoughts."
		<< std::endl;
}

Brain::~Brain(void) {

}

std::string Brain::identify(void) const {
	std::stringstream ss;
	ss << std::hex << this;
	return(ss.str());
}
