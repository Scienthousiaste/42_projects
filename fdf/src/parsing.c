/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 15:34:41 by tbehra            #+#    #+#             */
/*   Updated: 2018/06/25 16:37:40 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		tablen(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

void	realloc_map(t_fdf *fdf)
{
	int	*new_map;
	int	old_size_map;
	int i;

	old_size_map = fdf->size_map_1d;
	fdf->size_map_1d *= 2;
	i = 0;
	if (!(new_map = (int*)malloc(sizeof(int) * fdf->size_map_1d)))
		error(MALLOC_ERROR);
	while (i < fdf->size_map_1d)
	{
		if (i < old_size_map)
			new_map[i] = fdf->map_1d[i];
		else
			new_map[i] = 0;
		i++;
	}
	free(fdf->map_1d);
	fdf->map_1d = new_map;
}

int		get_number(char *s, t_fdf *fdf)
{
	char *itoa_string;

	if ((s[0] == '-' && ft_isdigit(s[1])) || ft_isdigit(s[0]))
	{
		if (fdf->i_map < fdf->size_map_1d)
		{
			fdf->map_1d[fdf->i_map] = ft_atoi(s);
			itoa_string = ft_itoa(fdf->map_1d[fdf->i_map]);
			if (ft_strcmp(itoa_string, s))
				error(WRONG_NUMBER_ERROR);
			free(itoa_string);
			fdf->i_map++;
		}
		else
			realloc_map(fdf);
		return (1);
	}
	return (0);
}

void	reorganize_map(t_fdf *fdf)
{
	int i;
	int j;

	fdf->i_map = 0;
	if (!(fdf->map = (int**)malloc(sizeof(int*) * fdf->row)))
		error(MALLOC_ERROR);
	j = -1;
	while (++j < fdf->row)
	{
		if (!(fdf->map[j] = (int*)malloc(sizeof(int) * fdf->col)))
			error(MALLOC_ERROR);
		i = -1;
		while (++i < fdf->col)
			fdf->map[j][i] = fdf->map_1d[fdf->i_map++];
	}
	free(fdf->map_1d);
}

void	parse_map(t_fdf *fdf)
{
	char	*line;
	char	**tab_split;
	int		split_len;

	while ((fdf->ret_gnl = get_next_line(fdf->fd, &line)))
	{
		if (fdf->ret_gnl == -1)
			error(GNL_ERROR);
		tab_split = ft_strsplit(line, ' ');
		split_len = 0;
		while (tab_split[split_len])
			if (!(get_number(tab_split[split_len++], fdf)))
				error(NAN_ERROR);
		if (fdf->col == -1)
			fdf->col = split_len;
		else if (fdf->col != split_len)
			error(INCONSISTENT_SIZE);
		ft_strdel(&line);
		ft_tabdel((void**)tab_split, split_len + 1);
		fdf->row++;
	}
	if (fdf->row == 0)
		error(EMPTY_ERROR);
	ft_strdel(&line);
}
