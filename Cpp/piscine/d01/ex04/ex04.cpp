/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex04.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 12:58:34 by tbehra            #+#    #+#             */
/*   Updated: 2019/05/21 13:02:50 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int ac, char **av) {
	(void) ac;
	(void) av;
	std::string s = "HI THIS IS BRAIN";
	std::string* ptr = &s;
	std::string& ref = s;

	std::cout << "Using pointer: " << *ptr << std::endl;
	std::cout << "Using reference: " << ref << std::endl;

}
