
#ifndef TIMEMODULE_HPP
# define TIMEMODULE_HPP

# include "AModule.hpp"

class TimeModule : public AModule {
	public:
		TimeModule();
		~TimeModule();
		virtual void updateInfo(void);
		virtual void displayTerminal(int *y);
		virtual void displayGUI(GraphicalDisplay *graphDisp);

	private:
		TimeModule(TimeModule const &src);
		TimeModule &operator=(TimeModule const &rhs);
		std::string _date;
		std::string _hour;
};

#endif
