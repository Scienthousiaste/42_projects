/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 17:14:37 by tbehra            #+#    #+#             */
/*   Updated: 2019/05/28 18:27:16 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serialize.hpp"
#include <unistd.h>

int main() {

	char *cptr;
	char s1[9];
	char s2[9];

	s1[8] = '\0';
	s2[8] = '\0';

	int i = -1;

	void *mystere = serialize();
	(void) mystere;
	cptr = static_cast<char*>(mystere);
	std::cout << "20 raw octets : "<< std::endl;
	while (++i < (20)) {
		write(1, &cptr[i], 1);
	}

	std::cout << std::endl;
	std::cout << "8 first chars: " << std::strncpy(s1, static_cast<char*>(&cptr[0]), 8)
		<< std::endl;
	int *myInt = reinterpret_cast<int*>(&cptr[8]);
	std::cout << "Int in the 4 next chars: " << *myInt << std::endl;
	std::cout << "8 last chars: " << std::strncpy(s1, static_cast<char*>(&cptr[12]), 8)
		<< std::endl;

	Data *d = deserialize(mystere);
	std::cout << "s1: " << d->s1 << std::endl;
	std::cout << "n: " << d->n << std::endl;
	std::cout << "s2: " << d->s2 << std::endl;
	
	delete d;
}
