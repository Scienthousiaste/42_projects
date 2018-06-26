/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 15:36:00 by tbehra            #+#    #+#             */
/*   Updated: 2018/05/28 10:59:57 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		parse_before_piece(t_filler *f)
{
	char	*pos;
	char	*line;

	if (f->piece.tab)
		ft_tabdel((void**)f->piece.tab, f->piece.ymax);
	if (get_next_line(0, &line) != 1)
		return (0);
	if (ft_strncmp(line, "Piece ", 6) != 0)
		return (0);
	pos = ft_strchr(line, ' ') + 1;
	if (!(ft_isdigit(*pos)))
		return (0);
	f->piece.ymax = ft_atoi(pos);
	pos = ft_strchr(pos, ' ') + 1;
	if (!(ft_isdigit(*pos)))
		return (0);
	f->piece.xmax = ft_atoi(pos);
	ft_strdel(&line);
	return (1);
}

int		build_piece(t_filler *f)
{
	int		r;
	char	*line;

	if (!(parse_before_piece(f)))
		return (error(f, ERROR_BAD_INPUT));
	if (!(f->piece.tab = (char**)malloc(sizeof(char*) * f->piece.ymax)))
		return (error(f, ERROR_MALLOC));
	r = -1;
	while (++r < f->piece.ymax)
	{
		if (!(f->piece.tab[r] =
					(char*)malloc(sizeof(char) * f->piece.xmax + 1)))
			return (error(f, ERROR_MALLOC));
		if (get_next_line(0, &line) != 1)
			return (error(f, ERROR_BAD_INPUT));
		ft_strcpy(f->piece.tab[r], line);
		ft_strdel(&line);
		if (!((int)ft_strlen(f->piece.tab[r]) == f->piece.xmax))
			return (error(f, ERROR_BAD_INPUT));
	}
	return (0);
}

int		check_plateau_line(t_filler *f, char *line)
{
	char **plateau_line;

	if (!(plateau_line = ft_strsplit(line, ' ')))
		return (1);
	ft_strdel(&line);
	if (!(plateau_line[1] && plateau_line[2]))
		return (1);
	if (!(ft_isdigit(plateau_line[1][0])))
		return (1);
	f->ymax = ft_atoi(plateau_line[1]);
	if (!(ft_isdigit(plateau_line[2][0])))
		return (1);
	f->xmax = ft_atoi(plateau_line[2]);
	if (f->ymax < 1 || f->xmax < 1 || !(f->ymax >= 2 || f->xmax >= 2))
		return (1);
	ft_tabdel((void**)plateau_line, 3);
	return (0);
}

int		parse_first_time(t_filler *f)
{
	char *line;

	if ((get_next_line(0, &line) != 1))
		return (error(f, ERROR_BAD_INPUT));
	if (ft_strncmp("$$$ exec p1", line, 11) == 0)
		f->player = 'O';
	else if (ft_strncmp("$$$ exec p2", line, 11) == 0)
		f->player = 'X';
	else
		return (error(f, ERROR_BAD_INPUT));
	ft_strdel(&line);
	if ((get_next_line(0, &line) != 1))
		return (error(f, ERROR_BAD_INPUT));
	if (ft_strncmp("Plateau ", line, 8) == 0)
	{
		if (check_plateau_line(f, line) != 0)
			return (error(f, ERROR_BAD_INPUT));
	}
	else
		return (error(f, ERROR_BAD_INPUT));
	init_tab(f);
	if (f->display)
		parse_first_time_display(f);
	return (0);
}
