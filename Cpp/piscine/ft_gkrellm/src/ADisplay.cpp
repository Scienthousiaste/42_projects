#include "ADisplay.hpp"
#include <iostream>

std::list<AModule *> ADisplay::getModules() {
	return _modules;
}

void ADisplay::reorderModules() {

}

void ADisplay::toggleModule(AModule *module) {
	module->setActive(!module->isActive());
}

void	ADisplay::swapModule(bool up) {
	std::list<AModule *>::iterator nextM(_selected);
	if (!up) {
		++nextM;
		if (nextM == _modules.end())
			return;
		std::swap(*_selected, *nextM);
		_selected = nextM;
	}
	else if (up && _selected != _modules.begin()) {
		--nextM;
		std::swap(*_selected, *nextM);
		_selected = nextM;
	}
}
