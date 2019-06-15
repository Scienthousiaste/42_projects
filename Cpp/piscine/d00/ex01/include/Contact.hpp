/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 13:34:50 by tbehra            #+#    #+#             */
/*   Updated: 2019/05/20 16:38:59 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>

# define NB_VARIABLES 11

class Contact {

public:
	static const std::string var_names[NB_VARIABLES];
	
	Contact();
	~Contact(void);

	std::string get_var(std::string var_name) const;
	void set_var(std::string var_name, std::string value);
	void search(void) const;

private:
	std::string	_vars[NB_VARIABLES];
	static int var_index(std::string var_name); 
};

#endif
