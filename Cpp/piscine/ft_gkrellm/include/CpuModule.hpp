#ifndef CPUMODULE_HPP
# define CPUMODULE_HPP

# include "AModule.hpp"
# include "ft_gkrellm.hpp"
# include <vector>
# include <sstream>

class CpuModule : public AModule {
	public:
		CpuModule();
		~CpuModule();
		virtual void updateInfo(void);
		virtual void displayTerminal(int *y);
		virtual void displayGUI(GraphicalDisplay *graphDisp);

	private:
		CpuModule(CpuModule const &src);
		CpuModule &operator=(CpuModule const &rhs);
		std::string	_model;
		std::string	_n_core;
		std::string _usage;
		float		_user;
		float		_system;
		float		_idle;
};

#endif
