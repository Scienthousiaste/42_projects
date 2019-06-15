/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 18:32:18 by tbehra            #+#    #+#             */
/*   Updated: 2019/05/24 23:00:12 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef A_MATERIA_HPP
# define A_MATERIA_HPP

#include <iostream>
#include "ICharacter.hpp"

class ICharacter;

class AMateria {
	protected:
		unsigned int xp_;
		std::string type_;

	public:
		AMateria(std::string const & type);
		virtual ~AMateria();
		AMateria(AMateria const & a);
		AMateria & operator=(AMateria const & a);

		std::string const & getType() const;
		unsigned int getXP() const;
		void setXP(unsigned int xp);

		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};


#endif
