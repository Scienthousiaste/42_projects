/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 13:38:54 by tbehra            #+#    #+#             */
/*   Updated: 2019/05/28 15:18:27 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

void usage(void) {
	std::cout << "Convert requires a single argument to convert" << std::endl;
}


int main(int ac, char **av) {
	if (ac != 2) {
		usage();
	}
	else {
		ScalarConvertor *sc
			= new ScalarConvertor(static_cast<std::string>(av[1]));
		sc->printConversions();
		delete sc;
	}
	return (0);
}
