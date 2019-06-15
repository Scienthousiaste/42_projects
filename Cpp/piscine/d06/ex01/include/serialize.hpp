/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serialize.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 15:20:04 by tbehra            #+#    #+#             */
/*   Updated: 2019/05/28 17:25:14 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZE_HPP
# define SERIALIZE_HPP

# include <stdlib.h>
# include <string>
# include <iostream>
# include <time.h>

typedef struct	Data {
	std::string s1;
	int n;
	std::string s2;
}				Data;

void * serialize( void );
Data * deserialize( void * raw );


#endif 
