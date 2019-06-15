/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConvertor.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 13:39:36 by tbehra            #+#    #+#             */
/*   Updated: 2019/05/28 15:18:24 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConvertor.hpp"


ScalarConvertor::ScalarConvertor(std::string raw) : 
	_raw(raw) {
	
}

ScalarConvertor::~ScalarConvertor(void) {
}

char ScalarConvertor::charConversion(void) {
	std::string raw = this->_raw;

	if (raw.length() == 3 && raw[0] == '\'' && raw[2] == '\'')
		return raw[1];

	return '\0';
}


void ScalarConvertor::printConversions(void) {
	char c;
	int i;
	float f;
	double d;

	c = 0;
	
	std::string raw = this->_raw;
	if (raw.length() == 3 && raw[0] == '\'' && raw[2] == '\'') {
		c = raw[1];
		i = static_cast<int> (c);
		f = static_cast<float> (i);
		d = static_cast<double> (f);
	}


	try {
		std::cout << "char: '" << c << "'" << std::endl;
	}
	catch (std::exception e) {
		std::cout << "char: impossible (" << e.what() << ")" << std::endl;
	}
	/*
	try {
		std::cout << "int: " << this->intConversion() << std::endl;
	}
	catch (std::exception e) {
		std::cout << "int: impossible (" << e.what() << ")" << std::endl;
	}
	try {
		std::cout << "float: " << this->floatConversion() << std::endl;
	}
	catch (std::exception e) {
		std::cout << "float: impossible (" << e.what() << ")" << std::endl;
	}
	try {
		std::cout << "double: " << this->doubleConversion() << std::endl;
	}
	catch (std::exception e) {
		std::cout << "double: impossible (" << e.what() << ")" << std::endl;
	}*/
}


