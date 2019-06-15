/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperMutant.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 13:16:28 by tbehra            #+#    #+#             */
/*   Updated: 2019/05/24 23:54:28 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SUPERMUTANT_HPP 
# define SUPERMUTANT_HPP

# include <iostream>
# include "Enemy.hpp"

class SuperMutant : public Enemy{
	
	public:
		SuperMutant();
		virtual ~SuperMutant();
		SuperMutant(SuperMutant const & e);
		SuperMutant & operator=(SuperMutant const & e);

		virtual void dies() const;
		virtual void takeDamage(int amount);

};

#endif
