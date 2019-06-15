/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AInstruction.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 17:19:57 by tbehra            #+#    #+#             */
/*   Updated: 2019/05/31 19:15:17 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef A_INSTRUCTION_HPP
# define A_INSTRUCTION_HPP

#include "Mindopen.hpp"

class Mindopen;
class AInstruction {
	public:
		virtual void exec(Mindopen * mo) = 0;
		std::string getNameInstruction() {
			return this->_name;
		}
	protected:
		std::string _name;
		Mindopen *_mo;
};


#endif
