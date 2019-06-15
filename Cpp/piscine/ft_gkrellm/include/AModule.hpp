#ifndef AMODULE_HPP
# define AMODULE_HPP

# include "IMonitorModule.hpp"
# include <ncurses.h>
# include <SFML/Graphics.hpp>

class GraphicalDisplay;

class AModule : public IMonitorModule {
	public:
		virtual ~AModule() {}
		std::string getCommandResult();
		std::string getCommandResult(std::string cmd);
		bool isActive();
		void setActive(bool res);
		virtual void displayTerminal(int *y) = 0;
		virtual void displayGUI(GraphicalDisplay *graphDisp) = 0;
		std::string getName();
	protected:
		std::string _name;
		std::string _cmd;
		bool _active;
};

#endif
