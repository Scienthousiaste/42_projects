/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 13:38:19 by tbehra            #+#    #+#             */
/*   Updated: 2018/05/27 18:58:40 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"

void	free_tab_content(void **tab, int max)
{
	int i;

	if (tab)
	{
		i = 0;
		while (i < max)
		{
			free(tab[i]);
			i++;
		}
	}
}

int		parse_frontier(t_display_mlx *d, char *buf)
{
	int		r;
	int		pos;
	char	*line;

	r = -1;
	pos = d->ymax * (d->xmax + 1) + 1;
	while (++r < d->ymax)
	{
		line = ft_strsub(buf, pos, d->xmax);
		if (ft_strchr(line, '\n'))
			return (0);
		pos += d->xmax + 1;
		ft_strcpy(d->frontier[r], line);
		free(line);
	}
	return (1);
}

int		parse_tab(t_display_mlx *d, char *buf)
{
	int		r;
	int		pos;
	char	*line;

	r = -1;
	pos = 0;
	while (++r < d->ymax)
	{
		line = ft_strsub(buf, pos, d->xmax);
		if (ft_strchr(line, '\n'))
			return (0);
		pos += d->xmax + 1;
		ft_strcpy(d->tab[r], line);
		free(line);
	}
	return (1);
}

int		parse_tab_frontier(t_display_mlx *d)
{
	char	*buf;

	buf = (char*)malloc(d->bytes_to_read_turn + 1);
	buf[d->bytes_to_read_turn] = '\0';
	fread(buf, 1, d->bytes_to_read_turn, d->file);
	if (feof(d->file))
		return (0);
	if (!(parse_tab(d, buf)))
		return (error(PARSING_ERROR));
	if (!(parse_frontier(d, buf)))
		return (error(PARSING_ERROR));
	free(buf);
	return (1);
}
