/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_scores.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/27 11:51:23 by tbehra            #+#    #+#             */
/*   Updated: 2018/05/27 18:50:42 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"

int		count_tab(char **tab, char count_char, t_display_mlx *d)
{
	int r;
	int c;
	int ret;

	ret = 0;
	r = -1;
	while (++r < d->ymax)
	{
		c = -1;
		while (++c < d->xmax)
		{
			if (tab[r][c] == count_char)
				ret++;
		}
	}
	return (ret);
}

void	mask_turn_nb(t_display_mlx *d)
{
	t_rect mask;

	mask.width = 300;
	mask.height = 25;
	mask.color = BLACK;
	mask.coord.x = d->win_width / 2 + 10;
	mask.coord.y = d->win_height - 100;
	print_rectangle(&mask, d);
}

t_rect	*create_mask(int w, int h, int x, int y)
{
	t_rect *mask;

	mask = (t_rect*)malloc(sizeof(t_rect));
	mask->width = w;
	mask->height = h;
	mask->color = BLACK;
	mask->coord.x = x;
	mask->coord.y = y;
	return (mask);
}

void	mask_scores_nb(t_display_mlx *d)
{
	t_rect		*mask;
	int			i;
	const int	v[16] = {
		WIDTH_MASK, HEIGHT_MASK, X_SCORE_PLAYER, Y_SCORE_PLAYER,
		WIDTH_MASK, HEIGHT_MASK, X_SCORE_PLAYER, Y_TERRITORY_PLAYER,
		WIDTH_MASK, HEIGHT_MASK, (d->win_width - 95), Y_SCORE_PLAYER,
		WIDTH_MASK, HEIGHT_MASK, (d->win_width - 95), Y_TERRITORY_PLAYER};

	i = 0;
	while (i < 4)
	{
		mask = create_mask(v[i * 4], v[i * 4 + 1], v[i * 4 + 2], v[i * 4 + 3]);
		print_rectangle(mask, d);
		free(mask);
		i++;
	}
}

void	compute_and_display_scores(t_display_mlx *d)
{
	d->score_player = count_tab(d->tab, (d->player == 1) ? 'O' : 'X', d);
	d->score_challenger = count_tab(d->tab, (d->player == 1) ? 'X' : 'O', d);
	d->territory_player = count_tab(d->frontier, '1', d);
	d->territory_challenger = count_tab(d->frontier, '2', d);
	mask_scores_nb(d);
	mlx_string_put(d->mlx, d->win, X_SCORE_PLAYER,
			Y_SCORE_PLAYER, TEXT_COLOR, ft_itoa(d->score_player));
	mlx_string_put(d->mlx, d->win, X_SCORE_PLAYER,
			Y_TERRITORY_PLAYER, TEXT_COLOR, ft_itoa(d->territory_player));
	mlx_string_put(d->mlx, d->win, (d->win_width - 95),
			Y_SCORE_PLAYER, TEXT_COLOR, ft_itoa(d->score_challenger));
	mlx_string_put(d->mlx, d->win, (d->win_width - 95),
			Y_TERRITORY_PLAYER, TEXT_COLOR, ft_itoa(d->territory_challenger));
}
