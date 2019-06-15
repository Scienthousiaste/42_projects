
#ifndef IMONITOR_DISPLAY_HPP
# define IMONITOR_DISPLAY_HPP

# include <iostream>
# include <list>
# include "AModule.hpp"



class IMonitorDisplay {
	public:
		virtual std::list<AModule *> getModules() = 0;
		virtual void reorderModules() = 0;
		virtual void toggleModule(AModule *module) = 0;
		virtual void display() = 0;
};

#endif
