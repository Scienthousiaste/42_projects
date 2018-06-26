/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 15:52:10 by tbehra            #+#    #+#             */
/*   Updated: 2018/06/26 17:12:56 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	find_color(t_display *d, int n_div)
{
	(void)n_div;
	(void)d;
	return (d->color_palette[(n_div - 1) % N_COLOR]);
	if ((n_div - 1) < N_COLOR)
		return (d->color_palette[n_div - 1]);
	else
		return (WHITE);
}

void	build_color_palette(t_display *d)
{
	const int tab_color[N_COLOR] = {MARINE_BLUE, BLUE_2, ROYAL_BLUE, DODGER_BLUE, 
		DEEP_SKY_BLUE, TURQUOISE, SPRING_GREEN, GREEN_YELLOW, YELLOW, ORANGE, 
		REDDISH, ALMOST_RED, RED_2, RED_3, RED_4, RED_5, RED_6, RED_7};
	int i;

	i = -1;
	while (++i < N_COLOR)
	{
		d->color_palette[i] = tab_color[i];
	}	
}
