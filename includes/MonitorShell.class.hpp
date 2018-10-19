#ifndef MONITOR_SHELL
#define MONITOR_SHELL

#include <curses.h>
#include <vector>
#include <set>
#include "IMonitorDisplay.class.hpp"

class MonitorShell : public IMonitorDisplay {

public:
	MonitorShell();
	virtual ~MonitorShell();

	void addModule(IMonitorModule *);
	void refresh();
	bool action();

private:
	int h_;
	int w_;
	int maxw_;
	int modulew_;

	void display();

	std::vector<IMonitorModule *> modules_;

	MonitorShell(MonitorShell const &);
	MonitorShell & operator=(MonitorShell const &);

};

#endif
