#include "GraphicalDisplay.hpp"
#include <SFML/Graphics.hpp>

GraphicalDisplay::GraphicalDisplay() {
}

GraphicalDisplay::GraphicalDisplay(std::list<AModule *> modules) : _nbModules(0) {
	_modules = modules;
	_selected = _modules.begin();

	_window = new sf::RenderWindow(
			sf::VideoMode((sf::VideoMode::getDesktopMode().width / 4), (sf::VideoMode::getDesktopMode().height))
			, "ft_gkrellm");
	_window->setFramerateLimit(60);
	_window->setPosition(sf::Vector2i(_window->getSize().x * 3, 0));

	if (!_font.loadFromFile("Roboto-Regular.ttf"))
		std::cout << "font \"Roboto-Regular.ttf\" not found" << std::endl;
}

void    GraphicalDisplay::windowEventLoop() {
	for (std::list<AModule*>::iterator it = _modules.begin(); it != _modules.end(); it++)
		++_nbModules;

	while (_window->isOpen()) {
		sf::Event event;
		while (_window->pollEvent(event)) {
			if (event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
				_window->close();

			if (event.type == sf::Event::Resized) {
				// update the view to the new size of the window
				sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
				_window->setView(sf::View(visibleArea));
			}

			if (event.type == sf::Event::KeyPressed) {
				if (event.key.code >= KEY_ONE && event.key.code <= KEY_NINE) {
					std::list<AModule *>::iterator it = _modules.begin();
					std::advance(it, event.key.code - KEY_ONE);
					if (it != _modules.end()) {
						if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
							this->_selected = it;
						else
							toggleModule(*it);
					}
				}
				else if (event.key.code == sf::Keyboard::Up)
					swapModule(true);
				else if (event.key.code == sf::Keyboard::Down)
					swapModule(false);
			}
		}
		_window->clear(sf::Color::Black);
		sf::Vector2u winSize = _window->getSize();

		// Draw all modules
		int borderH = 5;
		int i = 0;
		for (std::list<AModule*>::iterator it = _modules.begin(); it != _modules.end(); it++) {
			if ((*it)->isActive()) {
				// create module view
				sf::View view(sf::FloatRect(0.f, 0.f, winSize.x, winSize.y / _nbModules));
				view.setViewport(sf::FloatRect(0, (1.0f / _nbModules) * i, 1, 1.0f / _nbModules));
				_window->setView(view);
				sf::RectangleShape bgColor(sf::Vector2f(winSize.x, winSize.y));

				bgColor.setFillColor(sf::Color(41, 43, 55));

				_window->draw(bgColor);

				(*it)->displayGUI(this);

				// draw separation bar
				if (++it != _modules.end()) {
					sf::RectangleShape sepBar(sf::Vector2f(winSize.x, borderH));
					sepBar.setFillColor(sf::Color(0, 0, 0));
					// sepBar.setPosition(0, 320);
					sepBar.setPosition(0, winSize.y / _nbModules - borderH);
					_window->draw(sepBar);
				}
				it--;
				++i;
			}
		}

		_window->display();
	}
}

GraphicalDisplay::GraphicalDisplay(GraphicalDisplay const &src) {
	*this = src;
}

GraphicalDisplay::~GraphicalDisplay() {
	delete _window;
}

GraphicalDisplay &GraphicalDisplay::operator=(GraphicalDisplay const &rhs) {
	if (this != &rhs)
		;
	return *this;
}

void GraphicalDisplay::display() {
}

sf::RenderWindow	*GraphicalDisplay::getWindow() const { return _window; }
int					GraphicalDisplay::getNbModules() const { return _nbModules; }

sf::Text	GraphicalDisplay::printText(std::string textStr, int fontSize, sf::Color color) {
	sf::Text text;
	text.setFont(_font);
	text.setString(textStr);
	text.setCharacterSize(fontSize);
	text.setFillColor(color);
	return text;
}
