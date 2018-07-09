/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collatz.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/08 20:49:39 by tbehra            #+#    #+#             */
/*   Updated: 2018/07/09 18:01:49 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		collatz_init_pixel(t_pixel *p, int n_iter)
{
	int i;

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
	return (i);
}

int		collatz_diverge(t_pixel *p, int n_iter, double collatz_max)
{
	int			i;
	t_complex	z;
	t_complex	c;

	c = p->z;
	i = collatz_init_pixel(p, n_iter);
	z = (p->n_iter_value == 0) ? p->z : p->z_value;
	while (++i <= n_iter)
	{
		z = c_scalar_mult(c_sub(c_add_re(c_scalar_mult(z, 7), 2),
				c_mult(c_add_re(c_scalar_mult(z, 5), 2),
				c_cos((c_scalar_mult(z, M_PI))))), 0.25);
		if (squared_modulus(z) > collatz_max)
		{
			p->n_iter_div = i;
			return (i);
		}
	}
	p->z_value = z;
	p->n_iter_value = n_iter;
	return (0);
}

void	init_collatz(t_display *d)
{
	d->win_width = (d->win_width != 0) ?
		d->win_width : DEFAULT_WIN_WIDTH_C;
	d->win_height = (d->win_height != 0) ?
		d->win_height : DEFAULT_WIN_HEIGHT_C;
	d->x_min = -5;
	d->x_max = 5;
	d->y_min = -2;
	d->y_max = 2;
	d->no_zoom = 0;
	d->collatz_param = DEFAULT_COLLATZ_PARAM;
}

void	rotate_collatz_param(t_display *d)
{
	if (d->collatz_param == (double)DEFAULT_COLLATZ_PARAM)
		d->collatz_param = d->collatz_param * 10000;
	else if (d->collatz_param == (double)DEFAULT_COLLATZ_PARAM * 10000)
		d->collatz_param *= 10000;
	else if (d->collatz_param == (double)DEFAULT_COLLATZ_PARAM * 100000000)
		d->collatz_param = (double)DEFAULT_COLLATZ_PARAM / 100;
	else
		d->collatz_param = DEFAULT_COLLATZ_PARAM;
}

void	*collatz(void *param)
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
			if ((n_div = collatz_diverge(&(d->map[y][x]),
				d->n_iter, d->collatz_param)))
				image_put_pixel(d, x, y, find_color(d, n_div));
			else
				image_put_pixel(d, x, y, BLACK);
		}
		y++;
	}
	pthread_exit(NULL);
}
