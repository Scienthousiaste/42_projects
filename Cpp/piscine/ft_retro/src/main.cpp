/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 09:07:01 by gsmith            #+#    #+#             */
/*   Updated: 2019/06/01 16:26:12 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include "Game.hpp"


void	init_colors(void) {
	start_color();
	init_color(COLOR_GRAY, 500, 500, 500);
	init_color(COLOR_RED_D, 700, 300, 300);
	init_color(COLOR_GREEN_D, 700, 300, 300);
	init_color(COLOR_BLUE_D, 700, 300, 300);
	init_color(COLOR_RED_B, 1000, 700, 700);
	init_color(COLOR_GREEN_B, 700, 1000, 700);
	init_color(COLOR_BLUE_B, 700, 700, 1000);
	init_pair(COLOR_PAIR_SCORE, COLOR_BLUE_B, COLOR_BLACK);
	init_pair(COLOR_PAIR_BCKGRND, COLOR_GRAY, COLOR_BLACK);
	init_pair(COLOR_PAIR_ASTERO, COLOR_RED_D, COLOR_BLACK);
	init_pair(COLOR_PAIR_ALSHIP, COLOR_RED, COLOR_BLACK);
	init_pair(COLOR_PAIR_SPSHIP, COLOR_GREEN, COLOR_BLACK);
	init_pair(COLOR_PAIR_PROJ_R, COLOR_RED_B, COLOR_BLACK);
	init_pair(COLOR_PAIR_PROJ_G, COLOR_GREEN_B, COLOR_BLACK);
	init_pair(COLOR_PAIR_PROJ_B, COLOR_BLUE_B, COLOR_BLACK);
	init_pair(COLOR_PAIR_EXPLOD, COLOR_YELLOW, COLOR_BLACK);
}


int		main(void) {
	WINDOW *	stdscr = initscr();
	int			h;
	int			w;
	int			retry = true;
	int			ch;

	noecho();
	cbreak();
	keypad(stdscr, TRUE);
	curs_set(0);
	init_colors();
	while (retry) {
		Game		*game = new Game();
		getmaxyx(stdscr, h, w);
		if (w >= GAME_WIDTH && h >= GAME_HEIGHT + 1) {
			nodelay(stdscr, TRUE);
			game->run(h, w);
			delete game;
			mvprintw(h / 2 - 2, w / 2 - 4, "GAME OVER");
			mvprintw(h / 2, w / 2 - 8, "Try again ? (y/n)");
			ch = 0;
			while (ch != 'y' && ch != 'n')
				if ((ch = getch()) != ERR) {
					if (ch == 'n')
						retry = false;
				}
		} else {
			mvprintw(h / 2 - 2, w / 2 - 27, \
					"This program need more screen space to run correctly.");
			mvprintw(h / 2 - 1, w / 2 - 24, \
					"Current size: (%3d x %3d), needed: (%3d x %3d)", \
					w, h, GAME_WIDTH, GAME_HEIGHT + 5);
			mvprintw(h / 2, w / 2 - 27, \
					"Try again after increasing the size of this terminal.");
			mvprintw(h / 2 + 1, w / 2 - 18, \
					"Press any key to stop this program.");
			refresh();
			getch();
		}
	}
	return (endwin());
}
