/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 20:46:39 by tbehra            #+#    #+#             */
/*   Updated: 2018/06/25 15:55:12 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	refresh_screen(t_fdf *fdf, int opt)
{
	if (opt & RECOMPUTE_MATRIX)
		build_rotation_matrix(fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img_clear, 0, 0);
	projection_link(fdf);
}

void	dump_vars(t_fdf *fdf)
{
	ft_printf("row = %d\ncol = %d\nalpha_deg = %d\nbeta_deg = %d\n",
			fdf->row, fdf->col, fdf->alpha_deg, fdf->beta_deg);
	ft_printf("sx = %d\nsy = %d\nsz = %d\nscale_x = %d\nscale_y = %d\n",
			fdf->sx, fdf->sy, fdf->sz, fdf->scale_x, fdf->scale_y);
}

int		find_val(t_fdf *fdf, t_vertex *v, int x_or_y)
{
	t_point	*p;
	int		ret;

	p = fdf->project(fdf, v);
	ret = (x_or_y == 0) ? p->x : p->y;
	free(p);
	return (ret);
}

void	find_display_params(t_fdf *fdf, t_point *min, t_point *max)
{
	while (max->x > (WIN_WIDTH - MARGIN_W) || max->y > (WIN_HEIGHT - MARGIN_H)
			|| (min->x < MARGIN_W) || (min->y < MARGIN_H))
	{
		min->x = find_val(fdf, make_vertex(0, fdf->row - 1, 0), 0);
		min->y = find_val(fdf, make_vertex(0, 0, 0), 1);
		max->x = find_val(fdf, make_vertex(fdf->col - 1, 0, 0), 0);
		max->y = find_val(fdf, make_vertex(fdf->col - 1, fdf->row - 1, 0), 1);
		if (max->x > (WIN_WIDTH - MARGIN_W))
			fdf->sx--;
		if (max->y > (WIN_HEIGHT - MARGIN_H))
			fdf->sy--;
		if (min->x < MARGIN_W)
			fdf->scale_x++;
		if (min->y < MARGIN_H)
			fdf->scale_y++;
	}
	free(min);
	free(max);
}

void	init_display_params(t_fdf *fdf)
{
	int		max_x;
	int		max_y;
	int		min_x;
	int		min_y;

	fdf->sz = 10;
	fdf->polarity = 1;
	build_rotation_matrix(fdf);
	fdf->sx = 500;
	fdf->sy = 500;
	fdf->scale_x = 100;
	fdf->scale_y = 50;
	fdf->print_green = 0;
	max_x = WIN_WIDTH + 1;
	max_y = WIN_HEIGHT + 1;
	min_x = -1;
	min_y = -1;
	find_display_params(fdf, make_point(min_x, min_y),
			make_point(max_x, max_y));
}
