/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 15:24:32 by tbehra            #+#    #+#             */
/*   Updated: 2019/05/29 21:01:37 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template< typename T >
void swap(T & a, T & b) {
	T c;
	c = a;
	a = b;
	b = c;
}
	
template< typename T >
T const & min(T const & a, T const & b) {
	return (a < b ? a : b);	
}

template< typename T >
T const & max(T const & a, T const & b) {
	return (a > b ? a : b);	
}


int main(void) {
	int a = -42;
	int b = -42;

	std::cout << "addr a "<< &a << ", addr b " << &b << std::endl;
	std::cout << "min a ("<< a << "), b(" << b << "): " << min(a, b) << " ("
		<< &(min(a, b)) << ") " << std::endl;
	a = 42;
	std::cout << "min a ("<< a << "), b(" << b << "): " << min(a, b) << " ("
		<< &(min(a, b)) << ") " << std::endl;
	b = 51;
	std::cout << "min a ("<< a << "), b(" << b << "): " << min(a, b) << " ("
		<< &(min(a, b)) << ") " << std::endl;

	std::cout << "max a ("<< a << "), b(" << b << "): " << max(a, b) << " ("
		<< &(max(a, b)) << ") " << std::endl;
	
	std::cout << "Swap(a, b)" << std::endl;
	swap<int>(a, b);
	std::cout << "swap a ("<< a << "), b(" << b << "): " << max(a, b) << " ("
		<< &(max(a, b)) << ") " << std::endl;

	char cc = 'c';
	char dd = 'd';


	std::cout << "min cc ("<< cc << "), dd(" << dd << "): " << min(cc, dd)
	   	<< std::endl;
	cc = 'l';
	std::cout << "min cc ("<< cc << "), dd(" << dd << "): " << min(cc, dd)
	   	<< std::endl;
	std::cout << "max cc ("<< cc << "), dd(" << dd << "): " << max(cc, dd)
	   	<< std::endl;
	std::cout << "Swap(cc, dd)" << std::endl;

	int aa = 2;
	int bb = 3;
	swap( aa, bb );
	std::cout << "aa = " << aa << ", bb = " << bb << std::endl;
	std::cout << "min( aa, bb ) = " << ::min( aa, bb ) << std::endl;
	std::cout << "max( aa, bb ) = " << ::max( aa, bb ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap<std::string>(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

	return (0);

}
