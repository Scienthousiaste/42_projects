/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256_auxiliary_functions2.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 16:23:18 by tbehra            #+#    #+#             */
/*   Updated: 2019/04/15 16:28:22 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

uint32_t	bigsig_0(uint32_t x)
{
	return (rotr(x, 2) ^ rotr(x, 13) ^ rotr(x, 22));
}

uint32_t	bigsig_1(uint32_t x)
{
	return (rotr(x, 6) ^ rotr(x, 11) ^ rotr(x, 25));
}

uint32_t	sig_0(uint32_t x)
{
	return (rotr(x, 7) ^ rotr(x, 18) ^ (x >> 3));
}

uint32_t	sig_1(uint32_t x)
{
	return (rotr(x, 17) ^ rotr(x, 19) ^ (x >> 10));
}
