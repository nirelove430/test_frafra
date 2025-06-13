/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyanagis <kyanagis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 19:11:52 by kyanagis          #+#    #+#             */
/*   Updated: 2025/06/13 19:59:52 by kyanagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

static void	pan(t_fract *f, int k)
{
	printf("key > %d\n", k);
	if (k == KC_L)
		f->off_x -= PAN_STEP / f->zoom;
	else if (k == KC_R)
		f->off_x += PAN_STEP / f->zoom;
	else if (k == KC_U)
		f->off_y -= PAN_STEP / f->zoom;
	else if (k == KC_D)
		f->off_y += PAN_STEP / f->zoom;
}

int	key_hook(int k, t_fract *f)
{
	if (k == KC_ESC)
		return (close_win(f), 0);
	if (k == 'c' || k == 'C')
	{
		f->hue += 30;
		if (f->hue >= 360)
			f->hue -= 360;
		render_frame(f);
		return (0);
	}
	pan(f, k);
	render_frame(f);
	return (0);
}

int	mouse_hook(int btn, int x, int y, t_fract *f)
{
	double	prev;

	if (btn != BTN_UP && btn != BTN_DN)
		return (0);
	prev = f->zoom;
	if (btn == BTN_UP)
		f->zoom = prev * ZOOM_STEP;
	else
		f->zoom = prev / ZOOM_STEP;
	f->off_x += (x - WIN_W / 2.0) * (4.0 / WIN_W) * (1 / prev - 1 / f->zoom);
	f->off_y += (y - WIN_H / 2.0) * (4.0 / WIN_W) * (1 / prev - 1 / f->zoom);
	f->iter_base = 40 + 8 * log2(f->zoom);
	if (f->iter_base > 250)
		f->iter_base = 250;
	render_frame(f);
	return (0);
}
