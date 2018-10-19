#ifndef NAME_CLASS_H
#define NAME_CLASS_H

#include <unistd.h>
#include "IMonitorModule.class.hpp"

class Name : public IMonitorModule {

public:
	Name();
	virtual ~Name();

	std::string getTitle() const;
	std::vector<Info> const getInfo();

private:
	std::string hostname_;
	std::string username_;

	Name(Name const &);
	Name & operator=(Name const &);

};

#endif
