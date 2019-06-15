/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutantstack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 21:05:08 by tbehra            #+#    #+#             */
/*   Updated: 2019/05/31 12:18:38 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANT_STACK_HPP
# define  MUTANT_STACK_HPP

#include <algorithm>
#include <stack>
#include <iostream>

template< typename T >
class MutantStack : public std::stack<T> {

public:

	class iterator {
		MutantStack	& _rhs;
		size_t		_index;
		iterator	&operator=(iterator const & _rhs);
		iterator();
	
	public:
		iterator(iterator const & _rhs) : _rhs(_rhs._rhs), _index(_rhs._index) {}
		iterator(MutantStack &st, size_t i) : _rhs(st), _index(i) {}
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
