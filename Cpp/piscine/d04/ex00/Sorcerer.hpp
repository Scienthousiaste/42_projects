/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 10:18:14 by tbehra            #+#    #+#             */
/*   Updated: 2019/05/24 23:24:38 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORCERER_HPP
# define SORCERER_HPP

# include <iostream>
# include "Victim.hpp"

class Sorcerer {
	
	public:
		Sorcerer(std::string name, std::string title);
		~Sorcerer(void);
		Sorcerer(Sorcerer const & s);
		Sorcerer & operator=(Sorcerer const & s);
		std::string getName(void) const;
		std::string getTitle(void) const;
		void setName(std::string name);
		void setTitle(std::string title);
		std::string introduceThyself(void) const;
		void polymorph(Victim const & v) const;
	
	private:
		Sorcerer(void);
		std::string _name;
		std::string _title;

};

std::ostream & operator<<(std::ostream & o, Sorcerer const & s);

#endif
