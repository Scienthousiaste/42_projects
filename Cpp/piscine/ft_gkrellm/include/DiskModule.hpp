

#ifndef DISKMODULE_HPP
# define DISKMODULE_HPP

# include "AModule.hpp"
# include "ft_gkrellm.hpp"
# include <vector>
# include <sstream>

class DiskModule : public AModule {
	public:
		DiskModule();
		~DiskModule();
		virtual void updateInfo(void);
		virtual void displayTerminal(int *y);
		virtual void displayGUI(GraphicalDisplay *graphDisp);

	private:
		DiskModule(DiskModule const &src);
		DiskModule &operator=(DiskModule const &rhs);
		std::string _diskUsage;
};

#endif
