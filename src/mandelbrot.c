/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyanagis <kyanagis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 19:11:37 by kyanagis          #+#    #+#             */
/*   Updated: 2025/06/16 07:30:33 by kyanagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static double	dist_est(const t_iter *v)
{
	const double	mod = sqrt(v->zr * v->zr + v->zi * v->zi);
	const double	dnorm = sqrt(v->dr * v->dr + v->di * v->di);

	return (mod * log(mod) / dnorm);
}

static void	iter_init(t_iter *v)
{
	v->zr = 0;
	v->zi = 0;
	v->dr = 1;
	v->di = 0;
}

static int	iter_loop(double cx, double cy, t_iter *v, int lim)
{
	int		i;
	double	tmp_r;
	double	tmp_d;

	i = 0;
	while (v->zr * v->zr + v->zi * v->zi <= 4.0 && i < lim)
	{
		tmp_r = v->zr * v->zr - v->zi * v->zi + cx;
		v->zi = 2.0 * v->zr * v->zi + cy;
		v->zr = tmp_r;
		tmp_d = 2.0 * (v->zr * v->dr - v->zi * v->di) + 1.0;
		v->di = 2.0 * (v->zr * v->di + v->zi * v->dr);
		v->dr = tmp_d;
		++i;
	}
	return (i);
}

double	iter_mandel(double cx, double cy, const t_fract *f)
{
	t_iter	v;
	int		it;

	iter_init(&v);
	it = iter_loop(cx, cy, &v, f->iter_base);
	if (it == f->iter_base)
		return ((double)f->iter_base);
	return (it + 1.0 / (1.0 + dist_est(&v) * 10.0));
}
