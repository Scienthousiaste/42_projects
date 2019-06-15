/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OpenLoop.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 16:59:07 by tbehra            #+#    #+#             */
/*   Updated: 2019/05/31 19:50:40 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPEN_LOOP_HPP 
#define OPEN_LOOP_HPP 

#include "AInstruction.hpp"

class OpenLoop : public AInstruction {
	public:
		OpenLoop(void) {
			this->_name = "OpenLoop";
		}
		~OpenLoop(void) {}
		void exec(Mindopen * mo) {
			mo->openLoop();
		}

	private:
		OpenLoop & operator=(OpenLoop const & i);
		OpenLoop(OpenLoop const & i);
};


#endif
