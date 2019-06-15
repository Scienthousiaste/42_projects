/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Operand.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 18:03:28 by tbehra            #+#    #+#             */
/*   Updated: 2019/06/15 18:33:16 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERAND_HPP
# define OPERAND_HPP

#include "IOperand.hpp"

template< typename T >
class Operand : public IOperand {
	public:
		int getPrecision(void) const;
		eOperandType getType(void) const;

		std::string const & toString(void) const;

		IOperand const * operator+(IOperand const & rhs) const;
		IOperand const * operator-(IOperand const & rhs) const;
		IOperand const * operator*(IOperand const & rhs) const;
		IOperand const * operator/(IOperand const & rhs) const;
		IOperand const * operator%(IOperand const & rhs) const;

		Operand(T value, eOperandType type, std::string str);
		~Operand();
		Operand & operator =(Operand const & op);
		Operand(Operand const & op);
	
	private:
		T				_value;
		eOperandType	_type;
		std::string		_str;
};


#endif
