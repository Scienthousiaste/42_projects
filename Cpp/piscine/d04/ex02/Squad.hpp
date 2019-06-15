/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Squad.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 14:39:08 by tbehra            #+#    #+#             */
/*   Updated: 2019/05/24 18:21:02 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SQUAD_HPP 
# define SQUAD_HPP 

# include <iostream>
# include "ISquad.hpp"

# define DEFAULT_ARR_SIZE 1

class Squad : public ISquad {
	
	public:
		Squad();
		Squad(size_t arr_size);
		~Squad();
		Squad(Squad const & s);
		Squad & operator=(Squad const &);

		int getCount() const;
		size_t getArrSize() const;
		ISpaceMarine* getUnit(int) const;
		int push(ISpaceMarine*);	

	
	protected:
		size_t _arr_size;
		int _index;
		ISpaceMarine** _marines; 
		bool hasMarine(ISpaceMarine*);
};

#endif
