/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 15:52:10 by tbehra            #+#    #+#             */
/*   Updated: 2018/07/24 20:13:31 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		find_color(t_display *d, int n_div)
{
	return (d->color_palette[(n_div - 1) % N_COLOR]);
}

void	build_color_palette(t_display *d)
{
	const int	tab_color[N_COLOR] = {MARINE_BLUE, BLUE_2, ROYAL_BLUE,
		DODGER_BLUE, DEEP_SKY_BLUE, TURQUOISE, SPRING_GREEN, GREEN_YELLOW,
		YELLOW, ORANGE, REDDISH, ALMOST_RED, RED_2, RED_3, RED_4, RED_5,
		RED_6, RED_7};
	int			i;

	i = -1;
	while (++i < N_COLOR)
	{
		d->color_palette[i] = tab_color[i];
	}
}

#define MAX_SHADE 0.25

void	color_shading(t_display *d)
{
	int			x;
	int			y;
	t_complex	center;
	double		dist;
	double		shade_factor;

	int new_col;

	new_col = 0;
	center.re = d->win_width / 2;
	center.im = d->win_height / 2;
	y = -1;
	while (++y < d->win_height)
	{
		x = -1;
		while (++x < d->win_width)
		{
			dist = modulus(c_init(((double)x - center.re / d->win_width),
						((double)y - center.im)/ d->win_height));
			shade_factor = 1 - MAX_SHADE *(dist / modulus(c_init(0, 0)));
			new_col |= (int)(((double)(d->map[y][x].color & 0xFF)) * shade_factor);
			new_col |= (int)(((double)(d->map[y][x].color & 0xFF00)) * shade_factor);
			new_col |= (int)(((double)(d->map[y][x].color & 0xFF0000)) * shade_factor);
			d->map[y][x].color = new_col;
			if (y == 300)
			{
				ft_putnbr(new_col);
				ft_putendl("");
			}
			image_put_pixel(d, x, y, new_col);
		}
	}
	mlx_put_image_to_window(d->mlx, d->win, d->img, 0, 0);
}

void	build_monochrome_palette(t_display *d, unsigned int mask_color)
{
	int				i;
	unsigned int	color_inc;

	if (mask_color == MASK_RED)
		color_inc = ((0xFF - 0x11) / N_COLOR) << 16;
	else if (mask_color == MASK_GREEN)
		color_inc = ((0xFF - 0x11) / N_COLOR) << 8;
	else if (mask_color == MASK_BLUE)
		color_inc = ((0xFF - 0x11) / N_COLOR);
	else if (mask_color == MASK_GRAY)
		color_inc = ((0xFF - 0x11) / N_COLOR) |
			(((0xFF - 0x11) / N_COLOR) << 8) |
			(((0xFF - 0x11) / N_COLOR) << 16);
	i = -1;
	while (++i < N_COLOR)
	{
		d->color_palette[i] = mask_color + color_inc * i;
	}
}
