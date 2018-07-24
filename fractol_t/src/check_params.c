/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 14:45:19 by tbehra            #+#    #+#             */
/*   Updated: 2018/07/24 14:46:44 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		check_more_params(int i, char **av, t_display *d)
{
	int r;

	r = 0;
	if (av[i][1] == 'c' && (r = 1))
	{
		d->init_fractal = &init_collatz;
		d->display_fractal = &collatz;
	}
	else if (av[i][1] == 'b' && (r = 1))
	{
		d->init_fractal = &init_burning_ship;
		d->display_fractal = &burning_ship;
	}
	else if (av[i][1] == 'u' && (r = 1))
	{
		d->init_fractal = &init_buddhabrot;
		d->display_fractal = &buddhabrot;
	}
	else if (av[i][1] == 'm' && (r = 1) &&
			(d->init_fractal = &init_mandelbrot))
		d->display_fractal = &mandelbrot;
	else if (av[i][1] == 'j' && (r = 1) &&
			(d->init_fractal = &init_julia))
		d->display_fractal = &julia;
	return (r);
}

void	check_params(int ac, char **av, t_display *d)
{
	int i;

	i = 0;
	while (++i < ac)
	{
		if (av[i][0] == '-')
		{
			if (av[i][2] != '\0')
				usage();
			if (av[i][1] == 'w')
				i += get_window_size(ac, av, i, d);
			else if (av[i][1] >= 'b' && av[i][1] <= 'u')
			{
				if (!(check_more_params(i, av, d)))
					usage();
			}
			else
				usage();
		}
		else
			usage();
	}
}
