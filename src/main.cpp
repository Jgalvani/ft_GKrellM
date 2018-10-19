#include "ft_gkrellm.hpp"

void usage_exit() {
	std::cout << "usage: ./ft_gkrellm display_mode module ..." << std::endl;
	std::cout << "       display_mode: [shell] | [graphical]" << std::endl;
	std::cout << "       module: "
		<< "[hostname|username] | "
		<< "[os] | "
		<< "[date|time] | "
		<< "[cpu] | "
		<< "[ram] | "
		<< "[network] | "
		<< "[disk[s]]"
		<< std::endl;
	exit (EXIT_FAILURE);
}

int main(int ac, char *av[]) {
	IMonitorDisplay * monitorDisplay;
	time_t sec(0);
	bool quit;

	if (ac < 3)
		usage_exit();
	monitorDisplay = setDisplay(av[1]);
	if (monitorDisplay == NULL)
		usage_exit();
	if (setModules(monitorDisplay, av + 2) < 0) {
		delete monitorDisplay;
		usage_exit();
	}
	do {
		quit = monitorDisplay->action();
		time_t t(time(NULL));
		if (t > sec) {
			monitorDisplay->refresh();
			sec = t;
		}
	} while (quit == false);

	delete monitorDisplay;
	return EXIT_SUCCESS;
}
