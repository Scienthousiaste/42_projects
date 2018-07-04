/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 17:31:19 by tbehra            #+#    #+#             */
/*   Updated: 2018/07/01 17:34:22 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include "mlx.h"
# include <stdlib.h>
# include <pthread.h>
# include "libft.h"
# include "display.h"


//
#include <stdio.h>
//
//
# define MALLOC_ERROR 1
# define INVALID_OPTION 2
# define INVALID_WINDOW_SIZE 3

# define RECOMPUTE_COORD 2
# define REINIT_MAP 4

# define DEFAULT_JULIA_RE 0.285
# define DEFAULT_JULIA_IM 0.013
# define DEFAULT_WIN_WIDTH_J 600
# define DEFAULT_WIN_HEIGHT_J 600
# define DEFAULT_WIN_WIDTH_M 1000
# define DEFAULT_WIN_HEIGHT_M 600

# define N_ITER_INIT 20
# define N_COLOR 18
# define MIN_WIN_WIDTH 40
# define MIN_WIN_HEIGHT 40
# define MAX_WIN_WIDTH 3000
# define MAX_WIN_HEIGHT 1800
# define NB_THREAD 4

# define WIN_TITLE "Fract'Ol"

typedef struct	s_complex
{
	double		re;
	double		im;
}				t_complex;

typedef struct	s_pixel
{
	int			n_iter_div;
	int			n_iter_value;
	int			color;
	t_complex	z;
	t_complex	z_value;
}				t_pixel;

typedef struct	s_display
{
	void		*mlx;
	void		*win;

	void		*img;
	char		*img_ptr;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
	int			win_width;
	int			win_height;

	void		*(*display_fractal)(void *param);
	void		(*init_fractal)(struct s_display *d);
	int			color_palette[N_COLOR];

	double		x_min;
	double		x_max;
	double		y_min;
	double		y_max;
	int			n_iter;
	t_pixel		**map;

	t_complex	julia_param;
}				t_display;

typedef struct	s_disp_bundle
{
	t_display	*d;
	int			y_min;
	int			y_max;
	//pthread_mutex_t mutex;
}				t_disp_bundle;

int				compute_mandelbrot_values(t_complex c, int n_iter);
t_complex		c_add(t_complex a, t_complex b);
t_complex 		c_mult(t_complex a, t_complex b);
t_complex		c_init(double r, double i);
void			c_print(t_complex c);
double			squared_modulus(t_complex c);

int				mandelbrot_diverge(t_pixel *p, int n_iter);
void			display_complex_fractal(t_display *d);
void			init_mandelbrot(t_display *d);
void			*mandelbrot(void* param);
void			init_julia(t_display *d);
void			julia(t_display *d);

void			refresh_screen(t_display *d, int opt);
void			compute_coordinates_map(t_display *d);
void			init_display(t_display *d);
void			click_zoom(t_display *d, int x, int y);

void			image_put_pixel(t_display *d, int x, int y, int color);

void			error(int err);
int				deal_key(int key, void *param);
int				deal_mouse(int button, int x, int y, void *param);

int				find_color(t_display *d, int n_div);
void			build_color_palette(t_display *d);

void			vertical_line(t_display *d, int x, int y_start, int y_end, int color);
void			horizontal_line(t_display *d, int y, int x_start, int x_end, int color);

void			free_map(t_display *d);

#endif
