/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 18:31:05 by tbehra            #+#    #+#             */
/*   Updated: 2018/06/27 17:16:19 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	vertical_line(t_display *d, int x, int y_start, int y_end, int color)
{
	while (y_start < y_end)
		mlx_pixel_put(d->mlx, d->win, x, y_start++, color);
}

void	horizontal_line(t_display *d, int y, int x_start, int x_end, int color)
{
	while (x_start < x_end)
		mlx_pixel_put(d->mlx, d->win, x_start++, y, color);
}

void	free_map(t_display *d)
{
	int i;

	i = 0;
	while (++i <= WIN_HEIGHT)
	{
		free(d->map[i - 1]);
	}
	free(d->map);
}
