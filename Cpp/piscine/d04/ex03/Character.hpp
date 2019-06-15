/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 20:58:34 by tbehra            #+#    #+#             */
/*   Updated: 2019/05/25 00:09:22 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP 
# define CHARACTER_HPP

# include "ICharacter.hpp"

# define INVENTORY_SIZE 4

class Character : public ICharacter {
	private:
		AMateria* inventory_[INVENTORY_SIZE];	
		std::string name_;
		Character();

	public:
		Character(std::string const & name);
		~Character();
		Character(Character const & ch);
		Character & operator=(Character const & ch);

		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
		std::string const & getName() const;
		AMateria* getMateriaIndex(int idx) const;

};


#endif
