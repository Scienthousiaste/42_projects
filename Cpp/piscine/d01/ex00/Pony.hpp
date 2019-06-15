/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 09:05:52 by tbehra            #+#    #+#             */
/*   Updated: 2019/05/21 09:48:53 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PONY_HPP
# define PONY_HPP

# include <iostream>

class Pony {

public:
	Pony(bool is_a_unicorn, std::string favorite_marshmallow, std::string smell,
			int brightness, int cleanliness);
	~Pony(void);
	void describe(void) const;
	void play(void) const;

private:
	bool		_is_a_unicorn;
	std::string _favorite_marshmallow;
	std::string	_smell;
	int			_brightness;
	int			_cleanliness;
};

#endif
