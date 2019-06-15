/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OutputData.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 16:57:27 by tbehra            #+#    #+#             */
/*   Updated: 2019/05/31 19:06:44 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OUTPUT_DATA_HPP 
#define OUTPUT_DATA_HPP 

#include "AInstruction.hpp"

class OutputData : public AInstruction {
	public:
		OutputData(void) {
			this->_name = "OutputData"; 
		}
		~OutputData(void) {}
		void exec(Mindopen * mo) {
			mo->outputData();	
		}

	private:
		OutputData & operator=(OutputData const & i);
		OutputData(OutputData const & i);
};


#endif
