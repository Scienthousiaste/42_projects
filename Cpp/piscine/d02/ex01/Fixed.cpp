/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 14:19:55 by tbehra            #+#    #+#             */
/*   Updated: 2019/05/22 16:47:55 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"


Fixed::Fixed(void) : _rawBits(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const & f) {
	std::cout << "Copy constructor called" << std::endl;
	*this = f;
	return;
}

Fixed::Fixed(const int n) :
	_rawBits(n << Fixed::_fractional_bits_number) {
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float f) {
	double d;

	d = (double)f;
	d = std::roundf(d * (1 << Fixed::_fractional_bits_number));
	this->_rawBits = (int) d;
	std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
}

Fixed &	Fixed::operator=(Fixed const & f) {
	std::cout << "Assignation operator called" << std::endl;
	this->_rawBits = f.getRawBits();
	
	return *this;
}

int		Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->_rawBits;
}

void	Fixed::setRawBits(int const raw) {
	this->_rawBits = raw;
}

int		Fixed::toInt(void) const {
	return (this->_rawBits >> Fixed::_fractional_bits_number);
}

float	Fixed::toFloat(void) const {
	double d;

	d = ((double)this->_rawBits / (1 << Fixed::_fractional_bits_number));
	return ((float)d);	
}

std::ostream &	operator<<(std::ostream &o, Fixed const & f) {
	o << f.toFloat();
	return o;
}
