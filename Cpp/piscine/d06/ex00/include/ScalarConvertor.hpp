/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConvertor.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 13:35:54 by tbehra            #+#    #+#             */
/*   Updated: 2019/05/28 22:08:43 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_CONVERTOR_HPP
# define SCALAR_CONVERTOR_HPP

# define ERR 1
# define NO_DISPLAY 2

#include <iostream>
#include <limits.h>
#include <cmath>


class ScalarConvertor {
	
	public:
		ScalarConvertor(std::string raw);
		~ScalarConvertor(void);
		void	printConversions(void);

	
	private:
		std::string	_raw;

		void		_print_c(void);
		void		_print_i(void);
		void		_print_f(void);
		void		_print_d(void);
		void		_find_c_from_i(void);
		bool		_isSpecialDoubleValue(std::string s) const;
		bool		_isSpecialFloatValue(std::string s) const;
		bool		_parse_d(void);
		bool		_parse_f(void);
		bool		_parse_i(void);
		
		char		_c;
		int			_i;
		float		_f;
		double		_d;
		int			_c_err;
		int			_i_err;
		int			_f_err;
		int			_d_err;

		ScalarConvertor & operator=(ScalarConvertor const & s);
		ScalarConvertor(ScalarConvertor const & s);
		ScalarConvertor(void);
};

#endif
