/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 20:36:50 by tbehra            #+#    #+#             */
/*   Updated: 2019/05/24 22:00:48 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP 
# define CURE_HPP 

#include "AMateria.hpp"

class Cure : public AMateria {
	public:
		Cure();
		~Cure();
		Cure(Cure const & heal);
		Cure & operator=(Cure const & heal);

		Cure* clone() const;
		void use(ICharacter& target);
};


#endif
