/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PlasmaRifle.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 11:57:44 by tbehra            #+#    #+#             */
/*   Updated: 2019/05/24 23:53:48 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PLASMARIFLE_HPP 
# define PLASMARIFLE_HPP

# include "AWeapon.hpp"

class PlasmaRifle : public AWeapon {
	
	public:
		PlasmaRifle();
		virtual ~PlasmaRifle(void);
		PlasmaRifle(PlasmaRifle const & s);
		PlasmaRifle & operator=(PlasmaRifle const & w);
		void attack(void) const;

};

#endif
