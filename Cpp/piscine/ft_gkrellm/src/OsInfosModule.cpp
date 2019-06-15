#include "OsInfosModule.hpp"
#include "GraphicalDisplay.hpp"
#include <sstream>

OsInfosModule::OsInfosModule() {
	_cmd = "system_profiler SPSoftwareDataType -detailLevel mini | grep ': ' | awk -F ': ' '{print $2}'";
	_active = true;
	_name = "osx";
}

OsInfosModule::OsInfosModule(OsInfosModule const &src) {
	*this = src;
}

OsInfosModule::~OsInfosModule() {
}

OsInfosModule &OsInfosModule::operator=(OsInfosModule const &rhs) {
	if (this != &rhs)
		;
	return *this;
}

void	OsInfosModule::displayTerminal(int *y) {
	mvprintw((*y)++, DISPLAY_TERMINAL_FIRSTCOL, std::string("OS infos").c_str());
	mvprintw((*y)++, DISPLAY_TERMINAL_FIRSTCOL, _systemVersion.c_str());
	mvprintw((*y)++, DISPLAY_TERMINAL_FIRSTCOL, _kernelVersion.c_str());
	mvprintw((*y)++, DISPLAY_TERMINAL_FIRSTCOL, _timeSinceBoot.c_str());
}

void	OsInfosModule::displayGUI(GraphicalDisplay *graphDisp) {
	int offset = 0;

	// SystemVersion: ________________________

	sf::Text text = graphDisp->printText("System version", TEXTH, TITLE_COLOR);
	graphDisp->getWindow()->draw(text);

	offset += TEXTH + MARGIN;
	text = graphDisp->printText(_systemVersion, TEXTSH, VALUE_COLOR);
	text.setPosition(0, offset);
	graphDisp->getWindow()->draw(text);

	// KernelVersion: ________________________

	offset += TEXTSH + MARGIN;
	text = graphDisp->printText("Kernel version", TEXTH, TITLE_COLOR);
	text.setPosition(0, offset);
	graphDisp->getWindow()->draw(text);

	offset += TEXTH + MARGIN;
	text = graphDisp->printText(_kernelVersion, TEXTSH, VALUE_COLOR);
	text.setPosition(0, offset);
	graphDisp->getWindow()->draw(text);

	// TimeSinceBoot: ________________________

	offset += TEXTSH + MARGIN;
	text = graphDisp->printText("Time since boot", TEXTH, TITLE_COLOR);
	text.setPosition(0, offset);
	graphDisp->getWindow()->draw(text);

	offset += TEXTH + MARGIN;
	text = graphDisp->printText(_timeSinceBoot, TEXTSH, VALUE_COLOR);
	text.setPosition(0, offset);
	graphDisp->getWindow()->draw(text);
}

void	OsInfosModule::updateInfo(void) {
	std::stringstream ss(getCommandResult());
	std::string tmp;
	std::getline(ss, _systemVersion);
	std::getline(ss, _kernelVersion);
	std::getline(ss, _timeSinceBoot);
}

std::string OsInfosModule::getSystemVersion() { return _systemVersion; }
std::string OsInfosModule::getKernelVersion() { return _kernelVersion; }
std::string OsInfosModule::getTimeSinceBoot() { return _timeSinceBoot; }
