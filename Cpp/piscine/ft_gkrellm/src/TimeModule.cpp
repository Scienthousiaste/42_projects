
#include "GraphicalDisplay.hpp"
#include "TimeModule.hpp"
#include <iostream>

TimeModule::TimeModule() {
	_cmd = "date \"+%d-%m-%Y%n%H:%M:%S\"";
	_active = true;
	_name = "hrd";
}

TimeModule::TimeModule(TimeModule const &src) {
	*this = src;
}

TimeModule::~TimeModule() {
}

TimeModule &TimeModule::operator=(TimeModule const &rhs) {
	if (this != &rhs)
		;
	return *this;
}

void TimeModule::displayTerminal(int *y) {
	mvprintw((*y)++, DISPLAY_TERMINAL_FIRSTCOL, _date.c_str());
	mvprintw((*y)++, DISPLAY_TERMINAL_FIRSTCOL, _hour.c_str());
}

void TimeModule::displayGUI(GraphicalDisplay *graphDisp) {
	int offset = 0;

	// Date ________________________

	sf::Text text = graphDisp->printText("Date", TEXTH, TITLE_COLOR);
	graphDisp->getWindow()->draw(text);

	offset += TEXTH + MARGIN;
	text = graphDisp->printText(_date, TEXTSH, VALUE_COLOR);
	text.setPosition(0, offset);
	graphDisp->getWindow()->draw(text);

	// Time ________________________

	offset += TEXTSH + MARGIN;
	text = graphDisp->printText("Time", TEXTH, TITLE_COLOR);
	text.setPosition(0, offset);
	graphDisp->getWindow()->draw(text);

	offset += TEXTH + MARGIN;
	text = graphDisp->printText(_hour, TEXTSH, VALUE_COLOR);
	text.setPosition(0, offset);
	graphDisp->getWindow()->draw(text);
}

void	TimeModule::updateInfo(void) {
	std::string raw = getCommandResult();
	_date = raw.substr(0, raw.find("\n"));
	_hour = raw.substr(raw.find("\n") + 1, raw.length());
}
