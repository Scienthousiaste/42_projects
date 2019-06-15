/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 16:29:15 by tbehra            #+#    #+#             */
/*   Updated: 2019/05/27 20:40:18 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) :
	Form("ShrubberyCreationForm", 145, 137, target) {
}

ShrubberyCreationForm::~ShrubberyCreationForm() {

}

void ShrubberyCreationForm::execute(Bureaucrat const & b) const {
	this->Form::checkExecution(b);
	std::ofstream file(this->getTarget() + "_shrubbery");
	if (file) {
		file << "root\n+-- things\n    --stuff\n    --otherStuff\n+-- IMPORTANT\n    --rilakuma in the woods\n    --pedobear adventures\n    --secretKey\n";
	}
	else {
		std::cout << "The form execution failed and you CANNOT blame the "
			<< "administration this time : the file couldn't open." << std::endl;
	}
}
