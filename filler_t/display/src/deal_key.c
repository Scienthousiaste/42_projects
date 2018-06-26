/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/27 19:03:28 by tbehra            #+#    #+#             */
/*   Updated: 2018/05/27 19:06:23 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"

void	decrease_speed(t_display_mlx *d)
{
	if (d->turn_increment_nb > 1)
	{
		d->turn_increment_nb--;
		show_turn_increment(d);
	}
	return ;
}

void	increase_speed(t_display_mlx *d)
{
	d->turn_increment_nb++;
	show_turn_increment(d);
	return ;
}

int		deal_key(int key, void *param)
{
	t_display_mlx	*d;

	d = (t_display_mlx*)param;
	if (key == ESC_KEY)
		quit_program(d);
	if (key == LEFT_ARROW_KEY)
		previous_turn(d);
	if (key == RIGHT_ARROW_KEY)
		next_turn(d);
	if (key == UP_ARROW_KEY)
		increase_speed(d);
	if (key == DOWN_ARROW_KEY)
		decrease_speed(d);
	return (0);
}
