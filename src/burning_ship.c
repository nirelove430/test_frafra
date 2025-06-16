/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyanagis <kyanagis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 07:33:34 by kyanagis          #+#    #+#             */
/*   Updated: 2025/06/16 21:59:55 by kyanagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	iter_burning(double cx, double cy, const t_fract *f)
{
	double	zr;
	double	zi;
	double	temp;
	int		i;

	zr = 0;
	zi = 0;
	i = 0;
	while (zr * zr + zi * zi <= 4.0 && i < f->iter_base)
	{
		temp = zr * zr - zi * zi + cx;
		zi = fabs(2.0 * zr * zi) + cy;
		zr = fabs(temp);
		++i;
	}
	if (i == f->iter_base)
		return (f->iter_base);
	return (i + 1.0 / (1.0 + log(zr * zr + zi * zi)));
}
