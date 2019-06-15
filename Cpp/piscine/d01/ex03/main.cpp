/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 11:51:57 by tbehra            #+#    #+#             */
/*   Updated: 2019/05/21 12:57:15 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieHorde.hpp"

int main(int ac, char **av) {
	(void) ac;
	(void) av;
	ZombieHorde zStack = ZombieHorde(10);
	ZombieHorde *zHeap;

	std::cout << "Zombies on the heap" << std::endl;
	zHeap = new ZombieHorde(4);
	zHeap->announce();
	std::cout << "Destructing the zombies on the heap" << std::endl;
	delete zHeap;
	
	std::cout << std::endl << "Zombies on the stack" << std::endl;
	zStack.announce();
	std::cout << "Last instruction of main" << std::endl;
}
