/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PowerFist.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 12:59:42 by tbehra            #+#    #+#             */
/*   Updated: 2019/05/24 23:53:56 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POWERFIST_HPP 
# define POWERFIST_HPP

# include "AWeapon.hpp"

class PowerFist : public AWeapon {
	
	public:
		PowerFist();
		virtual ~PowerFist(void);
		PowerFist(PowerFist const & s);
		PowerFist & operator=(PowerFist const & w);
		void attack(void) const;

};

#endif
