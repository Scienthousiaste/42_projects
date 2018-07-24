/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_angles.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 15:34:26 by tbehra            #+#    #+#             */
/*   Updated: 2018/07/24 15:37:40 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	c_exp(t_complex c)
{
	double		r;
	t_complex	ret;

	r = exp(c.re);
	ret.re = r * cos(c.im);
	ret.im = r * sin(c.im);
	return (ret);
}

t_complex	c_cos(t_complex c)
{
	return (c_scalar_mult(
				c_add(c_exp(c_mult_i(c)), c_exp(c_mult_i(c_minus(c)))),
				0.5));
}

t_complex	c_rotate(t_complex a, double angle)
{
	return (c_mult(a, c_exp(c_mult_i(c_init(angle, 0)))));
}

t_complex	c_abs(t_complex c)
{
	t_complex ret;

	ret.re = fabs(c.re);
	ret.im = fabs(c.im);
	return (ret);
}
