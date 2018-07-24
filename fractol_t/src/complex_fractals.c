/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_fractals.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/01 17:14:29 by tbehra            #+#    #+#             */
/*   Updated: 2018/07/24 20:07:23 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_threads(t_disp_bundle *db, t_display *d)
{
	int n_thread;

	n_thread = 0;
	while (n_thread < NB_THREAD)
	{
		db[n_thread].d = d;
		if (n_thread == 0)
		{
			db[0].y_min = 0;
			db[0].y_max = d->win_height / NB_THREAD;
		}
		else
		{
			db[n_thread].y_min = db[n_thread - 1].y_max;
			db[n_thread].y_max = (n_thread + 1) * (d->win_height / NB_THREAD);
		}
		n_thread++;
	}
}

void	display_complex_fractal(t_display *d)
{
	pthread_t		*thread;
	t_disp_bundle	*db;
	int				n_thread;

	if (!(thread = (pthread_t*)malloc(sizeof(pthread_t) * NB_THREAD)))
		error(MALLOC_ERROR);
	if (!(db = (t_disp_bundle*)malloc(sizeof(t_disp_bundle) * NB_THREAD)))
		error(MALLOC_ERROR);
	init_threads(db, d);
	n_thread = 0;
	while (n_thread < NB_THREAD)
	{
		pthread_create(&thread[n_thread], NULL, d->display_fractal,
				(void*)&db[n_thread]);
		n_thread++;
	}
	n_thread = 0;
	while (n_thread < NB_THREAD)
	{
		pthread_join(thread[n_thread], NULL);
		n_thread++;
	}
	mlx_put_image_to_window(d->mlx, d->win, d->img, 0, 0);
	free(thread);
	free(db);
}
