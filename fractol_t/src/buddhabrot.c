/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buddhabrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 18:10:29 by tbehra            #+#    #+#             */
/*   Updated: 2018/07/23 20:39:45 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//http://paulbourke.net/fractals/buddhabrot/
//http://paulbourke.net/fractals/buddhabrot/buddha.c
#include "fractol.h"

t_pixel	*find_pixel(t_complex a, t_display *d)
{
	int     x;
	int     y;
	double  x_inc;
	double  y_inc;

	x_inc = (double)((double)1 / (double)d->win_width);
	y_inc = (double)((double)1 / (double)d->win_height);
	if (a.re > d->x_max || a.re < d->x_min ||
			a.im > d->y_max || a.im < d->y_min)
		return (NULL);
	x = (int)((a.re - d->x_min)/x_inc);
	y = (int)((a.im - d->y_min)/y_inc);
	if (x < 0 || x >= d->win_width || y < 0 || y >= d->win_height)
		return (NULL);
	return (&d->map[y][x]);
}

int		buddhabrot_diverge(t_complex z, int n_iter)
{
	int			i;
	t_complex	c;

	i = 0;
	c = z;
	while (++i <= n_iter)
	{
		z = c_add(c_mult(z, z), c);
		if (squared_modulus(z) >= 4)
			return (1);
	}
	return (0);
}

void	buddhabrot_iterate(t_complex z, int n_iter, t_display *d)
{
	int			i;
	t_complex	c;
	t_pixel		*p_landed;

	c = z;
	i = 0;
	z = c_init(0, 0);
	while (++i <= n_iter)
	{
		z = c_add(c_mult(z, z), c);
		if ((p_landed = find_pixel(z, d)))
			p_landed->buddha++;
		if (squared_modulus(z) >= 4)
			return ;
	}
}

void	init_buddhabrot(t_display *d)
{
	d->win_width = (d->win_width != 0) ?
		d->win_width : DEFAULT_WIN_WIDTH_U;
	d->win_height = (d->win_height != 0) ?
		d->win_height : DEFAULT_WIN_HEIGHT_U;
	d->x_min = -2;
	d->x_max = 2;
	d->y_min = -2;
	d->y_max = 2;
	d->buddha_nval_x = DEFAULT_BUDDHA_NVAL_X;
	d->buddha_nval_y = DEFAULT_BUDDHA_NVAL_Y;
	d->buddha_min_xval = DEFAULT_BUDDHA_MIN_XVAL;
	d->buddha_min_yval = DEFAULT_BUDDHA_MIN_YVAL;
	d->buddha_max_xval = DEFAULT_BUDDHA_MAX_XVAL;
	d->buddha_max_yval = DEFAULT_BUDDHA_MAX_YVAL;
}

void buddhabrot_compute_values(t_disp_bundle *db)
{
	t_display	*d;
	int			y;
	int			x;
	t_complex	z;

	d = db->d;
	y = -1;
	while (++y < d->buddha_nval_y)
	{
		x = -1;
		while (++x < d->buddha_nval_x)
		{
			z = c_init(
				   (double)((double)x / (double)d->buddha_nval_x) *
				   (d->buddha_max_xval - d->buddha_min_xval) + d->buddha_min_xval,
				   (double)((double)y / (double)d->buddha_nval_y) *
				   (d->buddha_max_yval - d->buddha_min_yval) + d->buddha_min_yval);
			if(buddhabrot_diverge(z, d->n_iter))
				buddhabrot_iterate(z, d->n_iter, d);
		}
	}
}

void	*buddhabrot(void *param)
{
	t_display		*d;
	t_disp_bundle	*db;
	int				y;
	int				x;

	db = (t_disp_bundle*)param;
	buddhabrot_compute_values(db);
	d = db->d;
	y = db->y_min;
	while (y < db->y_max)
	{
		x = -1;
		while (++x < d->win_width)
			image_put_pixel(d, x, y, find_color(d, d->map[y][x].buddha));
		y++;
	}
	pthread_exit(NULL);
}
