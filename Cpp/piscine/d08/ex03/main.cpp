/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 12:35:20 by tbehra            #+#    #+#             */
/*   Updated: 2019/05/31 22:20:00 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <map>
#include "Mindopen.hpp"

std::map<char, char> buildTranslationMap(void) {
	std::map<char, char> ret;

	for(int i = 0; i < NUM_SYMBOLS; i++) {
		ret[BF_CHARS[i]] = OPEN_CHARS[i];
	}

	return ret;
}

bool isBrainfuck(std::string s, std::map<char, char>dico) {
	for (std::string::iterator it = s.begin(); it < s.end(); it++) {
		if (!std::isspace(*it) && dico.find(*it) == dico.end()) {
			return false;
		}
	}
	return true;
}

bool isOpenmind(std::string s, std::map<char, char>dico) {
	bool isOpenmindChar;
	for (std::string::iterator it = s.begin(); it < s.end(); it++) {
		if (!std::isspace(*it)) {
			isOpenmindChar = false;
			for(std::map<char, char>::iterator iter = dico.begin();
				   iter != dico.end(); ++iter)
			{
				if (iter->second == *it || iter->second == 0) {
					isOpenmindChar = true;
					break;
				}
			}
			if (!isOpenmindChar) {
				return false;
			}
		}
	}
	return true;
}

std::string translateToOpen(std::string bf, std::map<char, char> dico) {
	std::string ret = bf;

	for (std::string::iterator it = ret.begin(); it < ret.end(); it++) {
		*it = dico[*it]; 
	}
	*(ret.end() -1) = '\n';
	return ret;
}

void openYourMind(std::string & instructions) {
	Mindopen mo(instructions);


}

int main(int ac, char **av) {
	if (ac != 2)
		std::cout << "Please enter a file containing open instructions" << std::endl;
	else {
		std::ifstream inputFile;
		std::map<char, char> dico = buildTranslationMap();
		std::string instructions;

		inputFile.open(av[1]);
		if (inputFile.is_open()) {
			instructions.assign((std::istreambuf_iterator<char>(inputFile)),
			            std::istreambuf_iterator<char>());
			if (isBrainfuck(instructions, dico)) {
				std::cout << "That's B********!!! Quick, look somewhere else"
					" while we translate that filthy thing!" << std::endl;
				std::ofstream outputFile(std::string(av[1]) + ".open");
				outputFile << translateToOpen(instructions, dico);
			}
			else if (isOpenmind(instructions, dico)) {
				openYourMind(instructions);
			}
			else {
				std::cout << "This program can only read Openmind instructions"
					<< std::endl;
			}
		}
	}
	return 0;
}
