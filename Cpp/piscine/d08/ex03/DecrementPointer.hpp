/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DecrementPointer.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 16:53:28 by tbehra            #+#    #+#             */
/*   Updated: 2019/05/31 18:36:27 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DECREMENT_POINTER_HPP 
#define DECREMENT_POINTER_HPP 

#include "AInstruction.hpp"

class DecrementPointer : public AInstruction {
	public:
		DecrementPointer(void) {
		    this->_name = "DecrementPointer";
		}
		~DecrementPointer(void) {}
		void exec(Mindopen * mo) {
			mo->decrementPointer();
		}

	private:
		DecrementPointer & operator=(DecrementPointer const & i);
		DecrementPointer(DecrementPointer const & i);
};


#endif
