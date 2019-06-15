/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 17:10:30 by tbehra            #+#    #+#             */
/*   Updated: 2019/05/30 21:03:15 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"
# define MILLION 1000000
# define BILLION 1000000000

int main(void) {

	IntContainer ic(8);
	ic.addNumber(90);

	try {
		std::cout << "Longest Span = " << ic.longestSpan() << std::endl;
	}
	catch (std::exception e) {
		std::cout << "exception (only 1 number -> no span)" << std::endl;
	}
	ic.addNumber(-20);
	ic.addNumber(20);
	ic.printVec();
	std::cout << "Longest Span = " << ic.longestSpan() << std::endl;

	std::cout << "10 random numbers" << std::endl;
	
	IntContainer ic2(10);
	ic2.addRandNumbers(10, 0, 500);

	ic2.printVec();
	std::cout << "Longest span = " << ic2.longestSpan() << std::endl;
	std::cout << "Shortest span = " << ic2.shortestSpan() << std::endl;

	IntContainer icc(MILLION);
	std::cout << "New container with a million random numbers" << std::endl;
	icc.addRandNumbers(MILLION, 0, BILLION);
	std::cout << "Longest span = " << icc.longestSpan() << std::endl;
	std::cout << "Shortest span = " << icc.shortestSpan() << std::endl;

	return (0);
}
