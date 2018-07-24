/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 17:48:46 by tbehra            #+#    #+#             */
/*   Updated: 2018/07/24 19:10:18 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** A FAIRE
**		"PLEIN DE FRACTALES". Buddabrot, autres sur le fractalforums ?
**		changement de couleurs
**		 Buddhabrot https://fr.wikipedia.org/wiki/Buddhabrot
*/

void	error(int err)
{
	const int	nb_err = 4;
	const char	*err_msg[nb_err] =
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
	ft_putendl("\t-b for burning ship fractal");
	ft_putendl("\t-u for Buddhabrot fractal");
	ft_putstr("During execution, use :\n\tF ");
	ft_putstr("to fix Julia's parameter\n\tZ to toggle ");
	ft_putstr("zoom\n\tC to recenter\n\tM to toggle using clicks to");
	ft_putstr("zoom instead of scrolling\n\tR, G, B, W for red, green, blue");
	ft_putstr(", B&W monochromes\n\tP to use the default palette\n\tArrows to");
	ft_putstr(" move around\n\t< and > to increase/decrease iterations by 20");
	ft_putendl("\n\tKeypad's + and - to increase/decrease iterations by 1");
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

int		main(int ac, char **av)
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
