/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 20:07:08 by tbehra            #+#    #+#             */
/*   Updated: 2019/05/30 13:26:35 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <exception>

template< typename T >
class Array {

public:
	Array<T>(void) : _len(0) {
		this->_arr = new T[0];
	}
	Array<T>(unsigned int n) : _len(n) {
		this->_arr = new T[n];
	}
	~Array<T>(void) {
		delete[] this->_arr;
	}

	Array<T>(Array<T> const & a) {
		delete[] this->_arr;
		this->_arr = new T[a.size()];
		this->_len = a.size();
		for (unsigned int i = 0; i < a.size(); i++)
			this->_arr[i] = T(a[i]);
	}

	Array<T> &		operator=(Array<T> const & a) {
		this->_len = a.size();
		delete[] this->_arr;
		this->_arr = new T[a.size()];
		for (unsigned int i = 0; i < a.size(); i++)
			this->_arr[i] = a[i];
		return (*this);
	}

	T	&	operator[](int n) const {
		 if ((n < 0) || (n >= (int)_len))
			 throw (std::exception());
		 else
			 return this->_arr[n];
	}

	unsigned int	size() const {
		return this->_len;
	}

private:
	T* _arr;
	unsigned int _len;
};

#endif
