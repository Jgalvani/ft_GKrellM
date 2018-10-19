#include "Time.class.hpp"

Time::Time() { }

Time::~Time() { }


std::string Time::getTitle() const { return "Date & Time"; }

#include <iostream>

void Time::setInfo() {
	char buff[32];
	time_t rawtime;
	struct tm * timeinfo;

	date_ = "";
	time_ = "";
	time(&rawtime);
	timeinfo = localtime(&rawtime);
	strftime(buff, sizeof(buff), "%a %F", timeinfo);
	date_.assign(buff);
	strftime(buff, sizeof(buff), "%r", timeinfo);
	time_.assign(buff);
}

std::vector<Info> const Time::getInfo() {
	std::vector<Info> info;
	Info i;

	setInfo();
	i.text = "Date";
	i.value = date_;
	info.push_back(i);
	i.text = "Time";
	i.value = time_;
	info.push_back(i);
	return (info);
}
