/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 19:24:59 by tbehra            #+#    #+#             */
/*   Updated: 2018/05/28 12:45:39 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <unistd.h>
# include <inttypes.h>
# include <limits.h>
# include <fcntl.h>
# include "ft_printf.h"

# define DISPLAY 0
# define TWO_BYTES 0x10
# define FOUR_BYTES 0x20
# define SIX_BYTES 0x30
# define MASQ_SHORT 0xFFFF

# define NEW_PLAYER_TERRITORY 3
# define NEW_ENNEMY_TERRITORY -3
# define LOST_TERRITORY 2
# define PLAYER_TERRITORY 1
# define ENNEMY_TERRITORY -1
# define RESET_COUNT -1
# define CHECK_CONTACT 1
# define ERROR_MALLOC 1
# define ERROR_BAD_INPUT 2

typedef struct	s_coord
{
	int			x_player;
	int			y_player;
	int			x_ennemy;
	int			y_ennemy;
}				t_coord;

typedef struct	s_piece
{
	int			ymax;
	int			xmax;
	int			x;
	int			y;
	char		**tab;
}				t_piece;

typedef struct	s_bestpos
{
	int			score;
	int			x;
	int			y;
}				t_bestpos;

typedef struct	s_filler
{
	char		player;
	char		ennemy;
	int			xmax;
	int			ymax;
	int			error;
	t_bestpos	bestpos;
	t_piece		piece;
	int16_t		(*tactic[2])(struct s_filler*);
	char		**tab;
	int8_t		**frontier;
	int			territory;
	int8_t		display;
	int			fd;
}				t_filler;

typedef struct	s_pos
{
	int			x;
	int			y;
	int			distance;
}				t_pos;

int				error(t_filler *f, int err_type);
int				init_tab(t_filler *f);
int				build_piece(t_filler *f);
int				two_players_present(t_filler *f);
int				parse_tab(t_filler *f);
int				parse_first_time(t_filler *f);
int8_t			is_player(t_filler *f, int x, int y, int player_sign);
int8_t			check_pos(t_filler *f, t_pos p, int player_sign);
int8_t			closest_player(t_filler *f, int x, int y, int player_sign);
void			move_next_frontier(t_filler *f, int x, int y, int player_sign);
void			fill_frontier(t_filler *f, int x, int y, int player_sign);
void			draw_frontier(t_filler *f, int x, int y);
void			update_frontier(t_filler *f, int player_sign);
void			find_coord(t_filler *f, int64_t *coord);
int8_t			belongs_to_us(int x, int y, int64_t coord);
void			set_frontier(t_filler *f);
int16_t			check_contact(t_filler *f);
int16_t			best_placement(t_filler *f, uint8_t strategy);
int16_t			fill_frontier_test(t_filler *f, int x, int y);
int16_t			update_frontier_test(t_filler *f);
void			parse_first_time_display(t_filler *f);
void			parse_tab_display(t_filler *f);
void			display_frontier(t_filler *f);
#endif
