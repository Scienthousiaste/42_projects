/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 18:31:59 by tbehra            #+#    #+#             */
/*   Updated: 2019/05/08 18:43:00 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	*realloc(void *ptr, size_t size)
{
	t_zone *z;

	if (!ptr)
		return (NULL);
	z = try_find_zone(g_alloc.tiny, ptr, NULL);
	return (NULL);
}
