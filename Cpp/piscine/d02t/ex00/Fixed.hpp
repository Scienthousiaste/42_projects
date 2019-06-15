/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 14:18:55 by tbehra            #+#    #+#             */
/*   Updated: 2019/05/22 15:02:35 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed {

	public:
		Fixed(void);
		Fixed(Fixed const & f);
		Fixed & operator=(Fixed const & f);
		~Fixed(void);
		int getRawBits(void) const;
		void setRawBits(int const raw);
	
	private:
		int _rawBits;
		static const int _fractional_bits_number = 8;
};


#endif
