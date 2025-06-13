/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyanagis <kyanagis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 19:11:37 by kyanagis          #+#    #+#             */
/*   Updated: 2025/06/13 19:56:50 by kyanagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>

double	iter_mu(double cx, double cy, int lim)
{
	int		i;
	double	tmp;
	double	mod;
	double	dist;

	double zr, zi, d_r, d_i;
	zr = 0;
	zi = 0;
	d_r = 1;
	d_i = 0;
	i = 0;
	while (zr * zr + zi * zi <= 4.0 && i < lim)
	{
		tmp = zr * zr - zi * zi + cx;
		zi = 2.0 * zr * zi + cy;
		zr = tmp;
		tmp = 2.0 * (zr * d_r - zi * d_i) + 1.0;
		d_i = 2.0 * (zr * d_i + zi * d_r);
		d_r = tmp;
		++i;
	}
	if (i == lim)
		return ((double)lim); /* 収束→黒 */
	mod = sqrt(zr * zr + zi * zi);
	dist = mod * log(mod) / sqrt(d_r * d_r + d_i * d_i);
	double shade = 1.0 / (1.0 + dist * 10.0); /* 0〜1 */
	return (((double)i) + shade);             /* 小数で滑らか */
}
