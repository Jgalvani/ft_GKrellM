#ifndef FT_GKRELLM_H
#define FT_GKRELLM_H

#include <algorithm>
#include <exception>
#include <iostream>
#include <vector>

#include "IMonitorDisplay.class.hpp"
#include "MonitorShell.class.hpp"
#include "MonitorGraphical.class.hpp"

#include "IMonitorModule.class.hpp"
#include "CPU.class.hpp"
#include "Disk.class.hpp"
#include "Name.class.hpp"
#include "Network.class.hpp"
#include "OS.class.hpp"
#include "RAM.class.hpp"
#include "Time.class.hpp"

#include "ft_gkrellmExceptions.hpp"


IMonitorDisplay * setDisplay(std::string const & dipslayMode);
int setModules(IMonitorDisplay * monitorDisplay, char ** modules);

#endif
