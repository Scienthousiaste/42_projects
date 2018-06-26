/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 19:06:54 by tbehra            #+#    #+#             */
/*   Updated: 2018/05/28 12:44:46 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		init_tab(t_filler *f)
{
	int i;

	if (!(f->tab))
	{
		if (!(f->tab = (char**)malloc(sizeof(char*) * f->ymax)))
			return (error(f, ERROR_MALLOC));
		i = -1;
		while (++i < f->ymax)
			if (!(f->tab[i] = (char*)malloc(sizeof(char) * f->xmax + 1)))
				return (error(f, ERROR_MALLOC));
	}
	return (0);
}

int		parse_row(t_filler *f, int row_number)
{
	char **split_line;
	char *line;

	if (get_next_line(0, &line) != 1)
		return (0);
	if (!(split_line = ft_strsplit(line, ' ')))
		return (0);
	ft_strdel(&line);
	if (!(split_line[0] && split_line[1]))
		return (0);
	if (ft_atoi(split_line[0]) != row_number)
		return (0);
	if ((int)ft_strlen(split_line[1]) != f->xmax)
		return (0);
	ft_strcpy(f->tab[row_number], split_line[1]);
	ft_tabdel((void**)split_line, 2);
	return (1);
}

int		two_players_present(t_filler *f)
{
	int x;
	int y;
	int x_present;
	int o_present;

	x_present = 0;
	o_present = 0;
	y = RESET_COUNT;
	while (++y < f->ymax)
	{
		x = RESET_COUNT;
		while (++x < f->xmax)
		{
			if (f->tab[y][x] == 'X')
				x_present = 1;
			if (f->tab[y][x] == 'O')
				o_present = 1;
			if (x_present && o_present)
				return (1);
		}
	}
	return (0);
}

int		parse_tab(t_filler *f)
{
	int		row;
	char	*line;

	if (!f->player)
		parse_first_time(f);
	if (f->error)
		return (f->error);
	get_next_line(0, &line);
	ft_strdel(&line);
	row = RESET_COUNT;
	while (++row < f->ymax)
	{
		if (!(parse_row(f, row)))
			return (error(f, ERROR_BAD_INPUT));
	}
	if (!(two_players_present(f)))
		return (error(f, ERROR_BAD_INPUT));
	if (f->display)
		parse_tab_display(f);
	if (!f->frontier)
		set_frontier(f);
	return (0);
}
