/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/27 19:05:22 by tbehra            #+#    #+#             */
/*   Updated: 2018/05/27 19:09:14 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"

int		usage(void)
{
	ft_putstr("Usage: ./display filler.disp\n");
	return (1);
}

void	update_prev_tabs(t_display_mlx *d)
{
	int r;

	r = -1;
	while (++r < d->ymax - 1)
	{
		ft_strcpy(d->prev_tab[r], d->tab[r]);
		ft_strcpy(d->prev_frontier[r], d->frontier[r]);
	}
}

void	print_rectangle(t_rect *rect, t_display_mlx *d)
{
	int x;
	int y;

	y = -1;
	while (++y < rect->height)
	{
		x = -1;
		while (++x < rect->width)
			mlx_pixel_put(d->mlx, d->win, rect->coord.x + x,
					rect->coord.y + y, rect->color);
	}
	return ;
}

void	print_square(int size, int color, t_point *p, t_display_mlx *d)
{
	int x;
	int y;

	y = -1;
	while (++y < size)
	{
		x = -1;
		while (++x < size)
			mlx_pixel_put(d->mlx, d->win, p->x + x, p->y + y, color);
	}
}

void	quit_program(t_display_mlx *d)
{
	if (d->tab)
		ft_tabdel((void**)d->tab, d->ymax);
	if (d->frontier)
		ft_tabdel((void**)d->frontier, d->ymax);
	if (d->prev_tab)
		ft_tabdel((void**)d->prev_tab, d->ymax);
	if (d->prev_frontier)
		ft_tabdel((void**)d->prev_frontier, d->ymax);
	fclose(d->file);
	exit(0);
}
