/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_julia.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 23:59:53 by cpollich          #+#    #+#             */
/*   Updated: 2019/11/01 21:03:00 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	calculate_julia(int x, int y, t_fract *fract)
{
	int	i;

	i = 0;
	fract->coord.key = 0;
	fract->coord.z_x = fract->coord.c_x;
	fract->coord.z_y = fract->coord.c_y;
	while (i < fract->it)
	{
		fract->coord.zx = fract->coord.z_x * fract->coord.z_x;
		fract->coord.zy = fract->coord.z_y * fract->coord.z_y;
		if (fract->coord.zx + fract->coord.zy > 4)
		{
			fract->coord.key = 1;
			break ;
		}
		fract->coord.z_y = 2.0 * fract->coord.z_x *
					fract->coord.z_y + fract->coord.j_y;
		fract->coord.z_x = fract->coord.zx -
					fract->coord.zy + fract->coord.j_x;
		i++;
	}
	fract->coord.key ? put_pixel(x, y, fract) : 0;
}

void		julia(t_fract *fract)
{
	int	y;
	int	x;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		CORD(fract).c_y = 4 * ((double)(HEIGHT - y) / HEIGHT - 0.5);
		while (x < WIDTH)
		{
			fract->coord.c_x = 4 * ((double)x / WIDTH - 0.5);
			calculate_julia(x, y, fract);
			x++;
		}
		y++;
	}
}
