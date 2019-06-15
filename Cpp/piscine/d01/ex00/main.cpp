/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 09:18:09 by tbehra            #+#    #+#             */
/*   Updated: 2019/05/21 09:49:24 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.hpp"

void ponyOnTheHeap(bool is_a_unicorn, std::string favorite_marshmallow,
		std::string smell, int brightness, int cleanliness) {
	Pony *myPony;

   	myPony = new Pony(is_a_unicorn, favorite_marshmallow, smell, brightness,
			cleanliness);
	
	myPony->play();
	delete myPony;
}

void ponyOnTheStack(bool is_a_unicorn, std::string favorite_marshmallow,
		std::string smell, int brightness, int cleanliness) {
	Pony stackPony = Pony(is_a_unicorn, favorite_marshmallow, smell, brightness,
			cleanliness);
	stackPony.play();
}

int main(int ac, char **av) {
	(void) ac;
	(void) av;
	ponyOnTheStack(false, "Blood Gummy", "Autumnal diarrhea", 12, -2);
	ponyOnTheHeap(true, "Rainbow cotton candy", "Luna by Channel5", 31, 99999);
	return (0);
}
