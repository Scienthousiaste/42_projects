/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 13:41:34 by tbehra            #+#    #+#             */
/*   Updated: 2019/05/31 21:45:06 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <list>
#include "easyfind.hpp"


int main(void) {

	int myints[] = { 10, 20, 30, 40 };
	std::vector<int> myvector (myints,myints+4);

	size_t indexFound = easyfind(myvector, 30);
	
	std::cout << "easyfind(myvector, 30) : " << indexFound << std::endl;
	indexFound = easyfind(myvector, 20);
	std::cout << "easyfind(myvector, 20) : " << indexFound << std::endl;
	indexFound = easyfind(myvector, 22);
	std::cout << "easyfind(myvector, 22) : ";
	if (indexFound > myvector.size())
		std::cout << "not found" << std::endl;
	else
		std::cout << indexFound << std::endl;
	
	return (0);
}
