/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 17:44:31 by tbehra            #+#    #+#             */
/*   Updated: 2018/06/27 18:25:48 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		julia_diverge(t_pixel *p, int n_iter, t_complex julia_param)
{
	int i;
	t_complex z;

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
	z = (p->n_iter_value == 0) ? julia_param : p->z_value;
	while (++i <= n_iter)
	{
		z = c_add(c_mult(z, z), p->z);
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

void	julia(t_display *d)
{
	int x;
	int y;
	int n_div;

	y = -1;
	while (++y < WIN_HEIGHT)
	{
		x = -1;
		while (++x < WIN_WIDTH)
		{
			if ((n_div = julia_diverge(&(d->map[y][x]), d->n_iter,
				d->julia_param)))
				image_put_pixel(d, x, y, find_color(d, n_div));
			else
				image_put_pixel(d, x, y, BLACK);
		}
	}
	mlx_put_image_to_window(d->mlx, d->win, d->img, 0, 0);
	return ;
}
