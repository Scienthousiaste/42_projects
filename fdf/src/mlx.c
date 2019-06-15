/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/24 13:35:23 by tbehra            #+#    #+#             */
/*   Updated: 2018/06/25 16:18:31 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	quit_program(t_fdf *fdf)
{
	int r;

	r = -1;
	close(fdf->fd);
	while (++r < fdf->row)
		free(fdf->map[r]);
	free(fdf->map);
	mlx_destroy_window(fdf->mlx, fdf->win);
	exit(0);
}

void	deal_key_letter(int key, t_fdf *fdf, int *refresh)
{
	if (key == KEY_Z && (*refresh = REFRESH))
		fdf->sz += SCZ_INC * fdf->polarity;
	if (key == KEY_Y && (*refresh = REFRESH))
		fdf->sy += SC_INC * fdf->polarity;
	if (key == KEY_X && (*refresh = REFRESH))
		fdf->sx += SC_INC * fdf->polarity;
	if (key == KEY_A && (*refresh = RECOMPUTE_MATRIX))
		fdf->alpha_deg += ANGLE_INC * fdf->polarity;
	if (key == KEY_B && (*refresh = RECOMPUTE_MATRIX))
		fdf->beta_deg += ANGLE_INC * fdf->polarity;
	if (key == KEY_D)
		dump_vars(fdf);
	if (key == KEY_I)
		fdf->polarity = -fdf->polarity;
	if (key == KEY_G && (*refresh = REFRESH))
		fdf->print_green = !fdf->print_green;
}

int		deal_key(int key, void *param)
{
	t_fdf	*fdf;
	int		refresh;

	refresh = 0;
	fdf = (t_fdf*)param;
	if (key == ESC_KEY)
		quit_program(fdf);
	if (key == LEFT_ARROW_KEY && (refresh = REFRESH))
		fdf->scale_x -= MOVE_AMT;
	if (key == RIGHT_ARROW_KEY && (refresh = REFRESH))
		fdf->scale_x += MOVE_AMT;
	if (key == DOWN_ARROW_KEY && (refresh = REFRESH))
		fdf->scale_y += MOVE_AMT;
	if (key == UP_ARROW_KEY && (refresh = REFRESH))
		fdf->scale_y -= MOVE_AMT;
	if (key >= KEY_A && key <= KEY_I)
		deal_key_letter(key, fdf, &refresh);
	if (refresh)
		refresh_screen(fdf, refresh);
	return (0);
}

t_point	*make_point(int x, int y)
{
	t_point *ret;

	if (!(ret = (t_point*)malloc(sizeof(t_point))))
		error(MALLOC_ERROR);
	ret->x = x;
	ret->y = y;
	return (ret);
}

void	launch_mlx(t_fdf *fdf)
{
	fdf->mlx = mlx_init();
	fdf->win = mlx_new_window(fdf->mlx, WIN_WIDTH, WIN_HEIGHT, WIN_TITLE);
	fdf->center_win.x = WIN_WIDTH / 2;
	fdf->center_win.y = WIN_HEIGHT / 2;
	generate_images(fdf);
}
