#ifndef MONITOR_GRAPHICAL
#define MONITOR_GRAPHICAL

#include <iostream>
#include <set>
#include <vector>
#include <SFML/Graphics.hpp>
#include "IMonitorDisplay.class.hpp"

class MonitorGraphical : public IMonitorDisplay {

public:
	MonitorGraphical();
	virtual ~MonitorGraphical();

	void addModule(IMonitorModule *);
	void refresh();
	bool action();

private:
	sf::RenderWindow win_;
	int h_;
	int w_;
	sf::Font textFont_;
	std::string fontFile_;
	int textSize_;
	int titleSize_;
	int titlePadding_;
	int textPadding_;

	void update();

	std::vector<IMonitorModule *> modules_;

	MonitorGraphical(MonitorGraphical const &);
	MonitorGraphical & operator=(MonitorGraphical const &);

};

#endif
