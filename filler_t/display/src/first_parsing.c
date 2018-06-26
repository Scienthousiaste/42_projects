/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 20:02:52 by tbehra            #+#    #+#             */
/*   Updated: 2018/05/27 19:00:56 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"

int		error(int err_type)
{
	char *err_m[2];

	err_m[0] = "Parsing error: the filler trace file is incorrect/corrupted.\n";
	err_m[1] = "Malloc error: problem during a malloc.\n";
	ft_putstr(err_m[err_type]);
	return (0);
}

char	**first_parse_tab(t_display_mlx *d)
{
	char	*line;
	char	**ret;
	int		r;

	r = -1;
	if (!(ret = (char**)malloc(sizeof(char*) * d->ymax)))
		return (0);
	while (++r < d->ymax)
	{
		if (get_next_line(fileno(d->file), &line) != 1)
			return (0);
		if ((int)ft_strlen(line) != d->xmax)
			return (0);
		if (!(ret[r] = ft_strnew(d->xmax)))
			return (0);
		ft_strcpy(ret[r], line);
		d->bytes_to_read_turn += d->xmax + 1;
		ft_strdel(&line);
	}
	return (ret);
}

int		first_parse_tab_frontier(t_display_mlx *d)
{
	char	*line;
	int		r;

	if (!(d->tab = first_parse_tab(d)))
		return (error(PARSING_ERROR));
	if (get_next_line(fileno(d->file), &line) != 1)
		return (error(PARSING_ERROR));
	d->bytes_to_read_turn++;
	ft_strdel(&line);
	if (!(d->frontier = first_parse_tab(d)))
		return (error(PARSING_ERROR));
	if (get_next_line(fileno(d->file), &line) != 1)
		return (error(PARSING_ERROR));
	d->bytes_to_read_turn++;
	ft_strdel(&line);
	if ((!(d->prev_tab = (char**)malloc(sizeof(char*) * d->ymax))) ||
		(!(d->prev_frontier = (char**)malloc(sizeof(char*) * d->ymax))))
		return (error(MALLOC_ERROR));
	r = -1;
	while (++r < d->ymax)
		if ((!(d->prev_tab[r] = ft_strnew(d->xmax))) ||
			(!(d->prev_frontier[r] = ft_strnew(d->xmax))))
			return (error(MALLOC_ERROR));
	return (1);
}

int		parse_map_params(t_display_mlx *d)
{
	char *line;

	if (get_next_line(fileno(d->file), &line) != 1)
		return (error(PARSING_ERROR));
	d->player = (line[0] == 'O') ? 1 : 2;
	d->begin_turn_one += ft_strlen(line) + 1;
	ft_strdel(&line);
	if (get_next_line(fileno(d->file), &line) != 1)
		return (error(PARSING_ERROR));
	if (!(ft_isdigit(line[0])))
		return (error(PARSING_ERROR));
	d->ymax = ft_atoi(line);
	d->begin_turn_one += ft_strlen(line) + 1;
	ft_strdel(&line);
	if (get_next_line(fileno(d->file), &line) != 1)
		return (error(PARSING_ERROR));
	d->xmax = ft_atoi(line);
	d->begin_turn_one += ft_strlen(line) + 1;
	ft_strdel(&line);
	return (1);
}
