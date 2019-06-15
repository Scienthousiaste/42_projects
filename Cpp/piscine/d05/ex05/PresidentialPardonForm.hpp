/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 16:18:22 by tbehra            #+#    #+#             */
/*   Updated: 2019/05/27 21:09:51 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PRESIDENTIALPARDONFORM_HPP 
# define PRESIDENTIALPARDONFORM_HPP 

# include "Form.hpp"

class PresidentialPardonForm : public Form {

public:
	PresidentialPardonForm(std::string target);
	~PresidentialPardonForm(void);
	void execute(Bureaucrat const & b) const;

private:
	PresidentialPardonForm(PresidentialPardonForm const & s);
	PresidentialPardonForm(void);
	PresidentialPardonForm & operator=(PresidentialPardonForm const & s);
};

#endif
