/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_contact.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 19:14:50 by tbehra            #+#    #+#             */
/*   Updated: 2018/05/24 19:16:21 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int16_t	contacts_four_directions(t_filler *f, int x, int y)
{
	int16_t nb_contact;

	nb_contact = 0;
	if (f->piece.y + y + 1 >= f->piece.ymax
			|| f->tab[f->piece.y + y + 1][f->piece.x + x] != '.')
		nb_contact++;
	if (f->piece.y + y - 1 < 0
			|| f->tab[f->piece.y + y - 1][f->piece.x + x] != '.')
		nb_contact++;
	if (f->piece.x + x + 1 >= f->piece.xmax
			|| f->tab[f->piece.y + y][f->piece.x + x + 1] != '.')
		nb_contact++;
	if (f->piece.x + x - 1 < 0
			|| f->tab[f->piece.y + y][f->piece.x + x - 1] != '.')
		nb_contact++;
	return (nb_contact);
}

int16_t	check_contact(t_filler *f)
{
	int x;
	int y;
	int nb_contact;

	y = 0;
	nb_contact = 0;
	while (y < f->piece.ymax)
	{
		x = 0;
		while (x < f->piece.xmax)
		{
			if (f->piece.tab[y][x] == '*')
			{
				if (f->piece.y + y < 0 || f->piece.y + y >= f->ymax
						|| f->piece.x + x < 0 || f->piece.x + x >= f->xmax)
					return (0);
				nb_contact += contacts_four_directions(f, x, y);
			}
			x++;
		}
		y++;
	}
	return (nb_contact);
}
