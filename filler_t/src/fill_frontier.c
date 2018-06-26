/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_frontier.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 16:56:29 by tbehra            #+#    #+#             */
/*   Updated: 2018/05/28 11:22:35 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int8_t	is_player(t_filler *f, int x, int y, int player_sign)
{
	int x1;
	int y1;

	if (x < 0 || x >= f->xmax || y < 0 || y >= f->ymax)
		return (0);
	if (f->tab[y][x] != '.')
	{
		if (f->tab[y][x] == f->player)
			return (PLAYER_TERRITORY);
		else
			return (ENNEMY_TERRITORY);
	}
	if (player_sign == PLAYER_TERRITORY)
	{
		x1 = x - f->bestpos.x;
		y1 = y - f->bestpos.y;
		if (x1 < 0 || x1 >= f->piece.xmax || y1 < 0 || y1 >= f->piece.ymax)
			return (0);
		return (f->piece.tab[y1][x1] == '*');
	}
	return (0);
}

int8_t	check_pos(t_filler *f, t_pos p, int player_sign)
{
	int ret;
	int n;
	int	x1;
	int	y1;

	x1 = p.x - p.distance;
	y1 = p.y;
	ret = 0;
	while (x1 != p.x && ret != LOST_TERRITORY)
		if ((n = is_player(f, x1++, y1--, player_sign)) && n != ret)
			ret = ret ? LOST_TERRITORY : n;
	while (y1 != p.y && ret != LOST_TERRITORY)
		if ((n = is_player(f, x1++, y1++, player_sign)) && n != ret)
			ret = ret ? LOST_TERRITORY : n;
	while (x1 != p.x && ret != LOST_TERRITORY)
		if ((n = is_player(f, x1--, y1++, player_sign)) && n != ret)
			ret = ret ? LOST_TERRITORY : n;
	while (y1 != p.y && ret != LOST_TERRITORY)
		if ((n = is_player(f, x1--, y1--, player_sign)) && n != ret)
			ret = ret ? LOST_TERRITORY : n;
	return (ret);
}

int8_t	closest_player(t_filler *f, int x, int y, int player_sign)
{
	int		ret;
	int		n;
	t_pos	p;

	p.x = x;
	p.y = y;
	p.distance = 0;
	ret = 0;
	while (++p.distance && !ret)
		ret = check_pos(f, p, player_sign);
	if (ret != LOST_TERRITORY)
		if ((n = check_pos(f, p, player_sign)) && n != ret)
			ret = LOST_TERRITORY;
	if (ret == LOST_TERRITORY)
		ret = 0;
	return (ret);
}

void	move_next_frontier(t_filler *f, int x, int y, int player_sign)
{
	if (x + 1 < f->xmax && f->frontier[y][x + 1] == -player_sign)
		fill_frontier(f, x + 1, y, player_sign);
	if (x - 1 >= 0 && f->frontier[y][x - 1] == -player_sign)
		fill_frontier(f, x - 1, y, player_sign);
	if (y + 1 < f->ymax && f->frontier[y + 1][x] == -player_sign)
		fill_frontier(f, x, y + 1, player_sign);
	if (y - 1 >= 0 && f->frontier[y - 1][x] == -player_sign)
		fill_frontier(f, x, y - 1, player_sign);
	if (x + 1 < f->xmax && y + 1 < f->ymax &&
			f->frontier[y + 1][x + 1] == -player_sign)
		fill_frontier(f, x + 1, y + 1, player_sign);
	if (x - 1 >= 0 && y + 1 < f->ymax &&
			f->frontier[y + 1][x - 1] == -player_sign)
		fill_frontier(f, x - 1, y + 1, player_sign);
	if (x + 1 < f->xmax && y - 1 >= 0 &&
			f->frontier[y - 1][x + 1] == -player_sign)
		fill_frontier(f, x + 1, y - 1, player_sign);
	if (x - 1 >= 0 && y - 1 >= 0 && f->frontier[y - 1][x - 1] == -player_sign)
		fill_frontier(f, x - 1, y - 1, player_sign);
}

void	fill_frontier(t_filler *f, int x, int y, int player_sign)
{
	int8_t pre_fill;

	pre_fill = f->frontier[y][x];
	if (f->tab[y][x] != '.')
		f->frontier[y][x] = (f->tab[y][x] == f->player) ?
			NEW_PLAYER_TERRITORY : NEW_ENNEMY_TERRITORY;
	else if (x - f->bestpos.x >= 0 && x - f->bestpos.x < f->piece.xmax &&
			y - f->bestpos.y >= 0 && y - f->bestpos.y < f->piece.ymax &&
			f->piece.tab[y - f->bestpos.y][x - f->bestpos.x] == '*')
		f->frontier[y][x] = NEW_PLAYER_TERRITORY;
	else
		f->frontier[y][x] = closest_player(f, x, y, player_sign) ^ 2;
	if (pre_fill != f->frontier[y][x] % 2)
	{
		if (pre_fill == PLAYER_TERRITORY)
			f->territory--;
		else if (f->frontier[y][x] == NEW_PLAYER_TERRITORY)
			f->territory++;
		move_next_frontier(f, x, y, player_sign);
	}
}
