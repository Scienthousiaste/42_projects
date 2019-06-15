/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   InputData.hpp                                     :+:      :+:    :+:    */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 16:57:27 by tbehra            #+#    #+#             */
/*   Updated: 2019/05/31 22:47:12 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_DATA_HPP 
#define INPUT_DATA_HPP 

#include "AInstruction.hpp"

class InputData : public AInstruction {
	public:
		InputData(void) {
		   this->_name = "InputData"; 
		}
		~InputData(void) {}
		void exec(Mindopen * mo) {
			mo->inputData();	
		}
	private:
		InputData & operator=(InputData const & i);
		InputData(InputData const & i);
};


#endif
