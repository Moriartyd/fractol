/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 22:47:16 by cpollich          #+#    #+#             */
/*   Updated: 2019/11/01 00:09:12 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	calculate_mandelbrot(int x, int y, t_fract *fract)
{
	int	i;

	i = 0;
	fract->coord.key = 0;
	fract->coord.z_x = fract->coord.c_x;
	fract->coord.z_y = fract->coord.c_y;
	while (i < REPEATS)
	{
		fract->coord.zx = fract->coord.z_x * fract->coord.z_x;
		fract->coord.zy = fract->coord.z_y * fract->coord.z_y;
		if (fract->coord.zx + fract->coord.zy > 4)
		{
			fract->coord.key = 1;
			break ;
		}
		fract->coord.z_y = 2 * fract->coord.z_x *
					fract->coord.z_y + fract->coord.c_y;
		fract->coord.z_x = fract->coord.zx -
					fract->coord.zy + fract->coord.c_x;
		i++;
	}
	fract->coord.key ? put_pixel(x, y, fract) : 0;
}

void		mandelbrot(t_fract *fract)
{
	int	y;
	int	x;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		fract->coord.c_y = MAX_Y - y * SHIFT_Y;
		while (x < WIDTH)
		{
			fract->coord.c_x = MIN_X + x * SHIFT_X;
			calculate_mandelbrot(x, y, fract);
			x++;
		}
		y++;
	}
}