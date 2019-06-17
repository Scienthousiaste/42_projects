/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 16:11:17 by tbehra            #+#    #+#             */
/*   Updated: 2019/06/17 17:02:59 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AbstractVM.hpp"

int main(int ac, char **av) {

	AbstractVM avm;

	if (ac == 1) {
		avm.push(avm.getFactory().createInt8(std::string("8")));
		avm.push(avm.getFactory().createInt32(std::string("32")));
		avm.dump();
		avm.pop();
		avm.dump();
		avm.pop();
		avm.dump();
		avm.push(avm.getFactory().createFloat(std::string("888.55")));
		avm.push(avm.getFactory().createFloat(std::string("44.55")));
		avm.dump();

		avm.assert(avm.getFactory().createFloat(std::string("44.55")));
		std::cout << std::endl;
		avm.dump();
		std::cout << std::endl;
		avm.add();
		avm.dump();

		std::cout << std::endl;
		std::cout << std::endl;
		avm.push(avm.getFactory().createInt8(std::string("55")));
		avm.print();
		avm.push(avm.getFactory().createInt8(std::string("65")));
		avm.print();
	}
	else {
		(void)av[0];
	}

	return 0;
}
