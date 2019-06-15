/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 20:41:06 by tbehra            #+#    #+#             */
/*   Updated: 2019/05/27 21:17:00 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP 
# define ROBOTOMYREQUESTFORM_HPP

# include <time.h>
# include "Form.hpp"

class RobotomyRequestForm : public Form {

public:
	RobotomyRequestForm(std::string target);
	~RobotomyRequestForm(void);
	void execute(Bureaucrat const & b) const;

private:
	RobotomyRequestForm(RobotomyRequestForm const & s);
	RobotomyRequestForm(void);
	RobotomyRequestForm & operator=(RobotomyRequestForm const & s);
};

#endif
