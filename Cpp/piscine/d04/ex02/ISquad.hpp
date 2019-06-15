/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ISquad.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 14:41:11 by tbehra            #+#    #+#             */
/*   Updated: 2019/05/24 18:13:44 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ISQUAD_HPP 
# define ISQUAD_HPP 

#include "ISpaceMarine.hpp"

class ISquad {
	
	public:
		virtual ~ISquad() {}
		virtual int getCount() const = 0;
		virtual ISpaceMarine* getUnit(int) const = 0;
		virtual int push(ISpaceMarine*) = 0;
};

#endif
