/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 16:18:22 by tbehra            #+#    #+#             */
/*   Updated: 2019/05/27 18:56:55 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <fstream>
# include <sstream>
# include "Form.hpp"

class ShrubberyCreationForm : public Form {

public:
	ShrubberyCreationForm(std::string target);
	~ShrubberyCreationForm(void);
	void execute(Bureaucrat const & b) const;

private:
	ShrubberyCreationForm(ShrubberyCreationForm const & s);
	ShrubberyCreationForm(void);
	ShrubberyCreationForm & operator=(ShrubberyCreationForm const & s);
};

#endif
