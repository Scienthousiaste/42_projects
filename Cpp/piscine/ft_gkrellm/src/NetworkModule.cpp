#include "NetworkModule.hpp"
#include "GraphicalDisplay.hpp"
#include "defines.hpp"

NetworkModule::NetworkModule() {
	_cmd = "top | head | grep Network | cut -d : -f 3 | tr . \" \"";
	_active = true;
	_name = "net";
}

NetworkModule::NetworkModule(NetworkModule const &src) {
	*this = src;
}

NetworkModule::~NetworkModule() {
}

NetworkModule &NetworkModule::operator=(NetworkModule const &rhs) {
	if (this != &rhs)
		;
	return *this;
}

void NetworkModule::displayTerminal(int *y) {
	mvprintw((*y)++, DISPLAY_TERMINAL_FIRSTCOL, "Network");
	mvprintw((*y)++, DISPLAY_TERMINAL_FIRSTCOL - 1, _packets.c_str());
}

void	NetworkModule::displayGUI(GraphicalDisplay *graphDisp) {
	int offset = 0;

	// Network: ________________________

	sf::Text text = graphDisp->printText("Network", TEXTH, TITLE_COLOR);
	graphDisp->getWindow()->draw(text);

	offset += TEXTH + MARGIN;
	text = graphDisp->printText(_packets, TEXTSH, VALUE_COLOR);
	text.setPosition(0, offset);
	graphDisp->getWindow()->draw(text);
}

void	NetworkModule::updateInfo(void) {
	_packets = getCommandResult();
}
