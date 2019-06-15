/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AssaultTerminator.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 16:21:43 by tbehra            #+#    #+#             */
/*   Updated: 2019/05/24 16:33:25 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASSAULTTERMINATOR_HPP
# define ASSAULTTERMINATOR_HPP

#include "ISpaceMarine.hpp"
#include <iostream>

class AssaultTerminator : public ISpaceMarine {
	
	public:
		AssaultTerminator();
		~AssaultTerminator();
		AssaultTerminator* clone() const;
		AssaultTerminator(AssaultTerminator const & m);
		AssaultTerminator & operator=(AssaultTerminator const & c);

		void battleCry() const;
		void rangedAttack() const;
		void meleeAttack() const;
};

#endif
