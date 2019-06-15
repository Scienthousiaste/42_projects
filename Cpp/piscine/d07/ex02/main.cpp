/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 20:09:00 by tbehra            #+#    #+#             */
/*   Updated: 2019/05/30 13:26:34 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

int main(void) {

	Array<int>a(0);

	try {
		std::cout << "a[-11] = 12   -> ";
		a[-11] = 12;
	}
	catch (std::exception e) {
		std::cout << e.what() << std::endl;
	}
	try {
		std::cout << "a[0] = 12   -> ";
		a[0] = 12;
	}
	catch (std::exception e) {
		std::cout << e.what() << std::endl;
	}

	Array<char>b(100);
	for (int i = 0; i < 100; i++) {
		b[i] = 'a' + (i % 26);
	}
	b[99] = '\0';
	std::cout << reinterpret_cast<char*>(&b[0]) << std::endl;

  	Array<std::string>s_arr(5);

	std::string s = "pump it up";
	s_arr[0] = s;
	s_arr[1] = "bolognaise papaye";
	s_arr[2] = "fElon Musk";
	std::cout << s_arr[0] << std::endl << s_arr[1]  << std::endl;

	Array<char>c_arr(b);
	std::cout << "size b : " << b.size() << std::endl;
	std::cout << "b addr : " << reinterpret_cast<void*>(&b[0]) << std::endl;
	std::cout << "size c_arr : " << c_arr.size() << std::endl;
	std::cout << "c addr : " << reinterpret_cast<void*>(&c_arr[0]) << std::endl;

	std::cout << reinterpret_cast<char*>(&c_arr[0]) << std::endl;


	return (0);
}
