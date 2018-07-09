/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 15:28:36 by tbehra            #+#    #+#             */
/*   Updated: 2018/07/09 15:42:05 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    recenter(t_display *d)
{
	double size_x;
	double size_y;

	size_x = (d->map[d->win_height - 1][d->win_width - 1].z.re)
		- (d->map[0][0].z.re);
	size_y = (d->map[d->win_height - 1][d->win_width - 1].z.im)
		- (d->map[0][0].z.im);
	d->x_min = -(size_x / 2);
	d->x_max = size_x / 2;
	d->y_min = -(size_y / 2);
	d->y_max = size_y / 2;
}

void	translation(t_display *d, int key)
{
	double size_x;
	double size_y;

	size_x = (d->map[d->win_height - 1][d->win_width - 1].z.re)
		- (d->map[0][0].z.re);
	size_y = (d->map[d->win_height - 1][d->win_width - 1].z.im)
		- (d->map[0][0].z.im);
	if (key == LEFT_ARROW_KEY || key == RIGHT_ARROW_KEY)
	{
		d->x_min = (key == LEFT_ARROW_KEY) ?
			d->x_min - 0.25 * size_x : d->x_min + 0.25 * size_x;
		d->x_max = (key == LEFT_ARROW_KEY) ?
			d->x_max - 0.25 * size_x : d->x_max + 0.25 * size_x;
	}
	if (key == DOWN_ARROW_KEY || key == UP_ARROW_KEY)
	{
		d->y_min = (key == UP_ARROW_KEY) ?
			d->y_min - 0.25 * size_y : d->y_min + 0.25 * size_y;
		d->y_max = (key == UP_ARROW_KEY) ?
			d->y_max - 0.25 * size_y : d->y_max + 0.25 * size_y;
	}
}

void	free_map(t_display *d)
{
	int i;

	i = 0;
	while (++i <= d->win_height)
	{
		free(d->map[i - 1]);
	}
	free(d->map);
}
