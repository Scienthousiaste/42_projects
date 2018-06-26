/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_display.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 19:42:54 by tbehra            #+#    #+#             */
/*   Updated: 2018/05/27 18:57:41 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"

void	compute_sq_size(t_display_mlx *d)
{
	if (((d->xmax + 1) * BIG_SQ_SIZE < X_TAB_MAX) &&
		((d->ymax + 1) * BIG_SQ_SIZE < Y_TAB_MAX))
		d->sq_size = BIG_SQ_SIZE;
	else if (((d->xmax + 1) * MEDIUM_SQ_SIZE < X_TAB_MAX) &&
		((d->ymax + 1) * MEDIUM_SQ_SIZE < Y_TAB_MAX))
		d->sq_size = MEDIUM_SQ_SIZE;
	else
		d->sq_size = SMALL_SQ_SIZE;
}

void	open_window(t_display_mlx *d)
{
	d->win_width = (d->sq_size + 1) * d->xmax + X_FIRST_SQUARE * 2;
	d->win_height = (d->sq_size + 1) * d->ymax + Y_FIRST_SQUARE + 150;
	ft_printf("width : %d, height : %d\n", d->win_width, d->win_height);
	d->win = mlx_new_window(d->mlx, d->win_width, d->win_height, WIN_TITLE);
	d->nb_sq = (double)(d->xmax * d->ymax);
}

void	display_top_panel(t_display_mlx *d)
{
	int	x_turn;
	int y_turn;

	x_turn = d->win_width / 2 - 40;
	y_turn = d->win_height - 100;
	mlx_string_put(d->mlx, d->win,
			X_PLAYER_NAME, Y_PLAYER_NAME, PLAYER_COLOR, "tbehra.filler");
	mlx_string_put(d->mlx, d->win,
			X_PLAYER_NAME, Y_PLAYER_NAME + 20, TEXT_COLOR, "Score:");
	mlx_string_put(d->mlx, d->win,
			X_PLAYER_NAME, Y_PLAYER_NAME + 40, TEXT_COLOR, "Territory:");
	mlx_string_put(d->mlx, d->win,
			d->win_width - 200, Y_PLAYER_NAME, CHALLENGER_COLOR, "Challenger");
	mlx_string_put(d->mlx, d->win,
			d->win_width - 200, Y_PLAYER_NAME + 20, TEXT_COLOR, "Score:");
	mlx_string_put(d->mlx, d->win,
			d->win_width - 200, Y_PLAYER_NAME + 40, TEXT_COLOR, "Territory:");
	mlx_string_put(d->mlx, d->win, x_turn, y_turn, TEXT_COLOR, "Turn");
	mlx_string_put(d->mlx, d->win, x_turn + 50, y_turn,
			TEXT_COLOR, ft_itoa(d->turn_nb));
}

void	init_display(t_display_mlx *d)
{
	rewind(d->file);
	fseek(d->file, d->begin_turn_one + d->bytes_to_read_turn, SEEK_SET);
	d->turn_nb = 1;
	d->turn_increment_nb = 1;
	d->mlx = mlx_init();
	compute_sq_size(d);
	generate_images(d);
	open_window(d);
	display_top_panel(d);
	d->col_dominance[0] = PLAYER_COLOR;
	d->col_dominance[1] = PLAYER_TERRITORY_COLOR;
	d->col_dominance[2] = FRONTIER_COLOR;
	d->col_dominance[3] = CHALLENGER_TERRITORY_COLOR;
	d->col_dominance[4] = CHALLENGER_COLOR;
}

int		main(int ac, char **av)
{
	t_display_mlx	d;

	if (ac < 2)
	{
		if (!(d.file = fopen("filler.disp", "rb")))
			return (usage());
	}
	else if (!(d.file = fopen(av[1], "rb")))
		return (usage());
	d.begin_turn_one = 0;
	d.bytes_to_read_turn = 0;
	if (!(parse_map_params(&d)))
		quit_program(&d);
	if (!(first_parse_tab_frontier(&d)))
		quit_program(&d);
	init_display(&d);
	mlx_key_hook(d.win, &deal_key, &d);
	mlx_loop(d.mlx);
	return (0);
}
