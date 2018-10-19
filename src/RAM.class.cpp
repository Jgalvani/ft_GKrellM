#include <sstream>
#include <sys/sysctl.h>
#include <mach/vm_statistics.h>
// #include <mach/mach_types.h>
// #include <mach/mach_init.h>
#include <mach/mach_host.h>
#include "RAM.class.hpp"

RAM::RAM() {
	long int memsize;
	int pagesize;
	size_t size;

	size = sizeof(memsize);
	if (sysctlbyname("hw.memsize", &memsize, &size, NULL, 0) == 0)
		memsize_ = memsize;
	else
		memsize_ = 0;

	size = sizeof(pagesize);
	size = sizeof(memsize);
	if (sysctlbyname("vm.pagesize", &pagesize, &size, NULL, 0) == 0)
		pagesize_ = pagesize;
	else
		pagesize_ = 0;
}
	

RAM::~RAM() { }


std::string RAM::getTitle() const { return "Memory"; }

void RAM::setInfo() {
	mach_msg_type_number_t count = HOST_VM_INFO_COUNT;
	vm_statistics_data_t vmstat;
	if(host_statistics(mach_host_self(), HOST_VM_INFO, (host_info_t)&vmstat, &count) == KERN_SUCCESS)
		free_ = static_cast<int64_t>(vmstat.free_count) * pagesize_;
	else
		free_ = 0;
}

std::vector<Info> const RAM::getInfo() {
	std::vector<Info> info;
	Info i;
	std::stringstream ss;

	i.text = "Total";
	ss << static_cast<float>(memsize_) / 1000000 << "M";
	i.value = ss.str();
	ss.str("");
	info.push_back(i);

	setInfo();

	i.text = "Free";
	ss << static_cast<float>(free_) / 1000000 << "M";
	i.value = ss.str();
	ss.str("");
	info.push_back(i);

	i.text = "Used";
	ss << static_cast<float>(memsize_ - free_) / 1000000 << "M";
	i.value = ss.str();
	ss.str("");
	info.push_back(i);
	return info;
}
