/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 17:56:30 by tbehra            #+#    #+#             */
/*   Updated: 2018/07/08 20:45:13 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mandelbrot_diverge(t_pixel *p, int n_iter)
{
	int			i;
	t_complex	z;
	t_complex	c;

	c = p->z;
	if (p->n_iter_value > n_iter)
	{
		i = 0;
		p->n_iter_value = 0;
		p->n_iter_div = 0;
		p->z_value = p->z;
	}
	else
	{
		if (p->n_iter_div)
			return (p->n_iter_div);
		i = (p->n_iter_value == 0) ? 0 : p->n_iter_value;
	}
	z = (p->n_iter_value == 0) ? c_init(0, 0) : p->z_value;
	while (++i <= n_iter)
	{
		z = c_add(c_mult(z, z), c);
		if (squared_modulus(z) >= 4)
		{
			p->n_iter_div = i;
			return (i);
		}
	}
	p->z_value = z;
	p->n_iter_value = n_iter;
	return (0);
}

void	init_mandelbrot(t_display *d)
{
	d->win_width = (d->win_width != 0) ?
		d->win_width : DEFAULT_WIN_WIDTH_M;
	d->win_height = (d->win_height != 0) ?
		d->win_height : DEFAULT_WIN_HEIGHT_M;
	d->x_min = -2;
	d->x_max = 1;
	d->y_min = -1;
	d->y_max = 1;
}

void	*mandelbrot(void *param)
{
	t_display		*d;
	t_disp_bundle	*db;
	int				n_div;
	int				y;
	int				x;

	db = (t_disp_bundle*)param;
	d = db->d;
	y = db->y_min;
	while (y < db->y_max)
	{
		x = -1;
		while (++x < d->win_width)
		{
			if ((n_div = mandelbrot_diverge(&(d->map[y][x]), d->n_iter)))
				image_put_pixel(d, x, y, find_color(d, n_div));
			else
				image_put_pixel(d, x, y, BLACK);
		}
		y++;
	}
	pthread_exit(NULL);
}
