/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 13:03:20 by tbehra            #+#    #+#             */
/*   Updated: 2019/05/20 13:10:08 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

std::string str_upper(std::string s) {
	int i;

	i = 0;
	while (s[i] != '\0') {
		s[i] = std::toupper(s[i]);
		i++;
	}
	return (s);
}

int		main(int ac, char **av) {
	int i;

	if (ac <= 1) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	}
	else {
		i = 1;
		while (i < ac) {
			std::cout << str_upper(av[i]);
			i++;
		}
		std::cout << std::endl;
	}
	return (0);
}
