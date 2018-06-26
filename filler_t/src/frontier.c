/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frontier.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 16:29:01 by tbehra            #+#    #+#             */
/*   Updated: 2018/05/28 11:42:54 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	draw_frontier(t_filler *f, int x, int y)
{
	if ((x - 1 >= 0 && (f->frontier[y][x - 1]) == PLAYER_TERRITORY)
	|| (x + 1 < f->xmax && (f->frontier[y][x + 1]) == PLAYER_TERRITORY)
	|| (y - 1 >= 0 && (f->frontier[y - 1][x]) == PLAYER_TERRITORY)
	|| (y + 1 < f->ymax && (f->frontier[y + 1][x]) == PLAYER_TERRITORY))
		return ;
	f->frontier[y][x] = ENNEMY_TERRITORY;
}

void	update_frontier(t_filler *f, int player_sign)
{
	int x;
	int y;
	int i;

	i = RESET_COUNT;
	while (++i < 3)
	{
		y = RESET_COUNT;
		while (++y < f->ymax)
		{
			x = RESET_COUNT;
			if (i == 0)
				while (++x < f->xmax)
					if (!f->frontier[y][x])
						fill_frontier(f, x, y, player_sign);
			if (i == 1)
				while (++x < f->xmax)
					f->frontier[y][x] %= 2;
			if (i == 2)
				while (++x < f->xmax)
					if (!f->frontier[y][x] && player_sign == ENNEMY_TERRITORY)
						draw_frontier(f, x, y);
		}
	}
}

void	find_coord(t_filler *f, int64_t *coord)
{
	int64_t x;
	int64_t y;

	y = RESET_COUNT;
	while (++y < f->ymax)
	{
		x = RESET_COUNT;
		while (++x < f->xmax)
		{
			if (f->tab[y][x] != '.')
			{
				if (f->tab[y][x] == f->player)
					*coord |= (y << TWO_BYTES) | x;
				else if (*coord <= INT_MAX)
					*coord |= (y << SIX_BYTES) | (x << FOUR_BYTES);
			}
		}
	}
}

int8_t	belongs_to_us(int x, int y, int64_t coord)
{
	t_coord	c;
	int		dist_y_p;
	int		dist_y_e;
	int		dist_x_p;
	int		dist_x_e;

	c.x_player = coord & MASQ_SHORT;
	c.y_player = (coord >> TWO_BYTES) & MASQ_SHORT;
	c.y_ennemy = (coord >> SIX_BYTES) & MASQ_SHORT;
	c.x_ennemy = (coord >> FOUR_BYTES) & MASQ_SHORT;
	dist_y_p = (c.y_player - y) < 0 ? -(c.y_player - y) : c.y_player - y;
	dist_y_e = (c.y_ennemy - y) < 0 ? -(c.y_ennemy - y) : c.y_ennemy - y;
	dist_x_p = (c.x_player - x) < 0 ? -(c.x_player - x) : c.x_player - x;
	dist_x_e = (c.x_ennemy - x) < 0 ? -(c.x_ennemy - x) : c.x_ennemy - x;
	if (dist_y_p + dist_x_p > dist_y_e + dist_x_e + 1)
		return (ENNEMY_TERRITORY);
	return (dist_y_p + dist_x_p < dist_y_e + dist_x_e - 1);
}

void	set_frontier(t_filler *f)
{
	int64_t		coord;
	int			x;
	int			y;

	coord = 0;
	find_coord(f, &coord);
	if (!(f->frontier = (int8_t**)malloc(sizeof(int8_t*) * f->ymax)))
		return ;
	y = RESET_COUNT;
	while (++y < f->ymax)
	{
		if (!(f->frontier[y] = (int8_t*)malloc(f->xmax)))
			return ;
		x = RESET_COUNT;
		while (++x < f->xmax)
		{
			f->frontier[y][x] = belongs_to_us(x, y, coord);
			f->territory += (f->frontier[y][x] == PLAYER_TERRITORY);
		}
	}
}
