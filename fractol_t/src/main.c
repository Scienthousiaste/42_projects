/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 17:48:46 by tbehra            #+#    #+#             */
/*   Updated: 2018/06/30 15:45:22 by tbehra           ###   ########.fr       */
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
	ft_putendl("Usage: fractol [-mj -w [width height]]"); 
	ft_putendl("\t-m for Mandelbrot set");
	ft_putendl("\t-j for Julia set");
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

	printf("width %i height %i\n", d->win_width, d->win_height);
	return (2);
}

void	check_params(int ac, char **av, t_display *d)
{
	int i;

	i = 0;
	while (++i < ac)
	{
		printf("debut boucle %i\n", i);
		if (av[i][0] == '-')
		{
			if (av[i][1] == 'w')
			{
				get_window_size(ac, av, i, d);
		printf("post get_window %i\n", i);
		break ;
			}
			else if (av[i][1] == 'j')
				d->display_fractal = &julia;
			else if (av[i][1] == 'm')
				d->display_fractal = &mandelbrot;
		}
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
	d.x_min = -2;
	d.x_max = 1;
	d.y_min = -1;
	d.y_max = 1;
	init_display(&d);
	d.display_fractal(&d);
	mlx_key_hook(d.win, &deal_key, &d);
	mlx_mouse_hook(d.win, &deal_mouse, &d);
	mlx_loop(d.mlx);
	return (0);
}
