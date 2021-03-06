/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 17:30:59 by tbehra            #+#    #+#             */
/*   Updated: 2018/07/24 15:40:50 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	c_minus(t_complex c)
{
	t_complex	ret;

	ret.re = c.re * -1;
	ret.im = c.im * -1;
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

t_complex	c_init(double r, double i)
{
	t_complex c;

	c.re = r;
	c.im = i;
	return (c);
}
