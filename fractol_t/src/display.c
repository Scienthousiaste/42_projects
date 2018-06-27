/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 11:17:54 by tbehra            #+#    #+#             */
/*   Updated: 2018/06/27 18:31:01 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	click_zoom(t_display *d, int x, int y)
{
	int new_zero_x;
	int	new_max_x;
	int new_zero_y;
	int new_max_y;

	new_zero_x = ((x - (WIN_WIDTH / 4)) > 0) ? (x - (WIN_WIDTH / 4)) : 0;
	new_zero_x = ((x + (WIN_WIDTH / 4)) > (WIN_WIDTH - 1)) ?
		 WIN_WIDTH / 2 : new_zero_x;
	new_max_x = ((new_zero_x + (WIN_WIDTH / 2)) < WIN_WIDTH) ? new_zero_x
		+ (WIN_WIDTH / 2) : WIN_WIDTH - 1;
	new_zero_y = ((y - (WIN_HEIGHT / 4)) > 0) ? (y - (WIN_HEIGHT / 4)) : 0;
	new_zero_y = ((y + (WIN_HEIGHT / 4) > (WIN_HEIGHT - 1))) ?
		WIN_HEIGHT / 2 : new_zero_y;
	new_max_y = ((new_zero_y + (WIN_HEIGHT / 2)) < WIN_HEIGHT) ? new_zero_y
		+ (WIN_HEIGHT / 2) : WIN_HEIGHT - 1;
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

	x_inc = (double)((double)1 / (double)WIN_WIDTH);
	y_inc = (double)((double)1 / (double)WIN_HEIGHT);
	proportion_y = 0;
	i = 0;
	while (++i <= WIN_HEIGHT)
	{
		if (!(d->map[i - 1] = (t_pixel*)malloc(sizeof(t_pixel) * WIN_WIDTH)))
			error(MALLOC_ERROR);
		j = 0;
		proportion_x = 0;
		while (++j <= WIN_WIDTH)
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

	x_inc = (double)((double)1 / (double)WIN_WIDTH);
	y_inc = (double)((double)1 / (double)WIN_HEIGHT);
	proportion_y = 0;
	i = 0;
	while (++i <= WIN_HEIGHT)
	{
		j = 0;
		proportion_x = 0;
		while (++j <= WIN_WIDTH)
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
	d->display_fractal(d);
}

void	init_display(t_display *d)
{	
	d->mlx = mlx_init();
	d->win = mlx_new_window(d->mlx, WIN_WIDTH, WIN_HEIGHT, WIN_TITLE);
	d->n_iter = N_ITER_INIT;
	d->img = mlx_new_image(d->mlx, WIN_WIDTH, WIN_HEIGHT);
	d->img_ptr = mlx_get_data_addr(d->img, &(d->bits_per_pixel),
			&(d->size_line), &(d->endian));

	d->julia_param = c_init(0.12, 0.4);

	build_color_palette(d);
	if (!(d->map = (t_pixel**)malloc(sizeof(t_pixel*) * WIN_HEIGHT)))
		error(MALLOC_ERROR);
	compute_coordinates_map(d);	
}
