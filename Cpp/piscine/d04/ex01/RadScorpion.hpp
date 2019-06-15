/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RadScorpion.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 13:31:40 by tbehra            #+#    #+#             */
/*   Updated: 2019/05/24 23:54:45 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCORPION_HPP 
# define SCORPION_HPP 

# include <iostream>
# include "Enemy.hpp"

class RadScorpion : public Enemy{
	
	public:
		RadScorpion();
		virtual ~RadScorpion();
		RadScorpion(RadScorpion const & e);
		RadScorpion & operator=(RadScorpion const & e);

		virtual void dies() const;
};

#endif
