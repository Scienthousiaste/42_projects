/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AbstractVM.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 14:53:02 by tbehra            #+#    #+#             */
/*   Updated: 2019/06/15 16:20:51 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ABSTRACTVM_H
# define ABSTRACTVM_H

# include <string>
# include "IOperand.hpp"

class AbstractVM {

	public:
		IOperand const * createInt8( std::string const & value ) const;
		IOperand const * createInt16( std::string const & value ) const;
		IOperand const * createInt32( std::string const & value ) const;
		IOperand const * createFloat( std::string const & value ) const;
		IOperand const * createDouble( std::string const & value ) const;
		IOperand const * createOperand( eOperandType type, std::string const & value ) const;

};

#endif
