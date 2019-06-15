/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 13:23:21 by tbehra            #+#    #+#             */
/*   Updated: 2019/05/27 21:24:32 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form {

public:
	Form(std::string name, unsigned int gradeSign,
			unsigned int gradeExecute, std::string target);
	virtual ~Form(void);

	std::string			getName() const;
	bool				getSigned() const;
	unsigned int		getGradeSign() const;
	unsigned int		getGradeExecute() const;
	const std::string	getTarget() const;
	void				beSigned(Bureaucrat const & b);
	void				checkExecution(Bureaucrat const & b) const;
	virtual void		execute(Bureaucrat const & b) const = 0;


	class UnsignedFormException : public std::exception {
	public:
		virtual const char* what() const throw() {
			return "This form is not signed!";
		}
	};
	class GradeTooHighException : public std::exception {
	public:
		virtual const char* what() const throw() {
			return "Bureaucrat grade is too high!";
		}
	};
	class GradeTooLowException : public std::exception {
	public:
		virtual const char* what() const throw() {
			return "Bureaucrat grade is too low!";
		}
	};
	
private:
	const std::string	_name;
	bool				_signed;
	const unsigned int	_gradeSign;
	const unsigned int	_gradeExecute;
	const std::string	_target;

	Form(Form const & s);
	Form(void);
	Form & operator=(Form const & s);

};

std::ostream & operator<<(std::ostream & o, Form const & f);

#endif
