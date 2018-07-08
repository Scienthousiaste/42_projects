/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 17:48:46 by tbehra            #+#    #+#             */
/*   Updated: 2018/07/08 21:08:45 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
 * A faire
 *
 * Buddhabrot https://fr.wikipedia.org/wiki/Buddhabrot
 * Fractales 3D ?
 * MULITHREADING
 * utiliser la carte graphique : https://fr.wikipedia.org/wiki/OpenCL
 */

void	error(int err)
{
	const int nb_err = 4;
	const char *err_msg[nb_err] =
	{"Erreur.", "Erreur de malloc.", "Option invalide.",
		"Taille de fenêtre invalide."};

	if (err < 0 || err > nb_err)
		exit(1);
	ft_putendl(err_msg[err]);
	exit(1);
}

void	usage(void)
{
	ft_putendl("Usage: fractol [-m | -j [-w width height]]"); 
	ft_putendl("\t-m for Mandelbrot set");
	ft_putendl("\t-j for Julia set");
	ft_putendl("\t-c for Collatz fractal");
	ft_putendl("During execution, use F to fix Julia's parameter, Z to toggle zoom, R to recenter, C to use clicks to zoom instead of scrolling.\n");
	exit(0);
}

int		get_window_size(int ac, char **av, int i, t_display *d)
{
	if (i + 3 > ac)
		error(INVALID_WINDOW_SIZE);
	if (!(ft_isdigit(av[i + 1][0])))
		error(INVALID_WINDOW_SIZE);
	d->win_width = ft_atoi(av[i + 1]);
	if (!(ft_isdigit(av[i + 2][0])))
		error(INVALID_WINDOW_SIZE);
	d->win_height = ft_atoi(av[i + 2]);
	if (d->win_width > MAX_WIN_WIDTH || d->win_width < MIN_WIN_WIDTH
			|| d->win_height > MAX_WIN_HEIGHT || d->win_height < MIN_WIN_HEIGHT)
		error(INVALID_WINDOW_SIZE);
	return (2);
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
			else if (av[i][1] == 'j')
			{
				d->init_fractal = &init_julia;
				d->display_fractal = &julia;
			}
			else if (av[i][1] == 'm')
			{
				d->init_fractal = &init_mandelbrot;
				d->display_fractal = &mandelbrot;
			}
			else if (av[i][1] == 'c')
			{
				d->init_fractal = &init_collatz;
				d->display_fractal = &collatz;
			}
			else
				usage();
		}
		else
			usage();
	}
}

int main(int ac, char **av)
{
	t_display	d;

	ft_bzero((void*)&d, sizeof(t_display));
	if (ac < 2)
		usage();
	check_params(ac, av, &d);
	if (d.display_fractal == NULL)
		usage();
	d.init_fractal(&d);
	init_display(&d);
	display_complex_fractal(&d);
	mlx_key_hook(d.win, &deal_key, &d);
	mlx_mouse_hook(d.win, &deal_mouse, &d);
	if (d.display_fractal == &julia)
		mlx_hook(d.win, MOTION_NOTIFY, 64, &change_julia_param, &d);
	mlx_loop(d.mlx);
	return (0);
}
