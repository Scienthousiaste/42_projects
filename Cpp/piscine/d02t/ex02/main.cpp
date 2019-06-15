#include <iostream>
#include "Fixed.hpp"
int main( void ) {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;


	Fixed const c(Fixed(10.1f) + Fixed(9.9f));
	Fixed d(Fixed(1000.1f) + Fixed(999.9f));
	std::cout << c << std::endl;


	int i = 0;

	while (i < 1000) {
		i++;
		d++;
		if (i %100 == 59)
			std::cout << d << std::endl;
	}

	Fixed e(Fixed(10));
	std::cout << e * 200 << std::endl;
	std::cout << e * Fixed(2.1f) << std::endl;

	Fixed f(2.01f);
	std::cout << f <<" "<< f*f << " " << f*f*f << " " << f*f*f*f << " " << std::endl;

	Fixed h (0);
	std::cout << Fixed(3) / h << std::endl;
	std::cout << Fixed(0) / h << std::endl;
	std::cout << Fixed(0.0f / 0) << std::endl;
	return 0;
}
