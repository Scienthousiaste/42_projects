/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_op.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 15:39:12 by tbehra            #+#    #+#             */
/*   Updated: 2018/07/24 15:40:38 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double		squared_modulus(t_complex c)
{
	return (c.re * c.re + c.im * c.im);
}

t_complex	c_mult_i(t_complex c)
{
	t_complex	ret;

	ret.re = c.im * -1;
	ret.im = c.re;
	return (ret);
}

double		modulus(t_complex c)
{
	return (sqrt(squared_modulus(c)));
}

t_complex	c_scalar_mult(t_complex a, double scalar)
{
	t_complex	ret;

	ret.re = scalar * a.re;
	ret.im = scalar * a.im;
	return (ret);
}

t_complex	c_mult(t_complex a, t_complex b)
{
	t_complex	ret;

	ret.re = (a.re * b.re) - (a.im * b.im);
	ret.im = (a.re * b.im) + (a.im * b.re);
	return (ret);
}
