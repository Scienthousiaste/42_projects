/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 21:41:13 by tbehra            #+#    #+#             */
/*   Updated: 2019/05/24 22:20:41 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIA_SOURCE_HPP
# define MATERIA_SOURCE_HPP

#include "IMateriaSource.hpp"
#include "AMateria.hpp"

class MateriaSource : public IMateriaSource {
	private:
		AMateria* store_[INVENTORY_SIZE];
		
	public:
		MateriaSource();
		~MateriaSource();
		MateriaSource(MateriaSource const & ms);
		MateriaSource & operator=(MateriaSource const & ms);
		void learnMateria(AMateria*);
		AMateria* createMateria(std::string const & type);


};

#endif
