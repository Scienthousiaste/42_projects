/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 17:31:19 by tbehra            #+#    #+#             */
/*   Updated: 2018/06/26 19:14:45 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include <mlx.h>
# include <stdlib.h>
# include "libft.h"
# include "display.h"


//
#include <stdio.h>
//
//
#define MALLOC_ERROR 1

#define RECOMPUTE_COORD 2
#define REINIT_MAP 4

# define N_ITER_INIT 30
# define N_COLOR 18
# define WIN_WIDTH 1800
# define WIN_HEIGHT 1200
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

	void		(*display_fractal)(struct s_display *d);
	int			color_palette[N_COLOR];

	double		x_min;
	double		x_max;
	double		y_min;
	double		y_max;
	int			n_iter;
	t_pixel		**map;
}				t_display;

int				compute_mandelbrot_values(t_complex c, int n_iter);
t_complex		c_add(t_complex a, t_complex b);
t_complex 		c_mult(t_complex a, t_complex b);
t_complex		c_init(double r, double i);
void			c_print(t_complex c);
double			squared_modulus(t_complex c);

int				mandelbrot_diverge(t_pixel *p, int n_iter);
void			mandelbrot(t_display *d);

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

#endif
