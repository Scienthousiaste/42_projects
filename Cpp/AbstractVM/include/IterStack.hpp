/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IterStack.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 11:07:53 by tbehra            #+#    #+#             */
/*   Updated: 2019/06/17 16:43:49 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERSTACK_HPP
# define ITERSTACK_HPP 

#include <algorithm>
#include <stack>
#include <iostream>

template< typename T >
class IterStack : public std::stack<T> {

public:

	class iterator {
		IterStack	& _rhs;
		size_t		_index;
		iterator	&operator=(iterator const & _rhs);
		iterator();
	
	public:
		iterator(iterator const & _rhs) : _rhs(_rhs._rhs), _index(_rhs._index) {}
		iterator(IterStack &st, size_t i) : _rhs(st), _index(i) {}
		~iterator() {}

		iterator &	operator++(void) {
			if (_index < _rhs.size())
				_index++;
			return (*this);
		}
		iterator &	operator--(void) {
			if (_index > 0)
				_index--;
			return (*this);
		}
		bool	operator==(iterator const & _rhs) {
			return (_index == _rhs._index);
		}
		bool	operator!=(iterator const & _rhs) { 
			return (_index != _rhs._index);
		}
		T	&	operator*(void) const{
			return _rhs.c[_index];
		}
	};

	iterator	begin()
	{
		return (iterator(*this, 0));
	}

	iterator	end()
	{
		return (iterator(*this, this->size()));
	}

};

#endif
