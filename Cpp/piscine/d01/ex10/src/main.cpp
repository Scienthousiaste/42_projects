/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 10:38:25 by tbehra            #+#    #+#             */
/*   Updated: 2019/05/22 11:14:46 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Reader.hpp"

int main(int ac, char **av) {
	int i;

	Reader reader;
	if (ac > 1) {
		i = 1;
		while (i < ac) {
			reader.cat_file(av[i]);
			i++;
		}	
	}
	else {
		reader.cat_console();
	}
}
