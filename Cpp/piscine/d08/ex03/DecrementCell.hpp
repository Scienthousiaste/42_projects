/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DecrementCell.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 16:56:06 by tbehra            #+#    #+#             */
/*   Updated: 2019/05/31 18:37:18 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DECREMENT_CELL_HPP 
#define DECREMENT_CELL_HPP 

#include "AInstruction.hpp"

class DecrementCell : public AInstruction {
	public:
		DecrementCell(void) {
			this->_name = "DecrementCell";
		}
		~DecrementCell(void) {}
		void exec(Mindopen * mo) {
			mo->decrementCell();
		}

	private:
		DecrementCell & operator=(DecrementCell const & i);
		DecrementCell(DecrementCell const & i);
};


#endif
