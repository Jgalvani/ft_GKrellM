#ifndef I_MONITOR_DISPLAY_H
#define I_MONITOR_DISPLAY_H

#include "IMonitorModule.class.hpp"

class IMonitorDisplay {

public:
	virtual ~IMonitorDisplay() {}
	virtual void addModule(IMonitorModule *) = 0;
	virtual void refresh() = 0;
	virtual bool action() = 0;

};

#endif
