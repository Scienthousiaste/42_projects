/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 14:05:18 by tbehra            #+#    #+#             */
/*   Updated: 2019/05/20 18:02:48 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main(int ac, char **av) {
	std::string	buff;
	PhoneBook	phonebook;
	(void)ac;
	(void)av;

	std::cout << "Kungfu Rolodex Turbo Activated, enter thy commands!"
		<< std::endl;
	while (true) {
		std::cin >> buff;
		if (std::cin.eof())
			break;
		if (buff == "ADD")
			phonebook.addContact();
		if (buff == "SEARCH")
			phonebook.search();
		if (buff == "EXIT") {
			std::cout << "As a Ninja warrior must sometimes do, the Kungfu " 
				<< "Rolodex now goes to sleep" << std::endl;
			break;
		}
	}
	return (0);
}
