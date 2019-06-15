#include "CpuModule.hpp"
#include "defines.hpp"
#include <iomanip>
#include <sstream>

CpuModule::CpuModule() {
	_cmd = "top | head | grep CPU | sed -e 's/[^0-9.]/ /g' -e 's/^ *//g' -e 's/ *$//g' | tr -s ' '";
	_active = true;
	_name = "cpu";
}

CpuModule::CpuModule(CpuModule const &src) {
	*this = src;
}

CpuModule::~CpuModule() {
}

CpuModule &CpuModule::operator=(CpuModule const &rhs) {
	if (this != &rhs)
		;
	return *this;
}

void CpuModule::displayTerminal(int *y) {

	mvprintw((*y)++, DISPLAY_TERMINAL_FIRSTCOL, "CPU");
	mvprintw((*y)++, DISPLAY_TERMINAL_FIRSTCOL, _model.c_str());
	mvprintw((*y)++, DISPLAY_TERMINAL_FIRSTCOL,
			(std::string("Nb cores : ") + (_n_core)).c_str());
	mvprintw((*y)++, DISPLAY_TERMINAL_FIRSTCOL, "CPU usage");
	mvprintw((*y)++, DISPLAY_TERMINAL_FIRSTCOL, _usage.c_str());

	int prop_user = (_user * NCURSE_COLUMN_WIDTH) / 100;
	int prop_sys = (_system * NCURSE_COLUMN_WIDTH) / 100;
	int color = ((_user + _system) > 75)? COLOR_PAIR_RED : COLOR_PAIR_GREEN;
	attron(COLOR_PAIR(color));
	mvprintw((*y), DISPLAY_TERMINAL_FIRSTCOL, std::string(prop_user, '+').c_str());
	mvprintw((*y)++, DISPLAY_TERMINAL_FIRSTCOL + prop_user, std::string(prop_sys, '=').c_str());
	attroff(COLOR_PAIR(color));
}

static void drawGraph(GraphicalDisplay *graphDisp, int proportion) {
	static std::vector<int> graphData(100, 0);
	static int idx = 0;
	static int update = 0;
	int offset = 300;
	int size_bar;

	update++;
	if (update % 30 == 0) {
		graphData[idx] = proportion;
		idx = (idx + 1) % 100;
	}

	sf::RectangleShape rectangle;
	for (std::vector<int>::iterator it = graphData.begin(); it != graphData.end(); it++) {
		size_bar = *it * 3;
		rectangle.setSize(sf::Vector2f(2, size_bar));
		rectangle.setFillColor(sf::Color((size_bar * 2) > 255 ? 255 : size_bar * 2,
					(size_bar * 2 > 255) ? 0: 255 - (size_bar * 2),
					0));

		rectangle.setPosition(100 + offset, HEIGHT_GRAPH - size_bar);
		offset += 2;
		graphDisp->getWindow()->draw(rectangle);
	}
}

void CpuModule::displayGUI(GraphicalDisplay *graphDisp) {
	int offset = 0;

	// CPU model ________________________

	sf::Text text = graphDisp->printText("CPU model: ", TEXTH, TITLE_COLOR);
	graphDisp->getWindow()->draw(text);

	offset += TEXTH + MARGIN;
	text = graphDisp->printText(_model, TEXTSH, VALUE_COLOR);
	text.setPosition(0, offset);
	graphDisp->getWindow()->draw(text);

	// Nb cores ________________________

	offset += TEXTH + MARGIN;

	text = graphDisp->printText(_n_core + " cores", TEXTSH, VALUE_COLOR);
	text.setPosition(0, offset);
	graphDisp->getWindow()->draw(text);

	// CPU usage: ________________________

	offset += TEXTH + MARGIN;
	text = graphDisp->printText("Usage", TEXTH, TITLE_COLOR);
	text.setPosition(0, offset);
	graphDisp->getWindow()->draw(text);

	offset += TEXTH + MARGIN;
	std::stringstream stream;
	stream << std::fixed << std::setprecision(2) << _user << "% (user) " << _system
	   << "% (system) " << _idle << "% (idle)";
	text = graphDisp->printText(stream.str(), TEXTSH, VALUE_COLOR);
	text.setPosition(0, offset);
	graphDisp->getWindow()->draw(text);

	int prop_user = (_user * NCURSE_COLUMN_WIDTH) / 100;
	int prop_sys = (_system * NCURSE_COLUMN_WIDTH) / 100;
	drawGraph(graphDisp, prop_user + prop_sys);
}

void	CpuModule::updateInfo(void) {
	_usage = getCommandResult();


	std::vector<std::string> vec = split(_usage, ' ');

	_user = std::stof(vec[0]);
	_system = std::stof(vec[1]);
	_idle = std::stof(vec[2]);

	std::stringstream stream;
	stream << std::fixed << std::setprecision(2) << _user << "%% (user) " << _system
	   << "%% (system) " << _idle << "%% (idle)";
	_usage = stream.str();
	_n_core = getCommandResult("sysctl hw.physicalcpu | cut -d \" \" -f 2");
	_n_core.erase(std::remove(_n_core.begin(), _n_core.end(), '\n'), _n_core.end());

	_model = getCommandResult("sysctl -n machdep.cpu.brand_string");
}

