/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 13:07:04 by tbehra            #+#    #+#             */
/*   Updated: 2018/05/27 19:09:42 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_H
# define DISPLAY_H

# include <mlx.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include "libft.h"
# include "ft_printf.h"

# define ESC_KEY 53
# define LEFT_ARROW_KEY 123
# define RIGHT_ARROW_KEY 124
# define DOWN_ARROW_KEY 125
# define UP_ARROW_KEY 126

# define BLUE 0xFF
# define GREEN 0xFF00
# define RED 0xFF0000
# define DARK_GRAY 0x111111
# define WHITE 0xFFFFFF
# define BLACK 0x0
# define PLAYER_COLOR 0x40A3FB
# define CHALLENGER_COLOR 0xF09042
# define FRONTIER_COLOR 0x555555
# define PLAYER_TERRITORY_COLOR BLUE
# define CHALLENGER_TERRITORY_COLOR RED
# define TEXT_COLOR WHITE

# define PARSING_ERROR 0
# define MALLOC_ERROR 1

# define WIN_HEIGHT 1200
# define WIN_TITLE "Filler display"

# define SMALL_SQ_SIZE 9
# define MEDIUM_SQ_SIZE 20
# define BIG_SQ_SIZE 45

# define WIDTH_MASK 80
# define HEIGHT_MASK 20

# define Y_PLAYER_NAME 20
# define X_PLAYER_NAME 40

# define X_SCORE_PLAYER X_PLAYER_NAME + 105
# define Y_SCORE_PLAYER Y_PLAYER_NAME + 20
# define Y_TERRITORY_PLAYER Y_PLAYER_NAME + 40

# define X_FIRST_SQUARE 100
# define Y_FIRST_SQUARE 100
# define X_TAB_MAX 1000
# define Y_TAB_MAX 1000
# define WIDTH_DOMINANCE 400
# define HEIGHT_DOMINANCE 50
# define Y_DOMINANCE 20

typedef struct	s_display_mlx
{
	void		*mlx;
	void		*win;
	void		*image_player;
	void		*image_t_player;
	void		*image_challenger;
	void		*image_t_challenger;
	void		*image_frontier;
	int			sq_size;
	int			player;
	int			xmax;
	int			ymax;
	int			turn_nb;
	char		**tab;
	char		**frontier;
	char		**prev_tab;
	char		**prev_frontier;
	long int	begin_turn_one;
	long int	bytes_to_read_turn;
	int			win_width;
	int			win_height;
	int			turn_increment_nb;
	int			score_player;
	int			score_challenger;
	int			territory_player;
	int			territory_challenger;
	int			col_dominance[5];
	double		nb_sq;
	FILE		*file;
}				t_display_mlx;

typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;

typedef struct	s_rect
{
	int			width;
	int			height;
	int			color;
	t_point		coord;
}				t_rect;

int				error(int err_type);
int				parse_map_params(t_display_mlx *d);
char			**first_parse_tab(t_display_mlx *d);
int				parse_tab(t_display_mlx *d, char *buf);
int				first_parse_tab_frontier(t_display_mlx *d);
int				parse_tab_frontier(t_display_mlx *d);
void			quit_program(t_display_mlx *d);
int				usage(void);
void			print_rectangle(t_rect *rect, t_display_mlx *d);
void			print_square(int size, int color, t_point *p, t_display_mlx *d);
void			mask_turn_nb(t_display_mlx *d);
int				change_in_square(t_display_mlx *d, int row, int col);
int				count_tab(char **tab, char count_char, t_display_mlx *d);
t_rect			*create_mask(int w, int h, int x, int y);
void			mask_scores_nb(t_display_mlx *d);
void			compute_and_display_scores(t_display_mlx *d);
void			update_prev_tabs(t_display_mlx *d);
void			show_turn_increment(t_display_mlx *d);
void			display_state_turn(t_display_mlx *d);
void			previous_turn(t_display_mlx *d);
void			next_turn(t_display_mlx *d);
void			quit_program(t_display_mlx *d);
void			decrease_speed(t_display_mlx *d);
void			increase_speed(t_display_mlx *d);
int				deal_key(int key, void *param);
void			compute_sq_size(t_display_mlx *d);
void			open_window(t_display_mlx *d);
void			display_top_panel(t_display_mlx *d);
void			init_display(t_display_mlx *d);
void			*select_image(t_display_mlx *d, int row, int col);
void			generate_images(t_display_mlx *d);

#endif
