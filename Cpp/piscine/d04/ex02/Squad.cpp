/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Squad.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 15:07:33 by tbehra            #+#    #+#             */
/*   Updated: 2019/05/24 18:23:23 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Squad.hpp"

Squad::Squad() : _arr_size(DEFAULT_ARR_SIZE), _index(0) {
	this->_marines = new ISpaceMarine*[DEFAULT_ARR_SIZE];
}

Squad::Squad(size_t arr_size) : _arr_size(arr_size), _index(0){
	this->_marines = new ISpaceMarine*[arr_size];
}

Squad::~Squad(void) {
	int i = 0;

	while (i < this->_index) {
		delete this->_marines[i];
		i++;
	}
	delete [] this->_marines;
}

Squad::Squad(Squad const & s) : ISquad() {
	for(int i = 0; i < s.getCount(); i++) {
		this->push(s._marines[i]);
	}
}

Squad & Squad::operator=(Squad const & s) {
	if (this == &s)
		return *this;
	if (this->getCount() > 0) {
		size_t i = 0;
		while (i < (size_t)this->_index) {
			delete this->_marines[i];
			i++;
		}
		delete [] this->_marines;
		this->_index = 0;
		this->_marines = new ISpaceMarine*[DEFAULT_ARR_SIZE];
		this->_arr_size = DEFAULT_ARR_SIZE;
	}

	for(int j = 0; j < s.getCount(); j++) {
		this->push(s._marines[j]->clone());
	}
	return *this;
}

bool Squad::hasMarine(ISpaceMarine* s) {
	size_t i = 0;

	while (i < this->_arr_size) {
		if (this->_marines[i] == s)
			return true;	
		i++;
	}
	return false;
}

int Squad::push(ISpaceMarine* s) {
	if (!s || this->hasMarine(s))
		return (this->_index);
	if ((size_t)this->_index >= this->_arr_size) {
		size_t new_array_size = this->_arr_size * 2;
		size_t i = 0;
		
		ISpaceMarine** new_arr = new ISpaceMarine* [new_array_size];

		while (i < this->_arr_size) {
			new_arr[i] = this->_marines[i];
			i++;
		}
		delete [] this->_marines;
		this->_marines = new_arr;
		this->_arr_size = new_array_size;
	}
	this->_marines[this->_index] = s;
	this->_index++;
	return this->_index;
}

int Squad::getCount() const {
	return this->_index;
}
size_t Squad::getArrSize() const {
	return this->_arr_size;
}

ISpaceMarine* Squad::getUnit(int n) const {
	if (n < 0 || n >= this->_index)
		return NULL;
	return this->_marines[n];
}
