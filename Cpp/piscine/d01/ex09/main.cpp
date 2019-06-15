/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 19:12:32 by tbehra            #+#    #+#             */
/*   Updated: 2019/05/22 10:33:19 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Logger.hpp"

int main() {
	Logger logger("log");
	logger.log("file", "Hello !");
	logger.log("file", "..world!");

	logger.log("console", "let's log on the console now!");
	logger.log("console", "on the console now!");
	logger.log("file", "third log");
	logger.log("console", "the console now!");
	logger.log("nowhere", "oups");
	return (0);
}
