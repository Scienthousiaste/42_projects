/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 14:02:29 by tbehra            #+#    #+#             */
/*   Updated: 2019/05/20 16:35:17 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

const std::string Contact::var_names[NB_VARIABLES] = {"first name", "last name",
	"nickname", "login", "postal address", "email", "phone number", "birthday",
	"favorite meal", "underwear color", "darkest secret"};

Contact::Contact(void) {
}

Contact::~Contact(void) {
}

std::string Contact::get_var(std::string var_name) const {
	int i;
	
	i = Contact::var_index(var_name);
	if (i == -1)
		return ("_NA_");
	return (this->_vars[i]);
}

void Contact::set_var(std::string var_name, std::string value) {
	int i;
	
	i = Contact::var_index(var_name);
	if (i == -1)
		return ;
	this->_vars[i] = value;
}

int Contact::var_index(std::string var_name) {
	int ret;

	ret = 0;
	while (ret < NB_VARIABLES)
	{
		if (Contact::var_names[ret] == var_name)
			return (ret);
		ret++;
	}
	return (-1);
}
