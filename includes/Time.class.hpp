#ifndef TIME_CLASS_H
#define TIME_CLASS_H

#include "IMonitorModule.class.hpp"

class Time : public IMonitorModule {

public:
	Time();
	virtual ~Time();

	std::string getTitle() const;
	std::vector<Info> const getInfo();

private:
	std::string date_;
	std::string time_;

	void setInfo();

	Time(Time const &);
	Time & operator=(Time const &);

};

#endif
