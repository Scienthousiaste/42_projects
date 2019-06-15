/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 13:02:56 by tbehra            #+#    #+#             */
/*   Updated: 2019/05/24 23:54:17 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_HPP 
# define ENEMY_HPP

# include <iostream>

class Enemy {
	
	private:
		Enemy();

	public:
		Enemy(int hp, std::string const & type);
		virtual ~Enemy(void);
		Enemy(Enemy const & e);
		Enemy & operator=(Enemy const & e);

		void setHP(int hp);
		void setType(std::string type);
		int getHP(void) const;
		std::string getType(void) const;
	
		virtual void dies(void) const;
		virtual void takeDamage(int amount);
	
	protected:
		int _hp;
		std::string _type;

};

#endif
