/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turn.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/27 14:22:28 by tbehra            #+#    #+#             */
/*   Updated: 2018/05/27 19:09:04 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"

void	show_turn_increment(t_display_mlx *d)
{
	const char	s1[17] = "Turn increment: ";
	char		*s2;
	char		*s3;
	t_rect		*mask;

	mask = create_mask(300, 30, d->win_width / 2 - 90, d->win_height - 75);
	print_rectangle(mask, d);
	s2 = ft_itoa(d->turn_increment_nb);
	s3 = ft_strjoin(s1, s2);
	mlx_string_put(d->mlx, d->win, d->win_width / 2 - 90,
			d->win_height - 75, TEXT_COLOR, s3);
	free(s2);
	free(s3);
	free(mask);
}

void	display_dominance(t_display_mlx *d)
{
	t_rect	rect;
	int		i;
	int		w[5];

	w[0] = (int)((double)WIDTH_DOMINANCE * ((double)d->score_player /
				d->nb_sq));
	w[1] = (int)((double)WIDTH_DOMINANCE * ((double)(d->territory_player -
					d->score_player) / d->nb_sq));
	w[2] = (int)((double)WIDTH_DOMINANCE * ((double)(d->nb_sq -
					d->territory_player - d->territory_challenger) / d->nb_sq));
	w[3] = (int)((double)WIDTH_DOMINANCE * ((double)(d->territory_challenger -
					d->score_challenger) / d->nb_sq));
	w[4] = (int)((double)WIDTH_DOMINANCE * ((double)(d->score_challenger) /
				d->nb_sq));
	rect.height = HEIGHT_DOMINANCE;
	rect.coord.x = (d->win_width / 2) - (WIDTH_DOMINANCE / 2);
	rect.coord.y = Y_DOMINANCE;
	i = -1;
	while (++i < 5)
	{
		rect.color = d->col_dominance[i];
		rect.width = w[i];
		print_rectangle(&rect, d);
		rect.coord.x += rect.width;
	}
}

void	display_state_turn(t_display_mlx *d)
{
	t_point	coord;
	void	*img;
	int		r;
	int		c;

	r = -1;
	while (r++ < d->ymax - 1)
	{
		c = -1;
		while (c++ < d->xmax - 1)
		{
			if ((d->prev_tab[r][c] != d->tab[r][c]) ||
					(d->prev_frontier[r][c] != d->frontier[r][c]))
			{
				img = select_image(d, r, c);
				coord.x = (d->sq_size + 1) * c + X_FIRST_SQUARE;
				coord.y = (d->sq_size + 1) * r + Y_FIRST_SQUARE;
				mlx_put_image_to_window(d->mlx, d->win, img, coord.x, coord.y);
			}
		}
	}
	compute_and_display_scores(d);
	display_dominance(d);
	update_prev_tabs(d);
}

void	previous_turn(t_display_mlx *d)
{
	if (d->turn_nb - d->turn_increment_nb >= 1)
	{
		fseek(d->file, -(d->bytes_to_read_turn *
					(d->turn_increment_nb + 1)), SEEK_CUR);
		if (!(parse_tab_frontier(d)))
			quit_program(d);
		d->turn_nb -= d->turn_increment_nb;
		display_state_turn(d);
		mask_turn_nb(d);
		mlx_string_put(d->mlx, d->win, (d->win_width / 2) + 10,
				d->win_height - 100, TEXT_COLOR, ft_itoa(d->turn_nb));
	}
}

void	next_turn(t_display_mlx *d)
{
	long int	cur_place;

	cur_place = ftell(d->file);
	if (d->turn_increment_nb > 1)
		fseek(d->file, (d->turn_increment_nb - 1) *
				d->bytes_to_read_turn, SEEK_CUR);
	if (!(parse_tab_frontier(d)))
	{
		if (feof(d->file))
		{
			ft_printf("last turn\n");
			fseek(d->file, cur_place, SEEK_SET);
		}
		else if (ferror(d->file))
			quit_program(d);
	}
	else
	{
		d->turn_nb += d->turn_increment_nb;
		display_state_turn(d);
		mask_turn_nb(d);
		mlx_string_put(d->mlx, d->win, (d->win_width / 2) + 10,
				d->win_height - 100, TEXT_COLOR, ft_itoa(d->turn_nb));
	}
}
