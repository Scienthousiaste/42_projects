

#ifndef NETWORKMODULE_HPP
# define NETWORKMODULE_HPP

# include "AModule.hpp"
# include "ft_gkrellm.hpp"
# include <vector>
# include <sstream>

class NetworkModule : public AModule {
	public:
		NetworkModule();
		~NetworkModule();
		virtual void updateInfo(void);
		virtual void displayTerminal(int *y);
		virtual void displayGUI(GraphicalDisplay *graphDisp);

	private:
		NetworkModule(NetworkModule const &src);
		NetworkModule &operator=(NetworkModule const &rhs);
		std::string _packets;
};

#endif
