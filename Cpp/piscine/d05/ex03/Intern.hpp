/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 21:25:49 by tbehra            #+#    #+#             */
/*   Updated: 2019/05/27 21:41:18 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include "Form.hpp"

class Form;

class Intern {

public:
	Intern(void);
	~Intern(void);
	Form *makeForm(std::string formName, std::string formTarget);

private:
	Intern(Intern const & s);
	Intern & operator=(Intern const & s);
};

std::ostream & operator<<(std::ostream & o, Intern const & s);

#endif
