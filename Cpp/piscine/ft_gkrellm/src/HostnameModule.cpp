#include "HostnameModule.hpp"
#include "GraphicalDisplay.hpp"
#include "defines.hpp"
#include <sstream>
#include <iostream>

HostnameModule::HostnameModule() {
	_cmd = "hostname && echo $USER";
	_active = true;
	_name = "usr";
}

HostnameModule::HostnameModule(HostnameModule const &src) {
	*this = src;
}

HostnameModule::~HostnameModule() {
}

HostnameModule &HostnameModule::operator=(HostnameModule const &rhs) {
	if (this != &rhs)
		;
	return *this;
}

void HostnameModule::displayTerminal(int *y) {
	mvprintw((*y)++, DISPLAY_TERMINAL_FIRSTCOL, std::string("Hostname").c_str());
	mvprintw((*y)++, DISPLAY_TERMINAL_FIRSTCOL, _hostname.c_str());
	mvprintw((*y)++, DISPLAY_TERMINAL_FIRSTCOL, _username.c_str());
}

void HostnameModule::displayGUI(GraphicalDisplay *graphDisp) {
	int offset = 0;

	// Hostname: ________________________

	sf::Text text = graphDisp->printText("Hostname", TEXTH, TITLE_COLOR);
	graphDisp->getWindow()->draw(text);

	offset += TEXTH + MARGIN;
	text = graphDisp->printText(_hostname, TEXTSH, VALUE_COLOR);
	text.setPosition(0, offset);
	graphDisp->getWindow()->draw(text);

	// Username: ________________________

	offset += TEXTSH + MARGIN;
	text = graphDisp->printText("Username", TEXTH, TITLE_COLOR);
	text.setPosition(0, offset);
	graphDisp->getWindow()->draw(text);

	offset += TEXTH + MARGIN;
	text = graphDisp->printText(_username, TEXTSH, VALUE_COLOR);
	text.setPosition(0, offset);
	graphDisp->getWindow()->draw(text);
}

void	HostnameModule::updateInfo(void) {
	std::stringstream ss(getCommandResult());
	std::getline(ss, _hostname);
	std::getline(ss, _username);
}

std::string HostnameModule::getHostname() { return _hostname; }
std::string HostnameModule::getUsername() { return _username; }
