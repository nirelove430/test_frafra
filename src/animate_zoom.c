/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate_zoom.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyanagis <kyanagis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 17:53:07 by kyanagis          #+#    #+#             */
/*   Updated: 2025/06/13 20:00:09 by kyanagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>

int	animate_zoom(t_fract *f)
{
	const double	rate = 1.015;
	double			prev_zoom;

	prev_zoom = f->zoom;
	f->zoom *= rate;
	f->off_x += (WIN_W / 2.0) * (4.0 / WIN_W) * (1 / prev_zoom - 1 / f->zoom);
	f->off_y += (WIN_H / 2.0) * (4.0 / WIN_W) * (1 / prev_zoom - 1 / f->zoom);
	f->iter_base = 40 + 8 * log2(f->zoom);
	if (f->iter_base > 250)
		f->iter_base = 250;
	f->hue = (f->hue + 1) % 360;
	render_frame(f);
	return (0);
}
