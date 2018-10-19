#ifndef OS_CLASS_H
#define OS_CLASS_H

#include "IMonitorModule.class.hpp"

class OS : public IMonitorModule {

public:
	OS();
	virtual ~OS();

	std::string getTitle() const;
	std::vector<Info> const getInfo();

private:
	std::string osName_;
	std::string osType_;
	std::string osVersion_;
	std::string buildVersion_;

	OS(OS const &);
	OS & operator=(OS const &);

};

#endif
