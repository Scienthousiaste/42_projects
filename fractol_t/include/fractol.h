/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 17:31:19 by tbehra            #+#    #+#             */
/*   Updated: 2018/07/24 20:02:44 by tbehra           ###   ########.fr       */
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

# define MALLOC_ERROR 1
# define INVALID_OPTION 2
# define INVALID_WINDOW_SIZE 3

# define RECOMPUTE_COORD 2
# define REINIT_MAP 4

# define DEFAULT_JULIA_RE 0.285
# define DEFAULT_JULIA_IM 0.013
# define DEFAULT_COLLATZ_PARAM 10000
# define DEFAULT_BUDDHA_NVAL_X 100
# define DEFAULT_BUDDHA_NVAL_Y 100
# define DEFAULT_BUDDHA_MIN_XVAL -2
# define DEFAULT_BUDDHA_MIN_YVAL -2
# define DEFAULT_BUDDHA_MAX_XVAL 2
# define DEFAULT_BUDDHA_MAX_YVAL 2
# define DEFAULT_WIN_WIDTH_J 600
# define DEFAULT_WIN_HEIGHT_J 600
# define DEFAULT_WIN_WIDTH_M 1000
# define DEFAULT_WIN_HEIGHT_M 600
# define DEFAULT_WIN_WIDTH_B 1000
# define DEFAULT_WIN_HEIGHT_B 600
# define DEFAULT_WIN_WIDTH_U 1000
# define DEFAULT_WIN_HEIGHT_U 1000
# define DEFAULT_WIN_WIDTH_C 1500
# define DEFAULT_WIN_HEIGHT_C 600

# define N_ITER_INIT 20
# define N_COLOR 18
# define MIN_WIN_WIDTH 40
# define MIN_WIN_HEIGHT 40
# define MAX_WIN_WIDTH 3000
# define MAX_WIN_HEIGHT 1800
# define NB_THREAD 40

# define TRANSLATION_FACTOR 0.25
# define LARGE_INC 20
# define COLOR_MODE_PSYCH 0
# define COLOR_MODE_SHADING 1

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

	int			buddha;
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
	int			julia_param_modif;
	double		collatz_param;

	int			buddha_nval_x;
	int			buddha_nval_y;
	double		buddha_max_xval;
	double		buddha_max_yval;
	double		buddha_min_xval;
	double		buddha_min_yval;

	int			zoom_button;
	int			no_zoom;
	int			color_mode;
}				t_display;

typedef struct	s_disp_bundle
{
	t_display	*d;
	int			y_min;
	int			y_max;
}				t_disp_bundle;

t_complex		c_minus(t_complex c);
t_complex		c_add_re(t_complex a, double to_add);
t_complex		c_sub(t_complex a, t_complex b);
t_complex		c_add(t_complex a, t_complex b);
t_complex		c_init(double r, double i);
t_complex		c_mult(t_complex a, t_complex b);
t_complex		c_mult_i(t_complex c);
t_complex		c_scalar_mult(t_complex a, double scalar);
t_complex		c_exp(t_complex c);
t_complex		c_cos(t_complex c);
t_complex		c_rotate(t_complex a, double angle);
t_complex		c_abs(t_complex c);
double			modulus(t_complex c);
double			squared_modulus(t_complex c);

int				init_i(int *i, t_pixel *p, int n_iter);
void			display_complex_fractal(t_display *d);
int				mandelbrot_diverge(t_pixel *p, int n_iter);
int				compute_mandelbrot_values(t_complex c, int n_iter);
void			init_mandelbrot(t_display *d);
void			*mandelbrot(void *param);
void			init_julia(t_display *d);
void			*julia(void *d);
void			init_collatz(t_display *d);
void			*collatz(void *param);
void			collatz_comp_values(t_display *d, int x, int y);
void			*burning_ship(void *param);
void			init_burning_ship(t_display *d);
void			rotate_collatz_param(t_display *d);
void			translation(t_display *d, int key);
void			*buddhabrot(void *param);
void			init_buddhabrot(t_display *d);

void			compute_coordinates(t_display *d);
void			compute_coordinates_map(t_display *d);
void			init_display(t_display *d);
void			click_zoom(t_display *d, int x, int y);
void			dezoom(t_display *d, int x, int y);
void			recenter(t_display *d);
void			refresh_screen(t_display *d, int opt);
void			image_put_pixel(t_display *d, int x, int y, int color);

int				check_more_params(int i, char **av, t_display *d);
void			check_params(int ac, char **av, t_display *d);
int				get_window_size(int ac, char **av, int i, t_display *d);
void			usage(void);
void			error(int err);
int				deal_key(int key, void *param);
int				deal_mouse(int button, int x, int y, void *param);
int				change_julia_param(int x, int y, void *param);

int				find_color(t_display *d, int n_div);
void			build_color_palette(t_display *d);
void			build_monochrome_palette(t_display *d, unsigned int mask_color);
void			color_shading(t_display *d);

void			vertical_line(t_display *d, int x, int y_start,
					int y_end, int color);
void			horizontal_line(t_display *d, int y, int x_start,
					int x_end, int color);

void			free_map(t_display *d);

#endif
