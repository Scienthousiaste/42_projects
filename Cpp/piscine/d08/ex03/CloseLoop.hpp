/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CloseLoop.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 16:59:07 by tbehra            #+#    #+#             */
/*   Updated: 2019/05/31 18:39:13 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLOSE_LOOP_HPP 
#define CLOSE_LOOP_HPP 

#include "AInstruction.hpp"

class CloseLoop : public AInstruction {
	public:
		CloseLoop(void) {
			this->_name = "CloseLoop";
		}
		~CloseLoop(void) {}
		void exec(Mindopen * mo) {
			mo->closeLoop();	
		}

	private:
		CloseLoop & operator=(CloseLoop const & i);
		CloseLoop(CloseLoop const & i);
};


#endif
