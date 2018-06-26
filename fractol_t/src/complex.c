/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 17:30:59 by tbehra            #+#    #+#             */
/*   Updated: 2018/06/26 12:15:40 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double		squared_modulus(t_complex c)
{
	return (c.re * c.re + c.im * c.im);
}

double		modulus(t_complex c)
{
	return (sqrt(squared_modulus(c)));
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
