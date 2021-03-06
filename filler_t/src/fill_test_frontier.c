/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_test_frontier.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 19:17:33 by tbehra            #+#    #+#             */
/*   Updated: 2018/05/28 12:34:48 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int8_t	is_player_test(t_filler *f, int x, int y)
{
	int x1;
	int y1;

	if (x < 0 || x >= f->xmax || y < 0 || y >= f->ymax)
		return (0);
	if (f->tab[y][x] != '.')
		return (f->tab[y][x] == f->player ? 1 : -1);
	x1 = (x - f->piece.x);
	y1 = (y - f->piece.y);
	if (x1 < 0 || x1 >= f->piece.xmax || y1 < 0 || y1 >= f->piece.ymax)
		return (0);
	return (f->piece.tab[y1][x1] == '*');
}

int8_t	check_pos_test(t_filler *f, t_pos p)
{
	int ret;
	int n;
	int	x1;
	int	y1;

	x1 = p.x - p.distance;
	y1 = p.y;
	ret = 0;
	while (x1 != p.x && ret != 2)
		if ((n = is_player_test(f, x1++, y1--)) && n != ret)
			ret = ret ? 2 : n;
	while (y1 != p.y && ret != 2)
		if ((n = is_player_test(f, x1++, y1++)) && n != ret)
			ret = ret ? 2 : n;
	while (x1 != p.x && ret != 2)
		if ((n = is_player_test(f, x1--, y1++)) && n != ret)
			ret = ret ? 2 : n;
	while (y1 != p.y && ret != 2)
		if ((n = is_player_test(f, x1--, y1--)) && n != ret)
			ret = ret ? 2 : n;
	return (ret);
}

int8_t	closest_player_test(t_filler *f, int x, int y)
{
	int		ret;
	int		n;
	t_pos	p;

	p.x = x;
	p.y = y;
	p.distance = 0;
	ret = 0;
	while (++p.distance && !ret)
		ret = check_pos_test(f, p);
	if (ret != 2)
	{
		n = check_pos_test(f, p);
		ret = (n && n != ret) ? 2 : ret;
	}
	if (ret == 2)
		ret = 0;
	return (ret);
}

int16_t	propagate_all_directions(t_filler *f, int x, int y)
{
	int16_t ret;

	ret = 0;
	if (x + 1 < f->xmax && f->frontier[y][x + 1] == ENNEMY_TERRITORY)
		ret += fill_frontier_test(f, x + 1, y);
	if (x - 1 > 0 && f->frontier[y][x - 1] == ENNEMY_TERRITORY)
		ret += fill_frontier_test(f, x - 1, y);
	if (y + 1 < f->ymax && f->frontier[y + 1][x] == ENNEMY_TERRITORY)
		ret += fill_frontier_test(f, x, y + 1);
	if (y - 1 > 0 && f->frontier[y - 1][x] == ENNEMY_TERRITORY)
		ret += fill_frontier_test(f, x, y - 1);
	if (x + 1 < f->xmax && y + 1 < f->ymax &&
			f->frontier[y + 1][x + 1] == ENNEMY_TERRITORY)
		ret += fill_frontier_test(f, x + 1, y + 1);
	if (x - 1 >= 0 && y + 1 < f->ymax &&
			f->frontier[y + 1][x - 1] == ENNEMY_TERRITORY)
		ret += fill_frontier_test(f, x - 1, y + 1);
	if (x + 1 < f->xmax && y - 1 >= 0 &&
			f->frontier[y - 1][x + 1] == ENNEMY_TERRITORY)
		ret += fill_frontier_test(f, x + 1, y - 1);
	if (x - 1 >= 0 && y - 1 >= 0 &&
			f->frontier[y - 1][x - 1] == ENNEMY_TERRITORY)
		ret += fill_frontier_test(f, x - 1, y - 1);
	return (ret);
}

int16_t	fill_frontier_test(t_filler *f, int x, int y)
{
	int8_t	pre_fill;
	int16_t	ret;

	ret = 0;
	pre_fill = f->frontier[y][x];
	if (f->tab[y][x] != '.')
		f->frontier[y][x] = NEW_ENNEMY_TERRITORY;
	else if ((x - f->piece.x) >= 0 && (x - f->piece.x) < f->piece.xmax
				&& (y - f->piece.y) >= 0
				&& (y - f->piece.y) < f->piece.ymax
				&& f->piece.tab[(y - f->piece.y)][(x - f->piece.x)] == '*')
		f->frontier[y][x] = NEW_PLAYER_TERRITORY;
	else
		f->frontier[y][x] = closest_player_test(f, x, y) ^ 2;
	if (pre_fill != f->frontier[y][x] % 2)
	{
		if (f->frontier[y][x] == NEW_PLAYER_TERRITORY)
			ret++;
		ret += propagate_all_directions(f, x, y);
	}
	f->frontier[y][x] = pre_fill ^ 2;
	return (ret);
}
