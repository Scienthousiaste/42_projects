/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 13:39:07 by tbehra            #+#    #+#             */
/*   Updated: 2018/07/24 15:27:56 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fill_img(void *img_to_fill, int color, t_display *d)
{
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	int		pos;
	char	*img;

	img = mlx_get_data_addr(img_to_fill,
			&bits_per_pixel, &size_line, &endian);
	pos = 0;
	while (pos < (size_line * d->win_height))
	{
		if (pos % 4 == 0)
			img[pos] = (char)(color & 0xFF);
		else if (pos % 4 == 1)
			img[pos] = (char)(color >> 8 & 0xFF);
		else if (pos % 4 == 2)
			img[pos] = (char)(color >> 16 & 0xFF);
		else if (pos % 4 == 3)
			img[pos] = 0x0;
		pos++;
	}
}

void	image_put_pixel(t_display *d, int x, int y, int color)
{
	int	pos;

	pos = (y * d->size_line + x * sizeof(int));
	*(d->img_ptr + pos) = (char)(color & 0xFF);
	*(d->img_ptr + pos + 1) = (char)(color >> 8 & 0xFF);
	*(d->img_ptr + pos + 2) = (char)(color >> 16 & 0xFF);
	*(d->img_ptr + pos + 3) = (char)0x0;
}
