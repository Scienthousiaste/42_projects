/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Exceptions.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 11:44:33 by tbehra            #+#    #+#             */
/*   Updated: 2019/06/17 14:55:24 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXCEPTIONS_HPP
# define EXCEPTIONS_HPP

# include <iostream>
class Exception : public std::exception {
	public:
		Exception(void);
		Exception(std::string str);
		virtual ~Exception() throw();
	
	protected:
		std::string _content;

	private:
//		Exception(Exception const & i);
		//virtual Exception & operator=(Exception const & i);
};

class EmptyStackException: public Exception {
	public:
		EmptyStackException(void);
};
class AssertIsFalseException: public Exception {
	public:
		AssertIsFalseException(void);
};
class NotAnInt8Exception: public Exception {
	public:
		NotAnInt8Exception(void);
};

/*
class InvalidValueException : public Exception {
	public:
		InvalidValueException(void);
		virtual ~InvalidValueException() throw(){}

	private:
		InvalidValueException(InvalidValueException const & i);
		virtual InvalidValueException & operator=(InvalidValueException const & );
};
*/

#endif
