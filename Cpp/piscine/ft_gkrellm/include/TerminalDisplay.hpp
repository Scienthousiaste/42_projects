


#ifndef TERMINAL_DISPLAY_HPP
# define TERMINAL_DISPLAY_HPP

#include "ADisplay.hpp"
#include <ncurses.h>


class TerminalDisplay : public ADisplay {
	public:
		TerminalDisplay(std::list<AModule *> modules);
		virtual ~TerminalDisplay();
		void display();
		void displayModuleNames(int *y);
		virtual void windowEventLoop();
		std::list<AModule *>::iterator select_n(int n);

	private:
		WINDOW *					_win;

		TerminalDisplay();
		TerminalDisplay(TerminalDisplay const &src);
		TerminalDisplay &operator=(TerminalDisplay const &rhs);
};

#endif
