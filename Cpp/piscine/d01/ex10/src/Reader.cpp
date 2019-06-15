/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Reader.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 10:43:15 by tbehra            #+#    #+#             */
/*   Updated: 2019/05/22 11:29:55 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Reader.hpp"

Reader::Reader(void) {

}

Reader::~Reader(void) {

}

void Reader::cat_file(std::string s) const {
	std::ifstream stream(s);
	
	if (stream.is_open()) {
		std::cout << stream.rdbuf();	
	}
	else {
		std::cout << "Couldn't open file " << s << std::endl;
	}
}

void Reader::cat_console(void) const {
	std::cout << std::cin.rdbuf();
}
