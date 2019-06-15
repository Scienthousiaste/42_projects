/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConvertor.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 13:39:36 by tbehra            #+#    #+#             */
/*   Updated: 2019/05/29 20:54:27 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConvertor.hpp"


ScalarConvertor::ScalarConvertor(std::string raw) : 
	_raw(raw), _c(0), _i(0), _f(0.0f), _d(0.0), 
	_c_err(0), _i_err(0), _f_err(0), _d_err(0){
}

ScalarConvertor::~ScalarConvertor(void) {
}

bool ScalarConvertor::_isSpecialDoubleValue(std::string s) const {
	if (s.compare("nan") == 0 || s.compare("inf") == 0 || s.compare("-inf") == 0)
		return true;
	return false;
}
bool ScalarConvertor::_isSpecialFloatValue(std::string s) const {
	if (s.compare("nanf") == 0 || s.compare("inff") == 0 || s.compare("-inff") == 0)
		return true;
	return false;
}

void ScalarConvertor::_print_c(void) {
	std::cout << "char: ";
   	if (this->_c_err == ERR) {
		std::cout << "impossible";
	}
	else if (this->_c_err == NO_DISPLAY) {
		std::cout << "Non displayable";
	}
	else {
		std::cout << "'" << this->_c << "'";
	}
	std::cout << std::endl;
}
void ScalarConvertor::_print_i(void) {
	std::cout << "int: ";
    if (this->_i_err == ERR) {
		std::cout << "impossible";
	}
	else {
		std::cout << this->_i;
	}
	std::cout<< std::endl;
}
void ScalarConvertor::_print_f(void) {
	std::cout << "float: ";
   	if (this->_f_err == ERR) {
		std::cout << "impossible";
	}
	else {
		if (this->_isSpecialDoubleValue(this->_raw)
				|| this->_isSpecialFloatValue(this->_raw)) {
			std::cout << this->_f << "f";
		}
		else {
			std::cout << this->_f << ((std::round(this->_f) == this->_f) ? ".0" : "") << "f";
		}
	}
	std::cout << std::endl;
}
void ScalarConvertor::_print_d(void) {
	std::cout << "double: ";
    if (this->_d_err == ERR) {
		std::cout << "impossible";
	}
	else {
		if (this->_isSpecialDoubleValue(this->_raw)
				|| this->_isSpecialFloatValue(this->_raw)) {
			std::cout << this->_d;
		}
		else {
			std::cout << this->_d<< ((std::round(this->_d) == this->_d) ? ".0" : "") ;
		}
	}
	std::cout << std::endl;
}

void ScalarConvertor::_find_c_from_i() {
	if (this->_i_err)
		this->_c_err = ERR;
	else {
		if (this->_i > 127 || this->_i < -128)
			this->_c_err = ERR;
		else if (this->_i < ' ' || this->_i > '~')
			this->_c_err = NO_DISPLAY;
		else
			this->_c = static_cast<char>(this->_i);
	}
}

bool ScalarConvertor::_parse_d() {
	std::string raw = this->_raw;
	bool point_found = false;
	int i = -1;
	while (++i < (static_cast<int>(raw.length()))) {
		if (raw[i] == '.') {
			if (point_found)
				return false;
			else 
				point_found = true;
		}
		else if ((!isdigit(raw[i])) && !(i == 0 && (raw[i] == '+' || raw[i] == '-')))
			return (false);
	}
	return (point_found);
}

bool ScalarConvertor::_parse_i() {
	std::string raw = this->_raw;
	int i = -1;
	while (++i < (static_cast<int>(raw.length()))) {
		if ((!isdigit(raw[i])) && !(i == 0 && (raw[i] == '+' || raw[i] == '-')))
			return (false);
	} 
	return (true);
}

bool ScalarConvertor::_parse_f() {
	std::string raw = this->_raw;
	bool point_found = false;
	int i = -1;
	while (++i < (static_cast<int>(raw.length()))) {
		if (raw[i] == '.') {
			if (point_found)
				return false;
			else 
				point_found = true;
		}	
		else if ((!isdigit(raw[i])) && !(i == 0 && (raw[i] == '+' || raw[i] == '-'))) {
			if (raw[i] == 'f' && (static_cast<size_t>(i) == raw.length() - 1))
				return (point_found);
			else
				return (false);
		}
	}
	return (false);
}

void ScalarConvertor::printConversions(void) {
	
	std::string raw = this->_raw;
	if (raw.length() == 3 && raw[0] == '\'' && raw[2] == '\'') {
		this->_c = raw[1];
		this->_i = static_cast<int> (this->_c);
		this->_f = static_cast<float> (this->_i);
		this->_d = static_cast<double> (this->_f);
	}
	else {
		try {
			if (this->_parse_d()) {
				this->_d = std::stod(raw);
				try {
					if ((this->_d > (static_cast<double>(INT_MAX)))
							|| (this->_d < (static_cast<double>(INT_MIN))))
						throw (std::exception());
					this->_i = static_cast<int> (this->_d);
				}
				catch (std::exception e) {
					this->_i_err = ERR;
				}
				try {
					this->_f = std::stof(raw);
				}
				catch (std::exception e) {
					this->_f_err = ERR;
				}
				this->_find_c_from_i();
			}
			else if (_isSpecialDoubleValue(raw)){
				this->_d = std::stod(raw);
				this->_f = static_cast<float> (this->_d);
				this->_c_err = ERR;
				this->_i_err = ERR;
			}
			else {
				if (this->_parse_f()) {
					this->_f = std::stof(raw);
					try {
						if ((this->_d > (static_cast<double>(INT_MAX)))
								|| (this->_d < (static_cast<double>(INT_MIN))))
							throw (std::exception());
						this->_i = static_cast<int> (this->_f);
					}
					catch (std::exception e) {
						this->_i_err = ERR;
					}
					this->_d = static_cast<double> (this->_f);
					this->_find_c_from_i();
				}
				else if (_isSpecialFloatValue(raw)){
					this->_f = std::stof(raw);
					this->_d = static_cast<double> (this->_f);
					this->_c_err = ERR;
					this->_i_err = ERR;
				}
				else {
					if (this->_parse_i()) {
						try {
							this->_i = std::stoi(raw);
						}
						catch (std::exception e) {
							this->_i_err = ERR;
						}
						this->_d = static_cast<double> (this->_i);
						this->_f = static_cast<float> (this->_i);
						this->_find_c_from_i();
					}
					else {
						throw (std::exception());
					}
				}
			}
		} 
		catch (std::exception e) {
			this->_i_err = ERR;
			this->_c_err = ERR;
			this->_f_err = ERR;
			this->_d_err = ERR;
		}
	}
	this->_print_c();
	this->_print_i();
	this->_print_f();
	this->_print_d();
}
