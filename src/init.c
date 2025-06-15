/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyanagis <kyanagis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 19:11:44 by kyanagis          #+#    #+#             */
/*   Updated: 2025/06/16 07:27:49 by kyanagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_win(t_fract *f)
{
	mlx_destroy_window(f->mlx, f->win);
	exit(0);
	return (0);
}

void	init_fract(t_fract *f)
{
	f->mlx = mlx_init();
	f->win = mlx_new_window(f->mlx, WIN_W, WIN_H, "fractol");
	f->img.img = mlx_new_image(f->mlx, WIN_W, WIN_H);
	f->img.addr = mlx_get_data_addr(f->img.img, &f->img.bpp, &f->img.line,
			&f->img.endian);
	f->zoom = 1.0;
	f->off_x = 0;
	f->off_y = 0;
	f->iter_base = 60;
	f->hue = 0;
	render_frame(f);
	mlx_hook(f->win, 17, 0, close_win, f);
	mlx_key_hook(f->win, key_hook, f);
	mlx_mouse_hook(f->win, mouse_hook, f);
}
