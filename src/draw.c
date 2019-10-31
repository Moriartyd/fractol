/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 23:23:09 by cpollich          #+#    #+#             */
/*   Updated: 2019/11/01 00:09:22 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_pixel(int x, int y, t_fract *fract)
{
	fract->mlx->data_addr[y * WIDTH + x] = fract->color;
}

void	draw(t_fract *fract)
{
	fract->color = 0xFF0000;
	ft_bzero(fract->mlx->data_addr, WIDTH * HEIGHT);
	if (fract->key == MANDELBROT)
		mandelbrot(fract);
	// else if (fract->key == JULIA)
	// 	julia(fract);
	else if (fract->key == BSHP)
		bshp(fract);
	mlx_put_image_to_window(MLX(fract)->mlx, MLX(fract)->win, MLX(fract)->img, 0, 0);
}