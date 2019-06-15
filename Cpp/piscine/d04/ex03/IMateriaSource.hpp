/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 21:25:51 by tbehra            #+#    #+#             */
/*   Updated: 2019/05/24 22:43:32 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef I_MATERIA_SOURCE_HPP 
# define I_MATERIA_SOURCE_HPP

# define INVENTORY_SIZE 4
#include <string>
#include "AMateria.hpp"

class IMateriaSource {
	public:
		virtual ~IMateriaSource () {}
		virtual void learnMateria(AMateria*) = 0;
		virtual AMateria* createMateria(std::string const & type) = 0;
};


#endif
