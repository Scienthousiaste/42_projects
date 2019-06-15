#ifndef OSINFOSMODULE_HPP
# define OSINFOSMODULE_HPP

# include "AModule.hpp"

class OsInfosModule : public AModule {
	public:
		OsInfosModule();
		virtual ~OsInfosModule();

		virtual void	updateInfo(void);

		std::string getSystemVersion();
		std::string getKernelVersion();
		std::string getTimeSinceBoot();
		virtual void displayTerminal(int *y);
		virtual void displayGUI(GraphicalDisplay *graphDisp);
	private:
		OsInfosModule(OsInfosModule const &src);
		OsInfosModule &operator=(OsInfosModule const &rhs);

		std::string _systemVersion;
		std::string _kernelVersion;
		std::string _timeSinceBoot;
};

#endif
