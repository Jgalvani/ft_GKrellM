#ifndef CPU_CLASS_H
#define CPU_CLASS_H

#include "IMonitorModule.class.hpp"

class CPU : public IMonitorModule {

public:
	CPU();
	virtual ~CPU();

	std::string getTitle() const;
	std::vector<Info> const getInfo();

private:
	std::string model_;
	float frequency_;
	int nbCores_;
	float loadavg_;

	void setInfo();

	CPU(CPU const &);
	CPU & operator=(CPU const &);

};

#endif
