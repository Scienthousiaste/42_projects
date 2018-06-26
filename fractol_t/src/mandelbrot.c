/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 17:56:30 by tbehra            #+#    #+#             */
/*   Updated: 2018/06/26 18:50:11 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		compute_mandelbrot_values(t_complex c, int n_iter)
{
	t_complex	z;
	int			i;

	i = 0;
	z = c_init(0, 0);
	while (++i < n_iter)
	{
		z = c_add(c_mult(z, z), c);
		c_print(z);
	}
	return (0);
}

int		mandelbrot_diverge(t_pixel *p, int n_iter)
{
	int i;
	t_complex z;
	t_complex c;

	c = p->z;
	if (p->n_iter_value > n_iter)
	{
		//i = (p->n_iter_value == 0) ? 0 : n_iter;
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

void	mandelbrot(t_display *d)
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
			if ((n_div = mandelbrot_diverge(&(d->map[y][x]), d->n_iter)))
				image_put_pixel(d, x, y, find_color(d, n_div));
			else
				image_put_pixel(d, x, y, BLACK);
		}
	}
	mlx_put_image_to_window(d->mlx, d->win, d->img, 0, 0);
	return ;
}
