#ifndef GRAPHICALDISPLAY_HPP
# define GRAPHICALDISPLAY_HPP

#include "ADisplay.hpp"
#include <SFML/Graphics.hpp>

class GraphicalDisplay : public ADisplay {
	public:
		GraphicalDisplay(std::list<AModule *> modules);
		virtual	~GraphicalDisplay();
		void display();

		virtual void	windowEventLoop();
		sf::Text	printText(std::string textStr, int fontSize, sf::Color color);

		sf::RenderWindow	*getWindow() const;
		int					getNbModules() const;
	private:
		GraphicalDisplay();
		GraphicalDisplay(GraphicalDisplay const &src);
		GraphicalDisplay &operator=(GraphicalDisplay const &rhs);

		sf::RenderWindow	*_window;
		int					_nbModules;
		sf::Font			_font;
};

#endif
