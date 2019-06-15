/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 20:41:06 by tbehra            #+#    #+#             */
/*   Updated: 2019/05/27 21:16:06 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string target) :
	Form("RobotomyRequestForm", 72, 45, target) {
	srand(time(NULL));

}

RobotomyRequestForm::~RobotomyRequestForm() {

}

void RobotomyRequestForm::execute(Bureaucrat const & b) const {
	this->Form::checkExecution(b);
	std::cout << "Dzoiiiiiiii * dddrrrrrrruuuuUUUUUUUUUUUUUUU drrrrruUUUUUUUUU *" << std::endl;
	if (std::rand() % 2 == 1) {
		std::cout << this->getTarget() << " has been robotomized successfully!" << std::endl;
	}
	else {
		std::cout << this->getTarget() << "'s robotomization is a tragic failure." << std::endl;
	}	
}
