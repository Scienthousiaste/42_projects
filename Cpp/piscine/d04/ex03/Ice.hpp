/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 20:36:50 by tbehra            #+#    #+#             */
/*   Updated: 2019/05/24 21:34:03 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP 
# define ICE_HPP 

# include "AMateria.hpp"

class Ice : public AMateria {
	public:
		Ice();
		~Ice();
		Ice(Ice const & ice);
		Ice & operator=(Ice const & ice);

		Ice* clone() const;
		void use(ICharacter& target);
};


#endif
