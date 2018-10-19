#include "MonitorShell.class.hpp"

MonitorShell::MonitorShell() : modules_() {
	initscr();
	cbreak();
	noecho();
	curs_set(0);
	keypad(stdscr, true);
	getmaxyx(stdscr, h_, w_);
	nodelay(stdscr, true);

	maxw_ = 42;
}

MonitorShell::~MonitorShell() {
	endwin();
	std::vector<IMonitorModule *>::iterator it(modules_.begin());
	std::vector<IMonitorModule *>::iterator ite(modules_.end());
	for(; it != ite; it++)
		delete *it;
}


void MonitorShell::addModule(IMonitorModule * newModule) {
	modules_.push_back(newModule);
}

void MonitorShell::display() {
	std::string title;
	std::vector<Info> info;
	std::vector<IMonitorModule *>::iterator it(modules_.begin());
	std::vector<IMonitorModule *>::iterator ite(modules_.end());

	while (it != ite) {
		title = "[ " + (*it)->getTitle() + " ]";
		mvaddch(getcury(stdscr), 0, ACS_ULCORNER);
		mvhline(getcury(stdscr), 1, ACS_HLINE, modulew_ - 1);
		move(getcury(stdscr), (modulew_ - title.size()) / 2);
		addstr(title.c_str());
		move(getcury(stdscr) + 1, 0);
		info = (*it)->getInfo();
		std::vector<Info>::iterator i(info.begin());
		std::vector<Info>::iterator ie(info.end());
		while (i != ie) {
			addstr(("  " + i->text + ": " + i->value + '\n').c_str());
			i++;
		}
		it++;
	}
}

void MonitorShell::refresh() {
	getmaxyx(stdscr, h_, w_);
	modulew_ = (w_ < maxw_ ? w_ : maxw_);
	erase();
	move(0, 0);
	display();
}

bool MonitorShell::action() {
	return (getch() == 'q' ? true : false);
}
