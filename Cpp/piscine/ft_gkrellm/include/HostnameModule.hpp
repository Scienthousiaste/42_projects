#ifndef HOSTNAMEMODULE_HPP
# define HOSTNAMEMODULE_HPP

# include "AModule.hpp"

class HostnameModule : public AModule {
	public:
		HostnameModule();
		virtual ~HostnameModule();

		virtual void	updateInfo(void);

		std::string getHostname();
		std::string getUsername();
		virtual void displayGUI(GraphicalDisplay *graphDisp);
		void displayTerminal(int *y);
	private:
		HostnameModule(HostnameModule const &src);
		HostnameModule &operator=(HostnameModule const &rhs);

		std::string _hostname;
		std::string _username;
};

#endif
