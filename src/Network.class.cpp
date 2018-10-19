#include "Network.class.hpp"

Network::Network() { }

Network::~Network() { }


std::string Network::getTitle() const { return "Network"; }

void Network::setInfo() {
	FILE * fp;
	char buff[32];
	size_t size(sizeof(buff));

	fp = popen("top -l1 | grep Network | cut -d' ' -f 3", "r");
	if (fp != NULL) {
		fgets(buff, size, fp);
		packetsIn_.assign(buff, strlen(buff) - 1);
	} else
		packetsIn_ = "";
	pclose(fp);

	fp = popen("top -l1 | grep Network | cut -d' ' -f 5", "r");
	if (fp != NULL) {
		fgets(buff, size, fp);
		packetsOut_.assign(buff, strlen(buff) - 1);
	} else
		packetsOut_ = "";
	pclose(fp);
}

std::vector<Info> const Network::getInfo() {
	std::vector<Info> info;
	Info i;

	setInfo();

	i.text = "Packets in";
	i.value = packetsIn_;
	info.push_back(i);
	i.text = "Packets out";
	i.value = packetsOut_;
	info.push_back(i);
	return info;
}
