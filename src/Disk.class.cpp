#include "Disk.class.hpp"

Disk::Disk() { }

Disk::~Disk() { }


std::string Disk::getTitle() const { return "Disk"; }

void Disk::setInfo() {
	FILE * fp;
	char buff[32];
	size_t size(sizeof(buff));

	fp = popen("top -l1 | grep Disks | cut -d' ' -f 2", "r");
	if (fp != NULL) {
		fgets(buff, size, fp);
		read_.assign(buff, strlen(buff) - 1);
	} else
		read_ = "";
	pclose(fp);

	fp = popen("top -l1 | grep Disks | cut -d' ' -f 4", "r");
	if (fp != NULL) {
		fgets(buff, size, fp);
		write_.assign(buff, strlen(buff) - 1);
	} else
		write_ = "";
	pclose(fp);
}

std::vector<Info> const Disk::getInfo() {
	std::vector<Info> info;
	Info i;

	setInfo();

	i.text = "Read";
	i.value = read_;
	info.push_back(i);
	i.text = "Write";
	i.value = write_;
	info.push_back(i);
	return info;
}
