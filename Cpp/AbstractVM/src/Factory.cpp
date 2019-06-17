/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Factory.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 11:13:12 by tbehra            #+#    #+#             */
/*   Updated: 2019/06/16 17:26:35 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Factory.hpp"

IOperand const * Factory::createInt8( std::string const & value ) const {
	//TODO : try catch around stoi
	//return new Operand< int8_t >(static_cast< int8_t >(std::stoi(value)), Int8, value);
	return new Operand< int8_t >(static_cast< int8_t >(std::stoi(value)), Int8, value);
}

IOperand const * Factory::createInt16( std::string const & value ) const {
	return new Operand< int16_t >(static_cast< int16_t >(std::stoi(value)), Int16, value);
}

IOperand const * Factory::createInt32( std::string const & value ) const {
	return new Operand< int32_t >(std::stoi(value), Int32, value);
}

IOperand const * Factory::createFloat( std::string const & value ) const {
	return new Operand< float >(std::stof(value), Float, value);
}

IOperand const * Factory::createDouble( std::string const & value ) const {
	return new Operand< double >(std::stod(value), Double, value);
}

IOperand const * Factory::createOperand(eOperandType type, std::string const & value) const {
	IOperand const * (Factory::*arr[5])(std::string const & value) const = {
		&Factory::createInt8,
		&Factory::createInt16,
		&Factory::createInt32,
		&Factory::createFloat,
		&Factory::createDouble
	};
	IOperand const * (Factory::*operandFunc)(std::string const & value) const;

	operandFunc = arr[type];
	return (this->*operandFunc)(value);
}

