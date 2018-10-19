#include "ft_gkrellm.hpp"

IMonitorDisplay * setDisplay(std::string const & mode) {
	if (mode.compare("shell") == 0)
		return new MonitorShell();
	else if (mode.compare("graphical") == 0)
		return new MonitorGraphical();
	std::cout << "./ft_gkrellm: error: " << mode
		<< ": invalide display mode" << std::endl;
	return NULL;
}

IMonitorModule * generateName() { return new Name(); }

IMonitorModule * generateOs() { return new OS(); }

IMonitorModule * generateTime() { return new Time(); }

IMonitorModule * generateCpu() { return new CPU(); }

IMonitorModule * generateRam() { return new RAM(); }

IMonitorModule * generateNetwork() { return new Network(); }

IMonitorModule * generateDisk() { return new Disk(); }

IMonitorModule * generateModule(std::string type) {
	typedef IMonitorModule * (*Foo)(void);
	Foo constructors[7] = {
		generateName,
		generateOs,
		generateTime,
		generateCpu,
		generateRam,
		generateNetwork,
		generateDisk
	};
	std::string modules[7][2] = {
		{ "hostname", "username" },
		{ "os", "system" },
		{ "date", "time" },
		{ "cpu", "processor" },
		{ "ram", "memory" },
		{ "network", "net" },
		{ "disk", "disks" }
	};

	for (int i(0); i < 7; i++) {
		for (int j(0); j < 2; j++) {
			if (type.compare(modules[i][j]) == 0)
				return constructors[i]();
		}
	}
	throw BadModuleException(type);
}

int setModules(IMonitorDisplay * monitorDisplay, char ** modules) {
	int i(0);

	try {
		while (modules[i] && i < 10)
			monitorDisplay->addModule(generateModule(modules[i++]));
	} catch (BadModuleException const & e) {
		std::cout << e.what() << std::endl;
		return (-1);
	}
	return (0);
}
