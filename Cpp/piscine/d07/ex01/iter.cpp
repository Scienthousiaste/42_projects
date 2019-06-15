/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 16:33:04 by tbehra            #+#    #+#             */
/*   Updated: 2019/05/29 22:07:31 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template< typename T >
void iter(T *array, size_t len, void (*f)(T)) {
	for (size_t i = 0; i < len; i++)
		f(array[i]);
}


void printSquare(int i) {
	std::cout << i * i << std::endl;
}

void printToUpper(std::string s) {
	int i = 0;

	while(s[i] != '\0') {
		std::cout << static_cast<char>(std::toupper(s[i]));
		i++;
	}
	std::cout << std::endl;
}

int main() {

	int t[6] = {0, 1, 2, 3, 4, 5};
	std::string s[4] = {"abc", "lolipop", "binouse quand tu nous tiens", "Lady dit et toto sont sur un bateau"};
	iter(t, 6, &printSquare);
	iter(s, 4, &printToUpper); 

	return 0;
}

