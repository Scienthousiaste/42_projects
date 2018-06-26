/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_test_frontier.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 19:18:24 by tbehra            #+#    #+#             */
/*   Updated: 2018/05/28 12:39:55 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int16_t	update_frontier_test(t_filler *f)
{
	int		x;
	int		y;
	int16_t	ret;

	y = RESET_COUNT;
	ret = 0;
	while (++y < f->ymax)
	{
		x = RESET_COUNT;
		while (++x < f->xmax)
			if (!f->frontier[y][x])
				ret += fill_frontier_test(f, x, y);
	}
	y = RESET_COUNT;
	while (++y < f->ymax)
	{
		x = RESET_COUNT;
		while (++x < f->xmax)
			f->frontier[y][x] %= 2;
	}
	return (ret);
}
