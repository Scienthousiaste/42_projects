
#ifndef MEMORYMODULE_HPP
# define MEMORYMODULE_HPP

# include "AModule.hpp"
# include "ft_gkrellm.hpp"
# include <vector>
# include <sstream>

class MemoryModule : public AModule {
	public:
		MemoryModule();
		~MemoryModule();
		virtual void updateInfo(void);
		virtual void displayTerminal(int *y);
		virtual void displayGUI(GraphicalDisplay *graphDisp);

	private:
		MemoryModule(MemoryModule const &src);
		MemoryModule &operator=(MemoryModule const &rhs);
		std::string _RAM_amount;
		std::string _RAM_usage;

};

#endif
