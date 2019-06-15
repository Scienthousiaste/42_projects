/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mindopen.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 17:18:40 by tbehra            #+#    #+#             */
/*   Updated: 2019/05/31 23:01:48 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINDOPEN_HPP
# define MINDOPEN_HPP

# include <list>
# include <iostream>
# include <istream>
# include "AInstruction.hpp"
# include <string>

#define NUM_SYMBOLS 8
#define BF_CHARS "[]<>+-.,"
#define OPEN_CHARS "}{:;08@4"


class Mindopen {
	public:
		Mindopen(std::string & instructions);
		~Mindopen();

		void incrementPointer(void) {
			if (_it == _mem.end()) {
				_mem.push_back(0);
			}
			_it++;
		}
		void decrementPointer(void) {
			if (_it == _mem.begin()) {
				_mem.push_front(0);
			}
			_it--;
		}
		void incrementCell(void) {
			*_it = *_it + 1;
		}
		void decrementCell(void) {
			*_it = *_it - 1;
		}
		void inputData(void) {
			char c;
			c = getchar();
			*_it = static_cast<uint8_t>(c);
		}
		void outputData(void) {
			std::cout << (char)*_it;
		}
		void openLoop(void);
		void closeLoop(void);

	private:
		std::list<uint8_t> 				_mem;
		std::list<uint8_t>::iterator	_it;
		std::list<AInstruction*>		_inst;
		std::list<AInstruction*>::iterator		_inst_it;
		
		Mindopen(void);
		Mindopen(Mindopen const & s);
		Mindopen & operator=(Mindopen const & s);
};

#endif
