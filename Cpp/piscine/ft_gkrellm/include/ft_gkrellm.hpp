#ifndef FT_GKRELLM_HPP
# define FT_GKRELLM_HPP

#include <cstdlib>
#include <iostream>
#include <list>
#include <ctime>
#include <unistd.h>

#include "AModule.hpp"
#include "HostnameModule.hpp"
#include "OsInfosModule.hpp"
#include "TimeModule.hpp"
#include "CpuModule.hpp"
#include "MemoryModule.hpp"
#include "DiskModule.hpp"
#include "NetworkModule.hpp"
#include "TerminalDisplay.hpp"
#include "GraphicalDisplay.hpp"


template<typename Out>
void split(const std::string &s, char delim, Out result);
std::vector<std::string> split(const std::string &s, char delim);


#endif
