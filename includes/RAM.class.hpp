#ifndef RAM_CLASS_H
#define RAM_CLASS_H

#include "IMonitorModule.class.hpp"

class RAM : public IMonitorModule {

public:
	RAM();
	virtual ~RAM();

	std::string getTitle() const;
	std::vector<Info> const getInfo();

private:
	long int memsize_;
	long int free_;
	int pagesize_;

	void setInfo();

	RAM(RAM const &);
	RAM & operator=(RAM const &);

};

#endif
