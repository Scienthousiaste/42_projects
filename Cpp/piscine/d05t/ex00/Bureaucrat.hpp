/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 10:59:04 by tbehra            #+#    #+#             */
/*   Updated: 2019/05/27 13:19:38 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>

class Bureaucrat {

public:
	Bureaucrat(std::string name, unsigned int grade);
	~Bureaucrat(void);

	std::string getName() const;
	unsigned int getGrade() const;
	void decrementGrade();
	void incrementGrade();
	
	class GradeTooHighException : public std::exception {
	public:
		virtual const char* what() const throw() {
			return "Grade is too high!";
		}
	};
	class GradeTooLowException : public std::exception {
	public:
		virtual const char* what() const throw() {
			return "Grade is too low!";
		}
	};
	
private:
	std::string			_name;
	unsigned int		_grade;
	Bureaucrat(Bureaucrat const & s);
	Bureaucrat(void);
	Bureaucrat & operator=(Bureaucrat const & s);

};

std::ostream & operator<<(std::ostream & o, Bureaucrat const & s);

#endif
