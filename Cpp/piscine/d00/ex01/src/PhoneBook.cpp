/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 13:59:55 by tbehra            #+#    #+#             */
/*   Updated: 2019/05/20 18:02:46 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

PhoneBook::PhoneBook(void) {
	this->_current_contact = 0;
}

PhoneBook::~PhoneBook(void) {
}

std::string build_content_index(size_t i) {
	int n_spaces;
	std::string ret;
	const std::string spaces = "          ";

	ret = std::to_string(i);
	n_spaces = WIDTH_COL - ret.length();
	
	ret = "|" + spaces.substr(0, n_spaces) + ret + "|";
	return (ret);
}

std::string build_content(std::string s) {
	int					n_spaces;
	std::string			ret;
	const std::string	spaces = "          ";

	n_spaces = WIDTH_COL - s.length();
	if (n_spaces > 0) {
		ret = spaces.substr(0, n_spaces) + s;
	}
	else if (s.length() > 10) {
		ret = s.substr(0, 9) + '.';
	}
	else {
		ret = s;
	}
	return (ret + "|");
}

void	display_contact(Contact c) {
	int i;

	i = 0;
	while (i < NB_VARIABLES) {
		std::cout << Contact::var_names[i] << ": "
			<< c.get_var(Contact::var_names[i]) << std::endl;
		i++;
	}
}

void	PhoneBook::search(void) {
	size_t i;
	std::string input;

	if (this->_current_contact == 0) {
		std::cout << "No contact at the moment!" << std::endl; 
		return;
	}
	std::cout << "|" << build_content("index") << build_content("first name")
		<< build_content("last name") << build_content("nickname") << std::endl;
	i = 0;
	while (i < this->_current_contact) {
		std::cout << build_content_index(i)
			<< build_content(this->_contacts[i].get_var("first name"))
			<< build_content(this->_contacts[i].get_var("last name"))
			<< build_content(this->_contacts[i].get_var("nickname"))
			<< std::endl;
		i++;
	}
	std::cout << "Enter index of contact you want to know more about." << std::endl;
	std::cin >> input;
	try {
		if (std::cin.eof()) {
			return ;
		}
		if (stoi(input) >= 0 && stoi(input) < (int)this->_current_contact)
			display_contact(this->_contacts[stoi(input)]);
		else
			std::cout << "That's not an index.." << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << "Ugh.. stop writing disgusting things like that." << std::endl;
	}
}

void	PhoneBook::addContact(void) {
	int i;
	std::string buff;

	i = 0;

	if (this->_current_contact == NB_CONTACTS) {
		 	std::cout << "The contact list is full: the Kungu rolodex "
				<< "humbly recognizes it should be more powerful, but won't do"
				<< " anything more." << std::endl;
		return ;
	}
	while (i < NB_VARIABLES) {
		std::cout << "Dear new contact, please input your "
			<< Contact::var_names[i] << std::endl; 
		std::cin >> buff;
		(this->_contacts[_current_contact]).set_var(Contact::var_names[i], buff); 
		i++;
	}

	std::cout << "Thank you! You can enter new commands." << std::endl;
	this->_current_contact++;
}
