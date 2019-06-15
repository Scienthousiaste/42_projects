/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Victim.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 11:14:03 by tbehra            #+#    #+#             */
/*   Updated: 2019/05/24 23:33:20 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VICTIM_HPP 
# define VICTIM_HPP

# include <iostream>

class Victim {
	
	public:
		Victim(std::string name);
	 	virtual ~Victim(void);
		Victim(Victim const & v);
		Victim & operator=(Victim const & v);
		std::string getName(void) const;
		void setName(std::string name);
		virtual void getPolymorphed(void) const;
		virtual std::string introduceThyself(void) const;
	
	protected:
		Victim(void);
		std::string _name;

};

std::ostream & operator<<(std::ostream & o, Victim const & v);

#endif
