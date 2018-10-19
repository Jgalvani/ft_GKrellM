#include "Name.class.hpp"

Name::Name() {
	char buff[32];

	if (gethostname(buff, sizeof(buff)) == 0)
		hostname_.assign(buff);
	else
		hostname_ = "";

	if (getlogin_r(buff, sizeof(buff)) == 0)
		username_.assign(buff);
	else
		username_ = "";
 }

Name::~Name() { }


std::string Name::getTitle() const { return "Identity"; }

std::vector<Info> const Name::getInfo() {
	std::vector<Info> info;
	Info i;

	i.text = "Hostname";
	i.value = hostname_;
	info.push_back(i);
	i.text = "Username";
	i.value = username_;
	info.push_back(i);
	return (info);
}
