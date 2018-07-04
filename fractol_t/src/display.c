/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 11:17:54 by tbehra            #+#    #+#             */
/*   Updated: 2018/06/30 16:42:05 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	click_zoom(t_display *d, int x, int y)
{
	int new_zero_x;
	int	new_max_x;
	int new_zero_y;
	int new_max_y;

	new_zero_x = ((x - (d->win_width / 4)) > 0) ? (x - (d->win_width / 4)) : 0;
	new_zero_x = ((x + (d->win_width / 4)) > (d->win_width - 1)) ?
		 d->win_width / 2 : new_zero_x;
	new_max_x = ((new_zero_x + (d->win_width / 2)) < d->win_width) ? new_zero_x
		+ (d->win_width / 2) : d->win_width - 1;
	new_zero_y = ((y - (d->win_height / 4)) > 0) ? (y - (d->win_height / 4)) : 0;
	new_zero_y = ((y + (d->win_height / 4) > (d->win_height - 1))) ?
		d->win_height / 2 : new_zero_y;
	new_max_y = ((new_zero_y + (d->win_height / 2)) < d->win_height) ? new_zero_y
		+ (d->win_height / 2) : d->win_height - 1;
	d->x_min = (d->map[new_zero_y][new_zero_x]).z.re;
	d->x_max = (d->map[new_max_y][new_max_x]).z.re;
	d->y_min = (d->map[new_zero_y][new_zero_x]).z.im;
	d->y_max = (d->map[new_max_y][new_max_x]).z.im;
	printf("x min %.12f max %.12f\ny min %.12f, max %.12f\n\n", d->x_min, d->x_max, d->y_min, d->y_max);//
}

void	compute_coordinates_map(t_display *d)
{
	int i;
	int j;
	double	proportion_x;
	double	proportion_y;
	double  x_inc;
	double  y_inc;

	x_inc = (double)((double)1 / (double)d->win_width);
	y_inc = (double)((double)1 / (double)d->win_height);
	proportion_y = 0;
	i = 0;
	while (++i <= d->win_height)
	{
		if (!(d->map[i - 1] = (t_pixel*)malloc(sizeof(t_pixel) * d->win_width)))
			error(MALLOC_ERROR);
		j = 0;
		proportion_x = 0;
		while (++j <= d->win_width)
		{
			ft_bzero((void*)&(d->map[i - 1][j - 1]), sizeof(t_pixel));
			(&(d->map[i - 1][j - 1]))->z =
				c_init((double)((d->x_max - d->x_min)*proportion_x + d->x_min),
					(double)((d->y_max - d->y_min)*proportion_y + d->y_min));
			proportion_x += x_inc;
		}
		proportion_y += y_inc;
	}
}

void	recompute_coordinates(t_display *d)
{
	int i;
	int j;
	double	proportion_x;
	double	proportion_y;
	double  x_inc;
	double  y_inc;

	x_inc = (double)((double)1 / (double)d->win_width);
	y_inc = (double)((double)1 / (double)d->win_height);
	proportion_y = 0;
	i = 0;
	while (++i <= d->win_height)
	{
		j = 0;
		proportion_x = 0;
		while (++j <= d->win_width)
		{
			ft_bzero((void*)&(d->map[i - 1][j - 1]), sizeof(t_pixel));
			(&(d->map[i - 1][j - 1]))->z =
				c_init((double)((d->x_max - d->x_min)*proportion_x + d->x_min),
					(double)((d->y_max - d->y_min)*proportion_y + d->y_min));
			proportion_x += x_inc;
		}
		proportion_y += y_inc;
	}
}

void	refresh_screen(t_display *d, int opt)
{
	if (opt == RECOMPUTE_COORD)
		recompute_coordinates(d);
	mlx_clear_window(d->mlx, d->win);
	display_complex_fractal(d);
}

void	init_display(t_display *d)
{	
	d->mlx = mlx_init();
	d->win = mlx_new_window(d->mlx, d->win_width, d->win_height, WIN_TITLE);
	d->n_iter = N_ITER_INIT;
	d->img = mlx_new_image(d->mlx, d->win_width, d->win_height);
	d->img_ptr = mlx_get_data_addr(d->img, &(d->bits_per_pixel),
			&(d->size_line), &(d->endian));
	build_color_palette(d);
	if (!(d->map = (t_pixel**)malloc(sizeof(t_pixel*) * d->win_height)))
		error(MALLOC_ERROR);
	compute_coordinates_map(d);	
}
