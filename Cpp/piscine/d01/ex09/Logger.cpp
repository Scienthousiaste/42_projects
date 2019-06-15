/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Logger.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 19:09:58 by tbehra            #+#    #+#             */
/*   Updated: 2019/05/22 10:35:14 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Logger.hpp"

Logger::Logger(std::string logFile) : _logFileName(logFile) {
}

Logger::~Logger(void) {
}

void Logger::logToConsole(std::string const & s) const {
	std::cout << this->makeLogEntry(s);
}

void Logger::logToFile(std::string const & s) const {
	std::ofstream write_file(this->_logFileName, std::ofstream::app);
	write_file << this->makeLogEntry(s);
}

std::string Logger::makeLogEntry(std::string const & s) const {
	std::time_t t = std::time(nullptr);
	char timeString[21];
	if (std::strftime(timeString, sizeof(timeString),
			"[%Y%m%d_%H%M%S] ", std::localtime(&t))) {
			 return (timeString + s + '\n');
	}
	return ("[Erreur timestamp] " + s + '\n');
}

void Logger::log(std::string const & dest, std::string const & message) const {
	void (Logger::*destination[NB_DEST])(std::string const & s) const = {
		&Logger::logToFile,
		&Logger::logToConsole };
	std::string destNames[NB_DEST] = {"file", "console"};
	void (Logger::*finalDestination)(std::string const & s) const;

	int i = 0;
	while (i < NB_DEST) {
		if (destNames[i] == dest) {
			finalDestination = destination[i];
			(this->*finalDestination)(message);
			return ;
		}
		i++;
	}
	std::cout << "Couldn't log on " << dest << ", the 2 valid destinations are "
		<< "console and file." << std::endl;
}
