/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 15:14:27 by tbehra            #+#    #+#             */
/*   Updated: 2019/05/21 18:58:47 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace.hpp"

std::string search_replace_all(std::string buf, std::string s1, std::string s2) {
	size_t index_found;
	size_t pos;

	pos = 0;
	while ((index_found = buf.find(s1, pos)) != (size_t)-1) {
		std::cout << "index found: " << index_found << std::endl;
		buf.replace(index_found, s1.length(), s2);
		pos = index_found + s2.length();
	}
	(void)s2;
	return (buf);
}

int main(int ac, char **av) {
	std::string filename;

	if (ac != 4) {
		std::cout << "This program needs a filename and 2 strings." << std::endl;
	}
	else {
		filename = av[1];
		if (std::string(av[2]).length() < 1 || std::string(av[3]).length() < 1) {
			std::cout << "Search or replace string invalid" << std::endl;
			return (1);
		}
		std::ifstream read_file(filename);
		
		if (read_file.is_open()) {
			if (filename.find(".replace") != std::string::npos) {
				std::cout << "Sorry, replace cannot replace on .replace files, change the name if "
					<< "you want to use this file!" << std::endl;
					return (1);
			}
			std::ofstream write_file(filename.substr(0, filename.find(".")) + ".replace");
			std::stringstream buffer;
			buffer << read_file.rdbuf();
			write_file << search_replace_all(buffer.str(), std::string(av[2]), std::string(av[3]));
			write_file.close();
		}
		else {
			std::cout << av[1] << ": file not found" << std::endl;
			return (1);
		}
		read_file.close();
	}
	return (0);
}
