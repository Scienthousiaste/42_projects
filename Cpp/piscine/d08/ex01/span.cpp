/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 16:56:50 by tbehra            #+#    #+#             */
/*   Updated: 2019/05/30 20:53:16 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"

IntContainer::IntContainer(unsigned int N) :
	_N(N),
	_index(0),
	_vec(std::vector<int>(N, 0)) {
}


IntContainer::~IntContainer(void) {

}

void IntContainer::addNumber(int n) {
	if (this->_index == this->_N)
		throw (new std::exception());
	else
		this->_vec[this->_index++] = n;
}

unsigned int IntContainer::shortestSpan(void) const {
	long int smallest_diff;
	if (this->_index <= 1)
		throw (new std::exception());
	else {
		std::vector<int> copyvec(this->_vec);
		std::sort(copyvec.begin(), copyvec.begin() + this->_index);

		smallest_diff = copyvec[1] - copyvec[0];
		for (unsigned int i = 2; i < this->_index; i++) {
			smallest_diff = ((copyvec[i] - copyvec[i - 1]) < smallest_diff) ? 
				copyvec[i] - copyvec[i - 1] : smallest_diff;
		}
		return smallest_diff;	
	}
}

unsigned int IntContainer::longestSpan(void) const {
	if (this->_index <= 1)
		throw (std::exception());
	else {
		return (*(std::max_element(this->_vec.begin(), this->_vec.begin() + this->_index))
				- (*std::min_element(this->_vec.begin(), this->_vec.begin() + this->_index)));
	}
}

static void printNumber(int i) {
	std::cout << i << std::endl;
}

void IntContainer::printVec(void) const {
	for_each(this->_vec.begin(), this->_vec.begin() + this->_index, printNumber);
}

void IntContainer::addRandNumbers(size_t n_numbers, int min, int max) {
	std::srand(time(NULL));
	
	if (max < min)
		throw(std::exception());
	for(size_t i = 0; i < n_numbers; i++) {
		this->addNumber((min + (std::rand() % max)) % max);
	}
}
