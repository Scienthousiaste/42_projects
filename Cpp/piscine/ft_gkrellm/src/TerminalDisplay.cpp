#include "TerminalDisplay.hpp"
#include "defines.hpp"
#include <vector>
#include <ctime>
#include <unistd.h>

static void initColors(void) {
	init_color(COLOR_GRAY, 500, 500, 500);
	init_pair(COLOR_PAIR_BORDER, COLOR_GRAY, COLOR_BLACK);
	init_pair(COLOR_PAIR_GREEN, COLOR_GREEN, COLOR_BLACK);
	init_pair(COLOR_PAIR_RED, COLOR_RED, COLOR_BLACK);
}

TerminalDisplay::TerminalDisplay(std::list<AModule *> modules) {
	this->_modules = modules;

	WINDOW * stdscr	= initscr();

	initscr();
	start_color();
	curs_set(0);
	keypad(stdscr, true);
	raw();
	noecho();
	nodelay(stdscr, true);
	cbreak();
	initColors();
}

TerminalDisplay::~TerminalDisplay() {
	endwin();
}

static void exitTerminal(void) {
	endwin();
	exit(0);
}

static void drawEmptyLine(int y) {
	attron(COLOR_PAIR(COLOR_PAIR_BORDER));
	mvaddch(y, FIRST_COLUMN, '*');
	mvaddch(y, NCURSE_COLUMN_WIDTH - 1, '*');
	attroff(COLOR_PAIR(COLOR_PAIR_BORDER));
}

static void drawFullLine(int y) {
	attron(COLOR_PAIR(COLOR_PAIR_BORDER));
	mvprintw(y, FIRST_COLUMN, std::string(NCURSE_COLUMN_WIDTH, '*').c_str()); 
	attroff(COLOR_PAIR(COLOR_PAIR_BORDER));
}

void TerminalDisplay::displayModuleNames(int *y) {
	int index = 0;
	(*y)++;
	for(std::list<AModule *>::iterator it = _modules.begin(); it != _modules.end(); it++) {
		mvprintw(*y, 5+ DISPLAY_TERMINAL_FIRSTCOL + index * 5, (*it)->getName().c_str());
		index++;
	}
	index = 0;
	(*y)++;
	for(std::list<AModule *>::iterator it = _modules.begin(); it != _modules.end(); it++) {
		mvprintw(*y, 6 + DISPLAY_TERMINAL_FIRSTCOL + index * 5, ((*it)->isActive()) ? "O" : "X" );
		index++;
	}
	index = 0;
	(*y)++;
	for(std::list<AModule *>::iterator it = _modules.begin(); it != _modules.end(); it++) {
		mvprintw(*y, 6 + DISPLAY_TERMINAL_FIRSTCOL + index * 5, std::to_string(index + 1).c_str());
		index++;
	}
}

void TerminalDisplay::display() {
	int y = 0;
	int y_before;
	clear();

 	for (std::list<AModule*>::iterator it = _modules.begin();
			it != _modules.end(); it++) {

		if ((*it)->isActive()) {
			drawFullLine(y++);
			y_before = y;
			(*it)->displayTerminal(&y);
			for (int i = 0; i < y - y_before; i++)
				drawEmptyLine(y_before+i);
		}
	}
	drawFullLine(y);

	displayModuleNames(&y);
	refresh();
}

std::list<AModule *>::iterator TerminalDisplay::select_n(int n) {
	int i = 0;
	std::list<AModule *>::iterator it = _modules.begin();
	while (i < n) {
		it++;
		i++;
	}
	return it;
}


void TerminalDisplay::windowEventLoop() {
	int ch;
	time_t start;

	this->_selected = _modules.begin();
	while (true) {
		start = time(NULL);
		display();
		if ((REFRESH_TIME_DISPLAY - (time(NULL) - start)) > 0)
			usleep(REFRESH_TIME_DISPLAY - (time(NULL) - start));

		if ((ch = getch()) != ERR) {
			if (ch == 27 || ch == 'q')
				exitTerminal();
			if (ch >= '1' && ch <= '9') {
				std::list<AModule *>::iterator it = _modules.begin();
				std::advance(it, ch - '1');
				if (it != _modules.end()) {
					toggleModule(*it);
					flushinp();
					display();
				}
			}

			if (ch == '!')
				_selected = select_n(0);
			else if (ch == '@')
				_selected = select_n(1);
			else if (ch == '#')
				_selected = select_n(2);
			else if (ch == '$')
				_selected = select_n(3);
			else if (ch == '%')
				_selected = select_n(4);
			else if (ch == '^')
				_selected = select_n(5);
			else if (ch == '&')
				_selected = select_n(6);

			if (ch == KEY_DOWN) {
				swapModule(false);
			}
			if (ch == KEY_UP) {
				swapModule(true);
			}
		}
	}
}
