#include "MemoryModule.hpp"
#include <cstdlib>

MemoryModule::MemoryModule() {
	_cmd = "hwmemsize=$(sysctl -n hw.memsize) && ramsize=$(expr $hwmemsize / $((1024**3))) && echo \"${ramsize} GB\"";
	_active = true;
	_name = "mem";
}

MemoryModule::MemoryModule(MemoryModule const &src) {
	*this = src;
}

MemoryModule::~MemoryModule() {
}

MemoryModule &MemoryModule::operator=(MemoryModule const &rhs) {
	if (this != &rhs)
		;
	return *this;
}

void MemoryModule::displayTerminal(int *y) {
	mvprintw((*y)++, DISPLAY_TERMINAL_FIRSTCOL, ("Ram: " + _RAM_amount).c_str());
	mvprintw((*y)++, DISPLAY_TERMINAL_FIRSTCOL, _RAM_usage.c_str());
}

void	MemoryModule::displayGUI(GraphicalDisplay *graphDisp) {
	int offset = 0;

	// RAM ________________________

	sf::Text text = graphDisp->printText("Ram", TEXTH, TITLE_COLOR);
	graphDisp->getWindow()->draw(text);

	offset += TEXTH + MARGIN;
	text = graphDisp->printText(_RAM_amount, TEXTSH, VALUE_COLOR);
	text.setPosition(0, offset);
	graphDisp->getWindow()->draw(text);

	offset += TEXTH + MARGIN;
	text = graphDisp->printText(_RAM_usage, TEXTSH, VALUE_COLOR);
	text.setPosition(0, offset);
	graphDisp->getWindow()->draw(text);

	sf::Vector2u winSize = graphDisp->getWindow()->getSize();
	int height = winSize.y / graphDisp->getNbModules();

	int rH = 20;
	int rW = winSize.x / 2;

	sf::RectangleShape memoryBox(sf::Vector2f(rW, rH));
	memoryBox.setFillColor(sf::Color::Transparent);
	memoryBox.setOutlineThickness(1);
	memoryBox.setOutlineColor(sf::Color(250, 250, 250));
	memoryBox.setPosition(10, height - 15 - rH);
	graphDisp->getWindow()->draw(memoryBox);

	float ramAmount = std::atoi(_RAM_amount.c_str()) * 1024;
	int ramUsage = std::atoi(_RAM_usage.c_str());
	float percent = ramUsage / ramAmount;

	if (ramUsage > 0) {
		sf::VertexArray memoryLoad(sf::Quads, 4);
		memoryLoad[0].position = sf::Vector2f(10, 		height - 15 - rH);
		memoryLoad[1].position = sf::Vector2f(10 + (rW * percent),	height - 15 - rH);
		memoryLoad[2].position = sf::Vector2f(10 + (rW * percent),	height - 15);
		memoryLoad[3].position = sf::Vector2f(10,		height - 15);

		memoryLoad[0].color = sf::Color::Green;
		memoryLoad[1].color = sf::Color::Red;
		memoryLoad[2].color = sf::Color::Red;
		memoryLoad[3].color = sf::Color::Green;

		graphDisp->getWindow()->draw(memoryLoad);
	}
}

void	MemoryModule::updateInfo(void) {
	_RAM_amount = getCommandResult();
	_RAM_usage = getCommandResult("top | head | grep PhysMe | cut -d \" \" -f 2,3,6,7");
}
