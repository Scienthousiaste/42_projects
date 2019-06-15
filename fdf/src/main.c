/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 17:21:06 by tbehra            #+#    #+#             */
/*   Updated: 2018/06/24 17:09:26 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	usage(void)
{
	ft_putendl("Usage: fdf filename.");
	exit(0);
}

void	error(int error)
{
	const char *errmsg[7] =
	{"Erreur lors de l'ouverture du fichier (existe-t-il ?).",
	"Erreur de malloc.",
	"Erreur lors de lecture avec GNL.",
	"Une valeur n'est pas un nombre.",
	"Erreur : map vide.",
	"Nombre de colonnes inconsistant.",
	"Nombre incorrect (par exemple, trop grand)."};

	ft_printf("%s\n", errmsg[error]);
	exit(0);
}

void	build_rotation_matrix(t_fdf *fdf)
{
	double m;

	fdf->alpha = asin(tan(fdf->alpha_deg * M_PI / 180));
	fdf->beta = fdf->beta_deg * M_PI / 180;
	m = (1 / sqrt(6));
	fdf->rotation_matrix[0][0] = cos(fdf->beta) * m;
	fdf->rotation_matrix[0][1] = 0;
	fdf->rotation_matrix[0][2] = -sin(fdf->beta) * m;
	fdf->rotation_matrix[1][0] = sin(fdf->alpha) * sin(fdf->beta) * m;
	fdf->rotation_matrix[1][1] = cos(fdf->alpha) * m;
	fdf->rotation_matrix[1][2] = cos(fdf->beta) * sin(fdf->beta) * m;
	fdf->rotation_matrix[2][0] = cos(fdf->alpha) * sin(fdf->beta) * m;
	fdf->rotation_matrix[2][1] = -sin(fdf->alpha) * m;
	fdf->rotation_matrix[2][2] = cos(fdf->alpha) * cos(fdf->beta) * m;
}

void	init_fdf(t_fdf *fdf)
{
	fdf->row = 0;
	fdf->col = -1;
	fdf->map = NULL;
	if (!(fdf->map_1d = (int *)malloc(sizeof(int) * MAP_START_SIZE)))
		error(MALLOC_ERROR);
	fdf->size_map_1d = MAP_START_SIZE;
	fdf->i_map = 0;
	fdf->start_point = NULL;
	fdf->project = &isometric_projection;
	fdf->alpha_deg = 30;
	fdf->beta_deg = 45;
	fdf->scale_x = 0;
	fdf->scale_y = 0;
}

int		main(int ac, char **av)
{
	t_fdf fdf;

	if (ac < 2)
		usage();
	init_fdf(&fdf);
	fdf.fd = open(av[1], O_RDONLY);
	if (fdf.fd == -1)
		error(ERROR_NO_FILE);
	parse_map(&fdf);
	reorganize_map(&fdf);
	launch_mlx(&fdf);
	init_display_params(&fdf);
	projection_link(&fdf);
	mlx_key_hook(fdf.win, &deal_key, &fdf);
	mlx_loop(fdf.mlx);
	return (0);
}
