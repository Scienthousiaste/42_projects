/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 17:48:46 by tbehra            #+#    #+#             */
/*   Updated: 2018/06/26 18:43:36 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
 * A faire
 *
 * Buddhabrot https://fr.wikipedia.org/wiki/Buddhabrot
 * Fractales 3D ?
 * MULITHREADING
 *
*/

void	error(int err)
{
	ft_putstr("Erreur ");
	ft_putnbr(err);
	ft_putchar('\n');
	exit(1);
}

void	usage(void)
{
	ft_putendl("Usage: fractol -m for Mandelbrot set, -j for Julia set");
	exit(0);
}

void	check_params(int ac, char **av)
{
	(void)ac;
	(void)av;
}

int main(int ac, char **av)
{
	t_display d;

	if (ac < 2)
		usage();
	check_params(ac, av);
	d.x_min = -2;
	d.x_max = 1;
	d.y_min = -1;
	d.y_max = 1;
	d.display_fractal = &mandelbrot;
	init_display(&d);
	d.display_fractal(&d);
	mlx_key_hook(d.win, &deal_key, &d);
	mlx_mouse_hook(d.win, &deal_mouse, &d);
	mlx_loop(d.mlx);
	return (0);
}
