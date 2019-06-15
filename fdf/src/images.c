/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 20:41:29 by tbehra            #+#    #+#             */
/*   Updated: 2018/06/26 13:38:35 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fill_img(void *img_to_fill, int color)
{
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	int		pos;
	char	*img;

	img = mlx_get_data_addr(img_to_fill,
			&bits_per_pixel, &size_line, &endian);
	pos = 0;
	while (pos < (size_line * WIN_HEIGHT))
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

void	generate_images(t_fdf *fdf)
{
	fdf->img_clear = mlx_new_image(fdf->mlx, WIN_WIDTH, WIN_HEIGHT);
	fill_img(fdf->img_clear, BLACK);
}
