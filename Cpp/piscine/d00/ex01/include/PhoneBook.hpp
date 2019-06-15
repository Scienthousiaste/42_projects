/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 13:24:05 by tbehra            #+#    #+#             */
/*   Updated: 2019/05/20 17:23:57 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <string>
#include <iostream>
#include "Contact.hpp"

#define NB_CONTACTS 8
#define WIDTH_COL 10

class PhoneBook {

public:
	PhoneBook(void);
	~PhoneBook(void);
	
	void addContact(void);
	void search(void);

private:
	size_t			_current_contact;
	Contact			_contacts[NB_CONTACTS];
};

#endif
