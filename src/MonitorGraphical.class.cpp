#include "MonitorGraphical.class.hpp"

MonitorGraphical::MonitorGraphical() {
	h_ = 0;
	w_ = 250;
	fontFile_ = "/System/Library/Fonts/Helvetica.dfont";
	if (!textFont_.loadFromFile(fontFile_))
		exit (EXIT_FAILURE);
	textSize_ = 12;
	titleSize_ = 14;
	titlePadding_ = 10;
	textPadding_ = 5;
}

MonitorGraphical::~MonitorGraphical() {
	win_.close();
	std::vector<IMonitorModule *>::iterator it(modules_.begin());
	std::vector<IMonitorModule *>::iterator ite(modules_.end());
	for(; it != ite; it++)
		delete *it;
}


void MonitorGraphical::addModule(IMonitorModule * newModule) {
	modules_.push_back(newModule);

	sf::Text text;
	sf::FloatRect box;
	std::vector<Info> info;

	text.setString(newModule->getTitle());
	text.setFont(textFont_);
	text.setCharacterSize(titleSize_);
	text.setStyle(sf::Text::Bold);
	box = text.getLocalBounds();
	h_ += box.height + 2 * titlePadding_;

	info = newModule->getInfo();
	int size(info.size());
	for (int i(0); i < size; i++) {
		text.setString(info[i].value);
		text.setFont(textFont_);
		text.setCharacterSize(textSize_);
		box = text.getLocalBounds();
		h_ += box.height + textPadding_;
	}
}

void MonitorGraphical::update() {
	std::string title;
	std::vector<Info> info;
	std::vector<IMonitorModule *>::iterator it(modules_.begin());
	std::vector<IMonitorModule *>::iterator ite(modules_.end());
	sf::Text text;
	sf::FloatRect box;
	int y(0);

	while (it != ite) {
		text.setString((*it)->getTitle());
		text.setFont(textFont_);
		text.setCharacterSize(titleSize_);
		text.setStyle(sf::Text::Bold);
		box = text.getLocalBounds();
		text.setOrigin(box.width / 2, box.height / 2);
		text.setPosition(w_ / 2, y + box.height / 2 + titlePadding_);
		win_.draw(text);
		y += box.height + 2 * titlePadding_;

		info = (*it)->getInfo();
		std::vector<Info>::iterator i(info.begin());
		std::vector<Info>::iterator ie(info.end());
		while (i != ie) {
			text.setString(i->text + ": " + i->value);
			text.setFont(textFont_);
			text.setCharacterSize(textSize_);
			box = text.getLocalBounds();
			text.setOrigin(0, box.height / 2);
			text.setPosition(10, y + box.height / 2);
			win_.draw(text);
			y += box.height + textPadding_;
			i++;
		}
		it++;
	}
}

void MonitorGraphical::refresh() {
	if (win_.isOpen() == false) {
		win_.create(sf::VideoMode(w_, h_ + textSize_ + titleSize_), "ft_gkrellm");
		win_.setPosition(sf::Vector2i(0, 0));
	}
	win_.clear(sf::Color(42, 42, 42));
	update();
	win_.display();
}

bool MonitorGraphical::action() {
	sf::Event event;

	while (win_.pollEvent(event)) {
		switch (event.type) {
			case sf::Event::Closed:
				return true;
				break;
			case sf::Event::KeyPressed:
				if (event.key.code == sf::Keyboard::Q
				 || event.key.code == sf::Keyboard::Escape)
					return true;
				break;
			default:
				break;
		}
	}
	return false;
}
