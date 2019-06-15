#include "DiskModule.hpp"
#include "GraphicalDisplay.hpp"
#include "defines.hpp"

DiskModule::DiskModule() {
	_cmd = "df -h | grep Users | awk -F ' ' '{print $2\" \"$3\" \"$4}'";
	_active = true;
	_name = "dsk";
}

DiskModule::DiskModule(DiskModule const &src) {
	*this = src;
}

DiskModule::~DiskModule() {
}

DiskModule &DiskModule::operator=(DiskModule const &rhs) {
	if (this != &rhs)
		;
	return *this;
}

void DiskModule::displayTerminal(int *y) {
	mvprintw((*y)++, DISPLAY_TERMINAL_FIRSTCOL, "Free disk space");
	mvprintw((*y)++, DISPLAY_TERMINAL_FIRSTCOL, "Size  Used  Avail");
	mvprintw((*y)++, DISPLAY_TERMINAL_FIRSTCOL, _diskUsage.c_str());
}

void	DiskModule::displayGUI(GraphicalDisplay *graphDisp) {
	int offset = 0;

	// Disk usage: ________________________

	sf::Text text = graphDisp->printText("Disk usage", TEXTH, TITLE_COLOR);
	graphDisp->getWindow()->draw(text);

	offset += TEXTH + MARGIN;
	text = graphDisp->printText(_diskUsage, TEXTSH, VALUE_COLOR);
	text.setPosition(0, offset);
	graphDisp->getWindow()->draw(text);
}

void	DiskModule::updateInfo(void) {
	_diskUsage = getCommandResult();
}
