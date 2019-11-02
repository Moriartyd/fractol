/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 20:48:12 by cpollich          #+#    #+#             */
/*   Updated: 2019/11/02 19:48:03 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "key_map.h"
#include "fractol.h"
#include "colors.h"

static int	key_press(int key, void *param)
{
	t_fract	*fract;

	fract = (t_fract *)param;
	if (key == K_ESC)
		exit(0);
	else if (key == K_B)
		fract->key = BSHP;
	else if (key == K_J)
		fract->key = JULIA;
	else if (key == K_M)
		fract->key = MANDELBROT;
	else if (key == K_PLUS || key == K_PLUS_NUM ||
					key == K_MINUS || key == K_MINUS_NUM)
		change_iteration(fract, key);
	else if (key >= K_ARROW_LEFT && key <= K_ARROW_DOWN)
		arrow_control(fract, key);
	else if (key == K_MEN || key == K_BOL)
		change_move_speed(fract, key);
	else if (key == K_BACKSPCE)
		back_pls(fract);
	draw(fract);
	return (0);
}

static int	close_fdf(void *param)
{
	(void)param;
	exit(0);
}

static int	mouse_handling(int x, int y, void *param)
{
	t_fract *fract;

	fract = (t_fract *)param;
	if (fract->key == JULIA && fract->mouse)
	{
		fract->coord.j_x = 4 * ((double)x / WIDTH - 0.5);
		fract->coord.j_y = 4 * ((double)(HEIGHT - y) / HEIGHT - 0.5);
		draw(fract);
	}
	return (0);
}

static int	mouse_click(int button, int x, int y, void *param)
{
	t_fract	*fract;

	fract = (t_fract *)param;
	(void)x;
	(void)y;
	if (button == 1)
		fract->mouse = fract->mouse ? 0 : 1;
	else if (button == MOUSE_SCROLL_UP || button == MOUSE_SCROLL_DOWN)
		make_zoom(fract, button);
	draw(fract);
	return (0);
}

void		hook_init(t_fract *fract)
{
	mlx_hook(MLX(fract)->win, 2, 0L, key_press, fract);
	mlx_hook(MLX(fract)->win, 17, 0L, close_fdf, fract);
	mlx_hook(MLX(fract)->win, 4, 0L, mouse_click, fract);
	mlx_hook(MLX(fract)->win, 6, 0L, mouse_handling, fract);
}
