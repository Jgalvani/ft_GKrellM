#ifndef I_MONITOR_MODULE_H
#define I_MONITOR_MODULE_H

#include <vector>
#include <string>

struct Info {
	std::string text;
	std::string value;
};

class IMonitorModule {

public:
	virtual ~IMonitorModule() {}
	virtual std::string getTitle() const = 0;
	virtual std::vector<Info> const getInfo() = 0;

};

#endif
