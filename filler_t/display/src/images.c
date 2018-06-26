/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/27 12:28:56 by tbehra            #+#    #+#             */
/*   Updated: 2018/06/23 21:18:25 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"

void	*select_image(t_display_mlx *d, int row, int col)
{
	if (((d->tab[row][col] == 'O') && (d->player == 1))
			|| ((d->tab[row][col] == 'X') && (d->player == 2)))
		return (d->image_player);
	else if (d->tab[row][col] != '.')
		return (d->image_challenger);
	if (d->frontier[row][col] == '0')
		return (d->image_frontier);
	if (d->frontier[row][col] == '1')
		return (d->image_t_player);
	return (d->image_t_challenger);
}

void	fill_img(t_display_mlx *d, void *img_to_fill, int color)
{
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	int		pos;
	char	*img;

	img = mlx_get_data_addr(img_to_fill,
			&bits_per_pixel, &size_line, &endian);
	pos = 0;
	while (pos < (size_line * d->sq_size))
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

void	generate_images(t_display_mlx *d)
{
	d->image_player = mlx_new_image(d->mlx, d->sq_size, d->sq_size);
	d->image_t_player = mlx_new_image(d->mlx, d->sq_size, d->sq_size);
	d->image_challenger = mlx_new_image(d->mlx, d->sq_size, d->sq_size);
	d->image_t_challenger = mlx_new_image(d->mlx, d->sq_size, d->sq_size);
	d->image_frontier = mlx_new_image(d->mlx, d->sq_size, d->sq_size);
	fill_img(d, d->image_player, PLAYER_COLOR);
	fill_img(d, d->image_t_player, PLAYER_TERRITORY_COLOR);
	fill_img(d, d->image_challenger, CHALLENGER_COLOR);
	fill_img(d, d->image_t_challenger, CHALLENGER_TERRITORY_COLOR);
	fill_img(d, d->image_frontier, FRONTIER_COLOR);
}
