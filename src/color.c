/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyanagis <kyanagis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 17:52:29 by kyanagis          #+#    #+#             */
/*   Updated: 2025/06/14 00:38:56 by kyanagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color_theme.h"
#include "fractol.h"
#include <math.h>

static int	compose_rgb(double t, double brt, double sat, double phase)
{
	int	red;
	int	green;
	int	blue;

	red = (int)(HI * brt + LO * (1.0 - brt) + 50.0 * sat * sin(3.0 * M_PI * t
				+ phase));
	green = (int)(HI * brt + LO * (1.0 - brt) + 50.0 * sat * sin(3.0 * M_PI * t
				+ 2.1 + phase));
	blue = (int)((HI + 40.0) * brt + LO * (1.0 - brt) + 50.0 * sat * sin(3.0
				* M_PI * t + 4.2 + phase));
	red &= 0xFF;
	green &= 0xFF;
	blue &= 0xFF;
	return ((red << 16) | (green << 8) | blue);
}

static double	calc_bright(double prog, double tex)
{
	double	brt;

	brt = BR_ADD + BR_GAIN * pow(prog, POW_EXP);
	brt *= 0.9 + TEX_BR_GAIN * tex;
	return (brt);
}

static double	calc_satmix(double mu, double tex)
{
	double	stripe;
	double	sat;

	stripe = fabs(sin(M_PI * mu / STRIPE_P));
	sat = SAT_BASE + SAT_GAIN * stripe;
	sat *= 0.9 + TEX_SAT_GAIN * tex;
	return (sat);
}

int	get_color(double mu, int limit, int hue_deg)
{
	double	prog;
	double	tex;
	double	brt;
	double	sat;
	double	shift_max;

	if (mu >= limit - 0.5)
		return (0x000000);
	prog = mu / (double)limit;
	tex = 0.5 + 0.5 * sin(TEX_FREQ * M_PI * mu);
	brt = calc_bright(prog, tex);
	sat = calc_satmix(mu, tex);
	if (hue_deg < 180)
		shift_max = 270.0;
	else
		shift_max = -240.0;
	return (compose_rgb(prog, brt, sat, (hue_deg + shift_max * prog * prog)
			* M_PI / 180.0));
}
