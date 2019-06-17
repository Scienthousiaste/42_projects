/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Operand.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 18:03:28 by tbehra            #+#    #+#             */
/*   Updated: 2019/06/17 16:59:01 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERAND_HPP
# define OPERAND_HPP

#include "IOperand.hpp"

template< typename T >
class Operand : public IOperand {
	public:
		int getPrecision(void) const {
			return static_cast<int>(this->_type);
		}
		std::string const & toString(void) const {
			return this->_str; 
		}
		IOperand const * operator+(IOperand const & rhs) const {
			//TODO	Try catch

			// TODO compute new value with correct type

			/*
			if (this->getPrecision > rhs.getPrecision)
				return Operand(this->getValue() + rhs.getValue(), this->getType(), this->getStr());	
			else
				return Operand(this->getValue() + rhs.getValue(), rhs.getType(), rhs.getStr());
				*/

			(void)rhs;
			std::cout << "here in operator+" << std::endl;
			return this;
		}
		IOperand const * operator-(IOperand const & rhs) const {
			(void)rhs;
			return this;
		}
		IOperand const * operator*(IOperand const & rhs) const {
			(void)rhs;
			return this;
		}
		IOperand const * operator/(IOperand const & rhs) const {
			(void)rhs;
			return this;
		}
		IOperand const * operator%(IOperand const & rhs) const {
			(void)rhs;
			return this;
		}
		Operand(T value, eOperandType type, std::string str) :
			_value(value),
			_type(type),
			_str(str) {
		}
		~Operand() {
			std::cout << "Operand destructor called" << std::endl;	
		}
		Operand<T> & operator=(Operand<T> const & op) {
			this->setValue(op.getValue());
			this->setType(op.getType());
			this->setStr(op.getStr());
			return *this;
		}
		Operand(Operand<T> const & op) {
			//TODO: reverif et comprendre
			*this = op;
			return;
		}

		eOperandType getType(void) const {
			return this->_type;
		}
		void setType(eOperandType type) {
			this->_type = type;
		}
		T getValue(void) const {
			return this->_value;
		}
		void setValue(T value) {
			this->_value = value;
		}
		std::string & getStr(void) const {
			return this->_str;
		}
		void setStr(std::string & s) {
			this->_str = std::string(s);
		}

	private:
		T				_value;
		eOperandType	_type;
		std::string		_str;
};


#endif
