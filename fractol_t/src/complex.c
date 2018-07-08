/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 17:30:59 by tbehra            #+#    #+#             */
/*   Updated: 2018/07/08 19:29:52 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double		squared_modulus(t_complex c)
{
	return (c.re * c.re + c.im * c.im);
}

t_complex	c_exp(t_complex c)
{
	double r;
	t_complex ret;

	r = exp(c.re);
	ret.re = r * cos(c.im);
	ret.im = r * cos(c.im);
	return (ret);
}

t_complex	c_mult_i(t_complex c)
{
	t_complex	ret;

	ret.re = c.im * -1;
	ret.im = c.re;
	return (ret);
}

t_complex	c_minus(t_complex c)
{
	t_complex	ret;

	ret.re = c.re * -1;
	ret.im = c.im * -1;
	return (ret);
}

t_complex	c_cos(t_complex c)
{
	return (c_scalar_mult(c_add(c_exp(c_mult_i(c)), c_exp(c_mult_i(c_minus(c)))), 0.5));
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

t_complex	c_add_re(t_complex a, double to_add)
{
	t_complex	ret;

	ret.re = a.re + to_add;
	ret.im = a.im;
	return (ret);
}

t_complex	c_sub(t_complex a, t_complex b)
{
	t_complex	ret;

	ret.re = a.re - b.re;
	ret.im = a.im - b.im;
	return (ret);
}

t_complex	c_add(t_complex a, t_complex b)
{
	t_complex	ret;
	
	ret.re = a.re + b.re;
	ret.im = a.im + b.im;
	return (ret);
}

t_complex	c_mult(t_complex a, t_complex b)
{
	t_complex	ret;

	ret.re = (a.re * b.re) - (a.im * b.im);
	ret.im = (a.re * b.im) + (a.im * b.re);
	return (ret);
}

t_complex	c_init(double r, double i)
{
	t_complex c;

	c.re = r;
	c.im = i;
	return (c);
}

void		c_print(t_complex c)
{
	printf("%f + i*%f. Module : %f.\n", c.re, c.im, modulus(c));
}
