#ifndef NETWORK_CLASS_H
#define NETWORK_CLASS_H

#include "IMonitorModule.class.hpp"

class Network : public IMonitorModule {

public:
	Network();
	virtual ~Network();

	std::string getTitle() const;
	std::vector<Info> const getInfo();

private:
	std::string packetsIn_;
	std::string packetsOut_;

	void setInfo();

	Network(Network const &);
	Network & operator=(Network const &);

};

#endif
