/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serialize.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 15:18:01 by tbehra            #+#    #+#             */
/*   Updated: 2019/05/28 19:06:58 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serialize.hpp"


void * serialize(void) {
	std::srand(time(NULL));
	int i, r;
	char *data = new char[20];

	i = -1;
	while (++i < 8) {
		while (1) {
			r = std::rand() % 128;
			if ((r >= '0' && r <= '9') || (r >= 'A' && r <= 'Z')
				|| (r >= 'a' && r <= 'z')) {
				break ;
			}
		}
		data[i] = r;
	}
	int n = std::rand() - RAND_MAX / 2;
	std::cout << "The int here : "<< n << std::endl;
	int *nptr = reinterpret_cast<int*>(&data[8]); 
	*nptr = n;

	i = 11;
	while (++i < 20) {
		while (1) {
			r = std::rand() % 128;
			if ((r >= '0' && r <= '9') || (r >= 'A' && r <= 'Z')
				|| (r >= 'a' && r <= 'z')) {
				break ;
			}
		}
		data[i] = r;
	}
	return static_cast<void *>(data);
}



Data * deserialize( void * raw ) {
	Data *ret = new Data();
	int *nptr;
	char s1c[9];

	char *rawC = static_cast<char*>(raw);
   	int i = -1;
	while (++i < 8) {
		s1c[i] = rawC[i];
	}	
	s1c[8] = '\0';
	ret->s1 = std::string(s1c);
	
	nptr = reinterpret_cast<int*>(&rawC[8]);
	ret->n = *nptr;
   	i = -1;
	while (++i < 8) {
		s1c[i] = rawC[12 + i];
	}	
	ret->s2 = std::string(s1c);
	return (ret);
}
