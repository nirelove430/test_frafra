/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyanagis <kyanagis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 19:11:37 by kyanagis          #+#    #+#             */
/*   Updated: 2025/06/14 04:55:21 by kyanagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>

/* 距離推定を分離 ― 変数数セーブ */
static double	dist_est(double zr, double zi, double dr, double di)
{
	const double	mod = sqrt(zr * zr + zi * zi);

	return (mod * log(mod) / sqrt(dr * dr + di * di));
}

static void	iter_init(double *zr, double *zi, double *dr, double *di)
{
	*zr = 0;
	*zi = 0;
	*dr = 1;
	*di = 0;
}

static int	iter_loop(double cx, double cy, double *zr, double *zi, double *dr,
		double *di, int lim)
{
	int		i;
	double	t;

	i = 0;
	while (*zr * *zr + *zi * *zi <= 4.0 && i < lim)
	{
		t = *zr * *zr - *zi * *zi + cx;
		*zi = 2.0 * *zr * *zi + cy;
		*zr = t;
		t = 2.0 * (*zr * *dr - *zi * *di) + 1.0;
		*di = 2.0 * (*zr * *di + *zi * *dr);
		*dr = t;
		++i;
	}
	return (i);
}

double	iter_mandel(double cx, double cy, const t_fract *f)
{
	double	zr;
	double	zi;
	double	dr;
	double	di;
	int		it;

	iter_init(&zr, &zi, &dr, &di);
	it = iter_loop(cx, cy, &zr, &zi, &dr, &di, f->iter_base);
	if (it == f->iter_base)
		return ((double)f->iter_base);
	return (it + 1.0 / (1.0 + dist_est(zr, zi, dr, di) * 10.0));
}
