/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 16:02:25 by tbehra            #+#    #+#             */
/*   Updated: 2018/06/25 16:13:44 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	vertical_line(t_fdf *fdf, t_point *start, int y_end, int color)
{
	int y;
	int end;
	int x;

	x = start->x;
	y = (start->y <= y_end) ? start->y : y_end;
	end = (start->y <= y_end) ? y_end : start->y;
	while (y < end)
		mlx_pixel_put(fdf->mlx, fdf->win, x, y++, color);
	return (1);
}

int	line_x_inc(t_fdf *fdf, t_point *start, t_point *end, int color)
{
	int		dx;
	int		dy;
	int		diff;
	int		yi;
	t_point	p;

	dx = end->x - start->x;
	dy = end->y - start->y;
	yi = (dy < 0) ? -1 : 1;
	dy = (dy < 0) ? -dy : dy;
	diff = 2 * dy - dx;
	p.x = start->x;
	p.y = start->y;
	while (p.x <= end->x)
	{
		mlx_pixel_put(fdf->mlx, fdf->win, p.x, p.y, color);
		if (diff > 0)
		{
			p.y += yi;
			diff -= 2 * dx;
		}
		diff += 2 * dy;
		p.x++;
	}
	return (1);
}

int	line_y_inc(t_fdf *fdf, t_point *start, t_point *end, int color)
{
	int		dx;
	int		dy;
	int		diff;
	int		xi;
	t_point p;

	dx = end->x - start->x;
	dy = end->y - start->y;
	xi = (dx < 0) ? -1 : 1;
	dx = (dx < 0) ? -dx : dx;
	diff = 2 * dy - dx;
	p.x = start->x;
	p.y = start->y;
	while (p.y <= end->y)
	{
		mlx_pixel_put(fdf->mlx, fdf->win, p.x, p.y, color);
		if (diff > 0)
		{
			p.x += xi;
			diff -= 2 * dy;
		}
		diff += 2 * dx;
		p.y++;
	}
	return (1);
}

int	trace_line(t_fdf *fdf, t_point *start, t_point *end, int color)
{
	int	dx;
	int dy;

	dx = end->x - start->x;
	if (dx == 0)
		return (vertical_line(fdf, start, end->y, color));
	dy = end->y - start->y;
	if ((dy / dx) >= 1)
	{
		if (dy < 0)
			return (line_y_inc(fdf, end, start, color));
		else
			return (line_y_inc(fdf, start, end, color));
	}
	else if ((dy / dx) <= -1)
	{
		if (dx < 0)
			return (line_y_inc(fdf, start, end, color));
		else
			return (line_y_inc(fdf, end, start, color));
	}
	else if (dx < 0)
		return (line_x_inc(fdf, end, start, color));
	return (line_x_inc(fdf, start, end, color));
}
