/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 14:19:55 by tbehra            #+#    #+#             */
/*   Updated: 2019/05/22 20:19:04 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"


Fixed::Fixed(void) : _rawBits(0) {
}

Fixed::Fixed(Fixed const & f) {
	*this = f;
	return;
}

Fixed::Fixed(const int n) :
	_rawBits(n << Fixed::_fractional_bits_number) {
}

Fixed::Fixed(const float f) {
	double d;

	d = (double)f;
	d = std::roundf(d * (1 << Fixed::_fractional_bits_number));
	this->_rawBits = (int) d;
}

Fixed::~Fixed(void) {
}

int		Fixed::getRawBits(void) const {
	return this->_rawBits;
}

void	Fixed::setRawBits(int const raw) {
	this->_rawBits = raw;
}

float	Fixed::toFloat(void) const {
	double d;

	d = ((double)this->_rawBits / (1 << Fixed::_fractional_bits_number));
	return ((float)d);	
}

int		Fixed::toInt(void) const {
	return (this->_rawBits >> Fixed::_fractional_bits_number);
}

Fixed &	Fixed::operator=(Fixed const & f) {
	this->_rawBits = f.getRawBits();
	return *this;
}

bool Fixed::operator>(Fixed const & f) const {
	return (this->_rawBits > f._rawBits);
}

bool Fixed::operator<(Fixed const & f) const {
	return (this->_rawBits < f._rawBits);
}

bool Fixed::operator>=(Fixed const & f) const {
	return (this->_rawBits >= f._rawBits);
}

bool Fixed::operator<=(Fixed const & f) const {
	return (this->_rawBits <= f._rawBits);
}

bool Fixed::operator==(Fixed const & f) const {
	return (this->_rawBits == f._rawBits);
}

bool Fixed::operator!=(Fixed const & f) const {
	return (this->_rawBits != f._rawBits);
}

Fixed Fixed::operator+(Fixed const & f) {
	return (Fixed(this->toFloat() + f.toFloat()));
}
Fixed Fixed::operator-(Fixed const & f) {
	return (Fixed(this->toFloat() - f.toFloat()));
}
Fixed Fixed::operator*(Fixed const & f) {
	return (this->toFloat() * f.toFloat());
}
Fixed Fixed::operator/(Fixed const & f) {
	if (f.toFloat() == 0)
	{
		std::cout << "( Division by 0 )";
		throw;
	}
	return (this->toFloat() / f.toFloat());
}

Fixed & Fixed::operator++(void) {
	this->_rawBits++;
	return (*this);
}
Fixed & Fixed::operator--(void) {
	this->_rawBits--;
	return (*this);
}

Fixed Fixed::operator++(int dummy) {
	(void) dummy;
	Fixed before(*this);
	this->_rawBits++;
	return (before);
}
Fixed Fixed::operator--(int dummy) {
	(void) dummy;
	Fixed before(*this);
	this->_rawBits--;
	return (before);
}

std::ostream &	operator<<(std::ostream &o, Fixed const & f) {
	o << f.toFloat();
	return o;
}

Fixed & Fixed::min(Fixed & a, Fixed & b) {
	if (a > b)
		return b;
	return a;
}

Fixed const & Fixed::min(Fixed const & a, Fixed const & b) {
	if (a > b)
		return b;
	return a;
}

Fixed & Fixed::max(Fixed & a, Fixed & b) {
	if (a > b)
		return a;
	return b;
}

Fixed const & Fixed::max(Fixed const & a, Fixed const & b) {
	if (a > b)
		return a;
	return b;
}
