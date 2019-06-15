/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IncrementPointer.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 16:50:03 by tbehra            #+#    #+#             */
/*   Updated: 2019/05/31 19:08:49 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCREMENT_POINTER_HPP 
#define INCREMENT_POINTER_HPP 

#include "AInstruction.hpp"

#include "Mindopen.hpp"

class Mindopen;

class IncrementPointer : public AInstruction {
	public:
		IncrementPointer() {
			this->_name = "IncrementPointer";
		}
		~IncrementPointer(void) {}
		void exec(Mindopen * mo) {
			mo->incrementPointer();
		}

	private:
		IncrementPointer & operator=(IncrementPointer const & i);
		IncrementPointer(IncrementPointer const & i);
};


#endif
