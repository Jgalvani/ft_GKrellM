#ifndef DISK_CLASS_H
#define DISK_CLASS_H

#include "IMonitorModule.class.hpp"

class Disk : public IMonitorModule {

public:
	Disk();
	virtual ~Disk();

	std::string getTitle() const;
	std::vector<Info> const getInfo();

private:
	std::string read_;
	std::string write_;

	void setInfo();

	Disk(Disk const &);
	Disk & operator=(Disk const &);

};

#endif
