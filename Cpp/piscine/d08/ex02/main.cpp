/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 21:12:50 by tbehra            #+#    #+#             */
/*   Updated: 2019/05/31 12:18:40 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mutantstack.hpp"


int main()
{
	MutantStack<int> mstack;
	std::cout << "push 1 then 2" << std::endl;
	mstack.push(1);
	mstack.push(2);
	std::cout << "top : " << mstack.top() << std::endl;
	std::cout << "pop" << std::endl;
	mstack.pop();
	std::cout << "size : " << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(4);
	mstack.push(5);
	mstack.push(6);

	std::cout << "pushing 3 4 5 and 6" << std::endl;
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

	std::stack<int> s(mstack);

	return 0;
}
