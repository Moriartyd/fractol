/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 23:23:09 by cpollich          #+#    #+#             */
/*   Updated: 2019/11/01 23:09:15 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		get_color(t_fract *fract, int i)
{
	int		r;
	int		g;
	int		b;
	double	t;

	t = (double)i / fract->it;
	r = (int)(9 * (1 - t) * pow(t, 3) * 255);
	g = (int)(15 * pow((1 - t), 2) * pow(t, 2) * 255);
	b = (int)(8.5 * pow((1 - t), 3) * t * 255);
	return (RGB(r, g, b));
}

void	put_pixel(int x, int y, t_fract *fract, int i)
{
	fract->mlx->data_addr[y * WIDTH + x] = get_color(fract, i);
}

void	draw(t_fract *fract)
{
	ft_bzero(fract->mlx->data_addr, WIDTH * HEIGHT * sizeof(int));
	if (fract->key == MANDELBROT)
		mandelbrot(fract);
	else if (fract->key == JULIA)
		julia(fract);
	else if (fract->key == BSHP)
		bshp(fract);
	mlx_put_image_to_window(MLX(fract)->mlx,
		MLX(fract)->win, MLX(fract)->img, 0, 0);
}
