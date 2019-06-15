/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 12:09:27 by tbehra            #+#    #+#             */
/*   Updated: 2019/05/27 18:26:14 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"


int main(void) {
	Bureaucrat *Francis = new Bureaucrat("Francis", 10);
	Bureaucrat *Fabienne = new Bureaucrat("Fabienne", 130);
	
	Form *a_42 = new Form("A42", 42, 42);
	Form *a_100 = new Form("A100", 100, 100);
	
	try {
		Form *b_42 = new Form("B42", 42, 151);
		(void)b_42;
	}
	catch (std::exception & e) {
		std::cout << "Exception : " << e.what() << std::endl;
	}
	try {
		Form *c_42 = new Form("C42", 42, 0);
		(void)c_42;
	}
	catch (std::exception & e) {
		std::cout << "Exception : " << e.what() << std::endl;
	}
	try {
		Form *d_42 = new Form("D42", 0, 10);
		(void)d_42;
	}
	catch (std::exception & e) {
		std::cout << "Exception : " << e.what() << std::endl;
	}
	try {
		Form *e_42 = new Form("E42", 151, 42);
		(void)e_42;
	}
	catch (std::exception & e) {
		std::cout << "Exception : " << e.what() << std::endl;
	}

	std::cout << *a_42 << std::endl;
	Francis->signForm(*a_42);
	std::cout << *a_42 << std::endl;

	std::cout << *a_100 << std::endl;
	Fabienne->signForm(*a_100);
	std::cout << *a_100 << std::endl;


	delete Francis;
	delete Fabienne;
}
