/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 13:23:21 by tbehra            #+#    #+#             */
/*   Updated: 2019/05/27 15:54:43 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form {

public:
	Form(std::string name, unsigned int gradeSign, unsigned int gradeExecute);
	~Form(void);

	std::string getName() const;
	bool				getSigned() const;
	unsigned int	getGradeSign() const;
	unsigned int	getGradeExecute() const;
	void				beSigned(Bureaucrat const & b);

	class GradeTooHighException : public std::exception {
	public:
		virtual const char* what() const throw() {
			return "(Form) Grade is too high!";
		}
	};
	class GradeTooLowException : public std::exception {
	public:
		virtual const char* what() const throw() {
			return "(Form) Grade is too low!";
		}
	};
	
private:
	const std::string	_name;
	bool				_signed;
	const unsigned int	_gradeSign;
	const unsigned int	_gradeExecute;

	Form(Form const & s);
	Form(void);
	Form & operator=(Form const & s);

};

std::ostream & operator<<(std::ostream & o, Form const & f);

#endif
