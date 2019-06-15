/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mindopen.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 15:56:08 by tbehra            #+#    #+#             */
/*   Updated: 2019/05/31 22:59:41 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Mindopen.hpp"
#include "IncrementPointer.hpp"


# include "IncrementPointer.hpp"
# include "DecrementPointer.hpp"
# include "IncrementCell.hpp"
# include "DecrementCell.hpp"
# include "OpenLoop.hpp"
# include "CloseLoop.hpp"
# include "InputData.hpp"
# include "OutputData.hpp"

static AInstruction *getInstruction(char c) {
	if (c == OPEN_CHARS[0])
		return new OpenLoop();
	else if (c == OPEN_CHARS[1])
		return new CloseLoop();
	else if (c == OPEN_CHARS[2])
		return new IncrementPointer();
	else if (c == OPEN_CHARS[3])
		return new DecrementPointer();
	else if (c == OPEN_CHARS[4])
		return new IncrementCell();
	else if (c == OPEN_CHARS[5])
		return new DecrementCell();
	else if (c == OPEN_CHARS[6])
		return new OutputData();
	else if (c == OPEN_CHARS[7])
		return new InputData();
	return NULL;
}


Mindopen::Mindopen(std::string & instructions) : _mem(std::list<uint8_t>(1, 0)) {
	AInstruction *inst;
	this->_it = this->_mem.begin();
	
	for (std::string::iterator it = instructions.begin();
			it < instructions.end(); it++) {
		try {
			inst = getInstruction(*it);
			if (inst) {
				this->_inst.push_back(inst);
			}
		}
		catch (std::exception e) {
			std::cout << "Error while parsing instruction";
		}
	}

	AInstruction *current_inst;

	_inst_it = _inst.begin();
	while (_inst_it != _inst.end()) {
		current_inst = *_inst_it;
		current_inst->exec(this);
		_inst_it++;
	}
}

Mindopen::~Mindopen() {
}

void Mindopen::openLoop(void) {
	AInstruction *current_inst;

	if (*(_it) == 0) {
		_inst_it++;
		unsigned int to_close = 1;
		while (to_close) {
			current_inst = *_inst_it;
			if (current_inst->getNameInstruction() == "OpenLoop")
				to_close++;
			else if (current_inst->getNameInstruction() == "CloseLoop")
				to_close--;
			if (to_close == 0) {
				_inst_it++;
				break;
			}
			_inst_it++;	
			if(_inst_it == _inst.end())
				throw (std::exception());
		}
	}
}

void Mindopen::closeLoop(void) {
	AInstruction *current_inst;
	if (*(_it) != 0) {
		_inst_it--;
		unsigned int to_close = 1;
		while (to_close) {
			current_inst = *_inst_it;
			if (current_inst->getNameInstruction() == "CloseLoop")
				to_close++;
			else if (current_inst->getNameInstruction() == "OpenLoop")
				to_close--;
			if (to_close == 0) {
				break;
			}
			_inst_it--;
			if(_inst_it == _inst.begin())
				throw (std::exception());
		}
	}
}

