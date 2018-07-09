/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 11:10:03 by tbehra            #+#    #+#             */
/*   Updated: 2018/07/09 15:35:10 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	quit_program(t_display *d)
{
	mlx_destroy_window(d->mlx, d->win);
	exit(0);
}

/*
Il doit être possible de faire varier avec la souris (sans clic) le paramètre de l’ensemble
de Julia. Pour les autres types de fractale, cela est laissé à votre discrétion.
La molette de la souris permet de zoomer et dézoomer, et cela de façon quasi
infinie (modulo les limites de la machine). C’est le principe même des fractales

https://fractalforums.org/mandelbulber/14
https://en.wikipedia.org/wiki/Mandelbulb
*/
int		deal_mouse(int button, int x, int y, void *param)
{
	t_display *d;

	d = (t_display*)param;
	if (button == d->zoom_button && !(d->no_zoom))
	{
		click_zoom(d, x, y);
		refresh_screen(d, RECOMPUTE_COORD);
	}
	if (button == MOUSE_SCROLL_OUT && !(d->no_zoom))
	{
		dezoom(d, x, y);
		refresh_screen(d, RECOMPUTE_COORD);
	}
	return (0);
}

int		deal_key(int key, void *param)
{
	t_display	*d;
	int			refresh;

	printf("Key %d\n", key);
	refresh = 0;
	d = (t_display*)param;
	if (key == KEY_PLUS && (refresh = 1))
		d->n_iter += 1;
	if (key == KEY_SUP_TO && (refresh = 1))
		d->n_iter += LARGE_INC;
	if (key == KEY_MINUS)
		if (d->n_iter > 1 && (refresh = 1))
			d->n_iter -= 1;
	if (key == KEY_INF_TO)
		if (d->n_iter > LARGE_INC && (refresh = 1))
			d->n_iter -= LARGE_INC;
	if ((key == LEFT_ARROW_KEY || key == RIGHT_ARROW_KEY || key == DOWN_ARROW_KEY
			|| key == UP_ARROW_KEY) && (refresh = RECOMPUTE_COORD))
		translation(d, key);
	if (key == ESC_KEY)
		quit_program(d);
	if (key == KEY_F && (refresh = 1))
		d->julia_param_modif = 
			(d->julia_param_modif) ? 0 : 1;
	if (key == KEY_C)
		d->zoom_button = (d->zoom_button == MOUSE_CLICK) ? MOUSE_SCROLL_IN : MOUSE_CLICK;
	if (key == KEY_Z)
		d->no_zoom = !(d->no_zoom);
	if (key == KEY_R && (refresh = RECOMPUTE_COORD))
		recenter(d);
	if (key == KEY_I && d->display_fractal == &collatz && (refresh = RECOMPUTE_COORD))
		rotate_collatz_param(d);
	if (refresh)
		refresh_screen(d, refresh);
	return (0);
}
