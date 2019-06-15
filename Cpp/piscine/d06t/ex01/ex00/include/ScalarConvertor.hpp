/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConvertor.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 13:35:54 by tbehra            #+#    #+#             */
/*   Updated: 2019/05/28 15:18:30 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_CONVERTOR_HPP
# define SCALAR_CONVERTOR_HPP

#include <iostream>

class ScalarConvertor {
	
	public:
		ScalarConvertor(std::string raw);
		~ScalarConvertor(void);
		char	charConversion(void);

		int		intConversion(void);
		float	floatConversion(void);
		double	doubleConversion(void);
		void	printConversions(void);
	
	private:
		std::string	_raw;
		
		char		_char;
		int			_int;
		float		_float;
		double		_double;

		ScalarConvertor & operator=(ScalarConvertor const & s);
		ScalarConvertor(ScalarConvertor const & s);
		ScalarConvertor(void);
};

#endif
