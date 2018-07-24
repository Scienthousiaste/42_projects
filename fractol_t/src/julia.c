/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 17:44:31 by tbehra            #+#    #+#             */
/*   Updated: 2018/07/24 15:30:49 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		change_julia_param(int x, int y, void *param)
{
	t_display *d;

	d = (t_display*)param;
	if (d->julia_param_modif && x > 0
			&& x < d->win_width && y > 0 && y < d->win_height)
	{
		d->julia_param = d->map[y][x].z;
		refresh_screen(d, RECOMPUTE_COORD);
	}
	return (0);
}

int		julia_diverge(t_pixel *p, int n_iter, t_complex julia_param)
{
	int			i;
	t_complex	z;

	if (p->n_iter_value > n_iter && (i = 0))
	{
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
	z = (p->n_iter_value == 0) ? p->z : p->z_value;
	while (++i <= n_iter)
	{
		z = c_add(c_mult(z, z), julia_param);
		if (squared_modulus(z) >= 4 && (p->n_iter_div = i))
			return (i);
	}
	p->z_value = z;
	p->n_iter_value = n_iter;
	return (0);
}

void	init_julia(t_display *d)
{
	d->win_width = (d->win_width != 0) ? d->win_width : DEFAULT_WIN_WIDTH_J;
	d->win_height = (d->win_height != 0) ? d->win_height : DEFAULT_WIN_HEIGHT_J;
	d->x_min = -2;
	d->x_max = 2;
	d->y_min = -2;
	d->y_max = 2;
	d->julia_param = c_init(DEFAULT_JULIA_RE, DEFAULT_JULIA_IM);
}

void	*julia(void *param)
{
	t_display		*d;
	t_disp_bundle	*db;
	int				x;
	int				y;
	int				n_div;

	db = (t_disp_bundle*)param;
	d = db->d;
	y = db->y_min;
	while (y < db->y_max)
	{
		x = -1;
		while (++x < d->win_width)
		{
			if ((n_div = julia_diverge(&(d->map[y][x]), d->n_iter,
							d->julia_param)))
				image_put_pixel(d, x, y, find_color(d, n_div));
			else
				image_put_pixel(d, x, y, BLACK);
		}
		y++;
	}
	pthread_exit(NULL);
}
