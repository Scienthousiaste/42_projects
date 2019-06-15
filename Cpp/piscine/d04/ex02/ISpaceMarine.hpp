/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ISpaceMarine.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 14:49:18 by tbehra            #+#    #+#             */
/*   Updated: 2019/05/24 16:28:39 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ISPACE_MARINE_HPP 
# define ISPACE_MARINE_HPP 

class ISpaceMarine {
	
	public:
		virtual ~ISpaceMarine() {}
		virtual ISpaceMarine* clone() const = 0;
		virtual void battleCry() const = 0;
		virtual void rangedAttack() const = 0;
		virtual void meleeAttack() const = 0;
};

#endif
