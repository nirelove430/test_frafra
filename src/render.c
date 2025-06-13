/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyanagis <kyanagis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 19:11:16 by kyanagis          #+#    #+#             */
/*   Updated: 2025/06/13 19:57:28 by kyanagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"

static void	put_line(t_img *img, int *buf, int y)
{
	ft_memcpy(img->addr + y * img->line, buf, WIN_W * 4);
}

void	render_frame(t_fract *f)
{
	int		x;
	int		y;
	double	cy;
	double	inc;
	int		line[WIN_W];

	inc = (4.0 / WIN_W) / f->zoom;
	cy = (-WIN_H / 2.0) * inc + f->off_y;
	y = 0;
	while (y < WIN_H)
	{
		x = 0;
		while (x < WIN_W)
		{
			line[x] = get_color(iter_mu((x - WIN_W / 2.0) * inc + f->off_x, cy,
						f->iter_base), f->iter_base, f->hue);
			++x;
		}
		put_line(&f->img, line, y);
		cy += inc;
		++y;
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img.img, 0, 0);
}
