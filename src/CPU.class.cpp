#include <sstream>
#include <iomanip>
#include <sys/sysctl.h>
#include "CPU.class.hpp"

CPU::CPU() {
	char buff[64];
	size_t size;
	int cores;
	long int freq;

	size = sizeof(buff);
	if (sysctlbyname("machdep.cpu.brand_string", &buff, &size, NULL, 0) == 0)
		model_.assign(buff, 27);
	else
		model_ = "";

	size = sizeof(cores);
	if (sysctlbyname("hw.ncpu", &cores, &size, NULL, 0) == 0)
		nbCores_ = cores;
	else
		nbCores_ = 0;

	size = sizeof(freq);
	if (sysctlbyname("hw.cpufrequency", &freq, &size, NULL, 0) == 0)
		frequency_ = static_cast<float>(freq) / 1000000000;
	else
		frequency_ = 0;
}

CPU::~CPU() { }


std::string CPU::getTitle() const { return "CPU"; }

void CPU::setInfo() {
	struct loadavg data;
	size_t size = sizeof(data);
	if (sysctlbyname("vm.loadavg", &data, &size, NULL, 0) == 0)
		loadavg_ = static_cast<float>(data.ldavg[0]) / data.fscale;
	else
		loadavg_ = 0;
}

std::vector<Info> const CPU::getInfo() {
	std::vector<Info> info;
	Info i;
	std::stringstream ss;

	i.text = "Model";
	i.value = model_;
	info.push_back(i);

	i.text = "Frequency";
	ss << std::fixed << std::setprecision(2) << frequency_ << "GHz";
	i.value = ss.str();
	ss.str("");
	info.push_back(i);

	i.text = "Number of cores";
	ss << nbCores_;
	i.value = ss.str();
	ss.str("");
	info.push_back(i);

	setInfo();
	i.text = "Activity";
	ss << std::fixed << std::setprecision(2) <<  loadavg_ * 100 / 4 << " %";
	i.value = ss.str();
	ss.str("");
	info.push_back(i);
	return (info);
}
