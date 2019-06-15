/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Peon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 11:14:03 by tbehra            #+#    #+#             */
/*   Updated: 2019/05/24 23:32:45 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PEON_HPP
#define PEON_HPP

# include "Victim.hpp"
# include <iostream>

class Peon : public Victim {
	private:
		Peon(void);
	
	public:
		Peon(std::string name);
		virtual ~Peon(void);
		Peon(Peon const & v);
		Peon & operator=(Peon const & v);
		virtual void getPolymorphed(void) const;
};

#endif
