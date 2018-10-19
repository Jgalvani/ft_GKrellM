#include <sys/sysctl.h>
#include "OS.class.hpp"

OS::OS() {
	FILE * fp;
	char buff[32];
	size_t size(sizeof(buff));
	
	fp = popen("sw_vers -productName", "r");
	if (fp != NULL) {
		fgets(buff, size, fp);
		osName_.assign(buff, strlen(buff) - 1);
	} else
		osName_ = "";
	pclose(fp);

	fp = popen("sw_vers -productVersion", "r");
	if (fp != NULL) {
		fgets(buff, size, fp);
		osVersion_.assign(buff, strlen(buff) - 1);
	} else
		osVersion_ = "";
	pclose(fp);

	fp = popen("sw_vers -buildVersion", "r");
	if (fp != NULL) {
		fgets(buff, size, fp);
		buildVersion_.assign(buff, strlen(buff) - 1);
	} else
		buildVersion_ = "";
	pclose(fp);

	if (sysctlbyname("kern.ostype", &buff, &size, NULL, 0) == 0)
		osType_.assign(buff);
	else
		osType_ = "";
}

OS::~OS() { }


std::string OS::getTitle() const { return "System"; }

std::vector<Info> const OS::getInfo() {
	std::vector<Info> info;
	Info i;

	i.text = "OS";
	i.value = osName_;
	info.push_back(i);
	i.text = "Type";
	i.value = osType_;
	info.push_back(i);
	i.text = "Version";
	i.value = osVersion_;
	info.push_back(i);
	i.text = "Build version";
	i.value = buildVersion_;
	info.push_back(i);
	return (info);
}
