/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IncrementCell.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 16:55:12 by tbehra            #+#    #+#             */
/*   Updated: 2019/05/31 18:36:55 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCREMENT_CELL_HPP 
#define INCREMENT_CELL_HPP 

#include "AInstruction.hpp"

class IncrementCell : public AInstruction {
	public:
		IncrementCell(void) {
			this->_name = "IncrementCell";
		}
		~IncrementCell(void) {}
		void exec(Mindopen * mo) {
			mo->incrementCell();
		}

	private:
		IncrementCell & operator=(IncrementCell const & i);
		IncrementCell(IncrementCell const & i);
};


#endif
