/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 14:18:36 by tbehra            #+#    #+#             */
/*   Updated: 2018/05/28 11:03:27 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		error(t_filler *f, int err_type)
{
	f->error = err_type;
	return (err_type);
}

void	init_turn(t_filler *f)
{
	f->piece.x = 0;
	f->piece.y = 0;
	f->bestpos.score = 0;
}

void	init_filler(t_filler *f)
{
	f->player = '\0';
	f->ennemy = '\0';
	f->error = 0;
	f->piece.tab = NULL;
	f->tab = NULL;
	f->frontier = NULL;
	f->tactic[0] = &update_frontier_test;
	f->tactic[1] = &check_contact;
	f->display = DISPLAY;
	if (f->display)
		f->fd = open("filler.disp", O_CREAT | O_WRONLY | O_TRUNC);
}

void	free_filler(t_filler *f)
{
	if (f->frontier)
		ft_tabdel((void**)f->frontier, f->ymax);
	if (f->tab)
		ft_tabdel((void**)f->tab, f->ymax);
	if (f->piece.tab)
		ft_tabdel((void**)f->piece.tab, f->piece.ymax);
}

int		main(void)
{
	char		*line;
	t_filler	f;

	init_filler(&f);
	while (1)
	{
		init_turn(&f);
		parse_tab(&f);
		if (f.error != 0)
			return (1);
		update_frontier(&f, ENNEMY_TERRITORY);
		display_frontier(&f);
		build_piece(&f);
		if (f.error != 0)
			return (1);
		if (!(best_placement(&f, 0)))
			break ;
		ft_printf("%i %i\n", f.bestpos.y, f.bestpos.x);
		update_frontier(&f, PLAYER_TERRITORY);
		while (get_next_line(0, &line) == 0)
			;
		ft_strdel(&line);
	}
	free_filler(&f);
	return (0);
}
