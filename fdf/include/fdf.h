/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 14:03:59 by tbehra            #+#    #+#             */
/*   Updated: 2018/06/25 16:34:35 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <fcntl.h>
# include <mlx.h>
# include <math.h>
# include "libft.h"
# include "ft_printf.h"
# include "display.h"

# define ERROR_NO_FILE 0
# define MALLOC_ERROR 1
# define GNL_ERROR 2
# define NAN_ERROR 3
# define EMPTY_ERROR 4
# define INCONSISTENT_SIZE 5
# define WRONG_NUMBER_ERROR 6

# define MAP_START_SIZE 1000
# define WIN_WIDTH 1800
# define WIN_HEIGHT 1200
# define WIN_TITLE "Funky Dot Funels"

# define SC_INC 10
# define SCZ_INC 2
# define ANGLE_INC 2

# define REFRESH 1
# define RECOMPUTE_MATRIX 2
# define DELTA 200

typedef struct	s_fdf
{
	int			fd;
	int			ret_gnl;
	int			row;
	int			col;
	int			**map;
	int			i_map;
	int			*map_1d;
	int			size_map_1d;
	void		*mlx;
	void		*win;
	void		*img_clear;
	int			alpha_deg;
	int			beta_deg;
	int			sx;
	int			sy;
	int			sz;
	int			scale_x;
	int			scale_y;
	int			polarity;
	int			print_green;
	double		alpha;
	double		beta;
	double		rotation_matrix[3][3];
	t_point		center_win;
	t_point		*start_point;
	t_point		*(*project)(struct s_fdf *fdf, t_vertex *v);
}				t_fdf;

void			parse_map(t_fdf *fdf);
void			error(int error);
void			realloc_map(t_fdf *fdf);
void			launch_mlx(t_fdf *fdf);
t_point			*make_point(int x, int y);
int				deal_key(int key, void *param);
int				deal_mouse(int mouse_button, int x, int y, void *param);
void			quit_program(t_fdf *fdf);
void			reorganize_map(t_fdf *fdf);
int				trace_line(t_fdf *fdf, t_point *start, t_point *end, int color);
int				vertical_line(t_fdf *fdf, t_point *start, int y_end, int color);
void			projection(t_fdf *fdf);
void			projection_link(t_fdf *fdf);
t_point			*isometric_projection(t_fdf *fdf, t_vertex *v);
void			build_rotation_matrix(t_fdf *fdf);
void			generate_images(t_fdf *fdf);
void			refresh_screen(t_fdf *fdf, int refresh);
void			dump_vars(t_fdf *fdf);
t_vertex		*make_vertex(int x, int y, int z);
void			init_display_params(t_fdf *fdf);

#endif
