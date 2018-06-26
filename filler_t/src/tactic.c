/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tactic.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 14:19:01 by tbehra            #+#    #+#             */
/*   Updated: 2018/05/24 19:16:06 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int8_t	check_star_collision(t_filler *f, int x, int y, int *nb_cover_player)
{
	if (f->piece.y + y < 0 || f->piece.y + y >= f->ymax
			|| f->piece.x + x < 0 || f->piece.x + x >= f->xmax)
		return (0);
	if (f->tab[f->piece.y + y][f->piece.x + x] == f->player)
		*nb_cover_player = *nb_cover_player + 1;
	else if (f->tab[f->piece.y + y][f->piece.x + x] != '.')
		return (0);
	return (1);
}

int8_t	check_placement(t_filler *f)
{
	int x;
	int y;
	int nb_cover_player;

	y = 0;
	nb_cover_player = 0;
	while (y < f->piece.ymax)
	{
		x = 0;
		while (x < f->piece.xmax)
		{
			if (f->piece.tab[y][x] == '*')
				if (!(check_star_collision(f, x, y, &nb_cover_player)))
					return (0);
			if (nb_cover_player > 1)
				return (0);
			x++;
		}
		y++;
	}
	return (nb_cover_player == 1);
}

int16_t	best_placement(t_filler *f, uint8_t strategy)
{
	int16_t score;

	score = 0;
	f->piece.y = -f->piece.ymax;
	while (f->piece.y <= f->ymax)
	{
		f->piece.x = -f->piece.xmax;
		while (f->piece.x <= f->xmax)
		{
			if (check_placement(f))
				if ((score = f->tactic[strategy](f)) > f->bestpos.score)
				{
					f->bestpos.score = score;
					f->bestpos.x = f->piece.x;
					f->bestpos.y = f->piece.y;
				}
			f->piece.x++;
		}
		f->piece.y++;
	}
	if (!f->bestpos.score && !strategy)
		return (best_placement(f, CHECK_CONTACT));
	return (f->bestpos.score);
}
