/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 18:38:45 by tbehra            #+#    #+#             */
/*   Updated: 2019/05/28 19:18:11 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <time.h>
#include <stdlib.h>
#include <iostream>


Base * generate(void) {
	int r;
	static int entropy = 0;

	r = (rand() + entropy++) % 3;
	if (r == 0)
		return new A();
	if (r == 1)
		return new B();
	else
		return new C();
}

void identify_from_reference(Base & b) {
	Base base;
	try {
		base = dynamic_cast<A&>(b);
		std::cout << "A" << std::endl;
		return ;
	}
	catch (std::exception e){

		try {
			base = dynamic_cast<B&>(b);
			std::cout << "B" << std::endl;
			return ;
		}
		catch (std::exception ee){
			try {
				base = dynamic_cast<C&>(b);
				std::cout << "C" << std::endl;
				return ;
			}
			catch (std::exception eee){
				std::cout << "Unknown type for this reference" << std::endl;
			}
		}
	}
}

void identify_from_pointer(Base *b) {
	if (dynamic_cast<A*>(b)) {
		std::cout << "A" << std::endl;
	}
	else if (dynamic_cast<B*>(b)) {
		std::cout << "B" << std::endl;
	}
	else if (dynamic_cast<C*>(b)) {
		std::cout << "C" << std::endl;
	}
	else {
		std::cout << "Unknown type for this pointer" << std::endl;
	}
}

int main(void) {
	Base i;

	srand(time(NULL));
	Base *m = generate();
	Base *m2 = generate();
	std::cout << "Real type from pointers" << std::endl;
	identify_from_pointer(m);
	identify_from_pointer(m2);
	identify_from_pointer(reinterpret_cast<Base *>(&i));

	std::cout << std::endl << "Real type from references" << std::endl;
	identify_from_reference(*m);
	identify_from_reference(*m2);
	identify_from_reference(reinterpret_cast<Base &>(i));

	delete m;
	delete m2;
	return (0);
}
