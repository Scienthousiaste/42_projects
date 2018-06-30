/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 11:10:03 by tbehra            #+#    #+#             */
/*   Updated: 2018/06/30 18:13:15 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	quit_program(t_display *d)
{
	mlx_destroy_window(d->mlx, d->win);
	exit(0);
}

int		deal_mouse(int button, int x, int y, void *param)
{
	t_display *d;

	d = (t_display*)param;
	printf("button %d, x %d, y %d\n", button, x, y);
	if (button == 1)
	{
		click_zoom(d, x, y);
		refresh_screen(d, RECOMPUTE_COORD);
	}
	return (0);
}

int		deal_key(int key, void *param)
{
	t_display	*d;
	int			refresh;

	refresh = 0;
	d = (t_display*)param;
	if (key == RIGHT_ARROW_KEY && (refresh = 1))
		d->n_iter += 1;
	if (key == LEFT_ARROW_KEY)
		if (d->n_iter > 1 && (refresh = 1))
			d->n_iter -= 1;
	if (key == ESC_KEY)
		quit_program(d);
	if (refresh)
		refresh_screen(d, refresh);
	return (0);
}
