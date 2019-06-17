/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Factory.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 11:12:35 by tbehra            #+#    #+#             */
/*   Updated: 2019/06/17 10:28:05 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FACTORY_HPP
# define FACTORY_HPP

# include <string>
# include <iostream>
# include "defines.h"
# include "Operand.hpp"
# include "IOperand.hpp"
# include "Exceptions.hpp"

class IOperand;

class Factory {

	public:
		IOperand const * createInt8( std::string const & value ) const;
		IOperand const * createInt16( std::string const & value ) const;
		IOperand const * createInt32( std::string const & value ) const;
		IOperand const * createFloat( std::string const & value ) const;
		IOperand const * createDouble( std::string const & value ) const;
		IOperand const * createOperand( eOperandType type, std::string const & value ) const;

};

#endif
