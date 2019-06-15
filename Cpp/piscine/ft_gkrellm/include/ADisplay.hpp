#ifndef ADISPLAY_HPP
# define ADISPLAY_HPP

#include "IMonitorDisplay.hpp"

class ADisplay : public IMonitorDisplay{
	public:
		virtual std::list<AModule *> getModules();
		virtual void reorderModules();
		virtual void toggleModule(AModule *module);
		virtual void windowEventLoop() = 0;

	protected:
		std::list<AModule *> _modules;
		std::list<AModule *>::iterator	_selected;
		void	swapModule(bool up);
};

#endif
