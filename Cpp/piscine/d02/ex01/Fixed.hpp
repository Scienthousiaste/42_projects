/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 14:18:55 by tbehra            #+#    #+#             */
/*   Updated: 2019/05/22 16:40:19 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed {

	public:
		Fixed(void);
		Fixed(Fixed const & f);
		Fixed(const int n);
		Fixed(const float f);
		~Fixed(void);
		
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
	
		Fixed &	operator=(Fixed const & f);
	
	private:
		int		_rawBits;
		static	const int _fractional_bits_number = 8;
};

std::ostream &	operator<<(std::ostream & o, Fixed const & f);


#endif
