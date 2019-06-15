/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 16:52:57 by tbehra            #+#    #+#             */
/*   Updated: 2019/05/30 21:03:18 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <algorithm>
#include <iostream>
#include <vector>
#include <time.h>

class IntContainer {
	public:
		IntContainer(unsigned int N);
		~IntContainer();
		void addNumber(int n);
		void addRandNumbers(size_t n_numbers, int min, int max);
		void printVec(void) const;
		unsigned int shortestSpan(void) const;
		unsigned int longestSpan(void) const;

	private:
		unsigned int _N;
		unsigned int _index;
		std::vector<int> _vec;
		
		IntContainer(IntContainer const & s);
		IntContainer & operator=(IntContainer const & s);
		IntContainer(void);
};


#endif
