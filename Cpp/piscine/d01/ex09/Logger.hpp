/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Logger.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 19:04:30 by tbehra            #+#    #+#             */
/*   Updated: 2019/05/21 19:58:43 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOGGER_H
# define LOGGER_H

# include <iostream>
# include <fstream>

# define NB_DEST 2

class Logger {

	public:
		Logger(std::string logFile);
		~Logger(void);
		void log(std::string const & dest, std::string const & message) const;	

	private:
		void logToConsole(std::string const & s) const;
		void logToFile(std::string const & s) const;
		std::string makeLogEntry(std::string const & s) const;
		std::string _logFileName;
};

#endif
