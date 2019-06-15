/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 17:15:30 by tbehra            #+#    #+#             */
/*   Updated: 2018/06/29 16:15:29 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_vertex	*make_vertex(int x, int y, int z)
{
	t_vertex	*ret;

	if (!(ret = (t_vertex*)malloc(sizeof(t_vertex))))
		error(MALLOC_ERROR);
	ret->x = x;
	ret->y = y;
	ret->z = z;
	return (ret);
}

t_point		*isometric_projection(t_fdf *fdf, t_vertex *v)
{
	double x;
	double y;

	x = fdf->scale_x + fdf->sx * v->x * fdf->rotation_matrix[0][0]
		+ fdf->sy * v->y * fdf->rotation_matrix[0][2];
	y = fdf->scale_y + fdf->sx * v->x * fdf->rotation_matrix[1][0]
		+ fdf->sz * -v->z * fdf->rotation_matrix[1][1]
		+ fdf->sy * v->y * fdf->rotation_matrix[1][2];
	free(v);
	return (make_point((int)x, (int)y));
}

void		projection(t_fdf *fdf)
{
	t_point *tmp;
	int		r;
	int		c;

	r = -1;
	while (++r < fdf->row)
	{
		c = -1;
		while (++c < fdf->col)
		{
			tmp = fdf->project(fdf, make_vertex(c, r, fdf->map[r][c]));
			mlx_pixel_put(fdf->mlx, fdf->win, tmp->x, tmp->y, WHITE);
			free(tmp);
		}
	}
}

int			find_color(t_fdf *fdf, int zs, int ze)
{
	if (fdf->print_green)
		return (GREEN);
	if (zs == ze)
	{
		if (zs == 0)
			return (GREEN);
		else if (zs < 0)
			return (BLUE);
		else
			return (WHITE);
	}
	return (RED);
}

void		projection_link(t_fdf *fdf)
{
	t_point *tmp;
	t_point *t;
	int		r;
	int		c;

	r = -1;
	t = NULL;
	while (++r < fdf->row && (c = -1))
		while (++c < fdf->col)
		{
			tmp = fdf->project(fdf, make_vertex(c, r, fdf->map[r][c]));
			if (c < fdf->col - 1 && (t = fdf->project(fdf,
				make_vertex(c + 1, r, fdf->map[r][c + 1]))))
				trace_line(fdf, tmp, t,
					find_color(fdf, fdf->map[r][c], fdf->map[r][c + 1]));
			if (t)
				ft_memdel((void**)&t);
			if (r < fdf->row - 1 && (t = fdf->project(fdf,
				make_vertex(c, r + 1, fdf->map[r + 1][c]))))
				trace_line(fdf, tmp, t,
					find_color(fdf, fdf->map[r][c], fdf->map[r + 1][c]));
			if (t)
				ft_memdel((void**)&t);
			free(tmp);
		}
}
