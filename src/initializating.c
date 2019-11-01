/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializating.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 17:07:25 by cpollich          #+#    #+#             */
/*   Updated: 2019/11/01 22:52:28 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "errors.h"
#include "colors.h"

t_mlx	*init_mlx(void)
{
	t_mlx	*res;

	if (!(res = (t_mlx *)malloc(sizeof(t_mlx))))
		error(E_INIT);
	res->mlx = mlx_init();
	if (!(res->win = mlx_new_window(res->mlx, WIDTH, HEIGHT, "Fractol")))
		error(E_INIT);
	if (!(res->img = mlx_new_image(res->mlx, WIDTH, HEIGHT)))
		error(E_INIT);
	res->data_addr = (int *)mlx_get_data_addr(res->img, &res->bpp,
				&res->size_line, &res->endian);
	return (res);
}

t_fract	*init_fract(void)
{
	t_fract	*res;

	if (!(res = (t_fract *)ft_memalloc(sizeof(t_fract))))
		error(E_MALLOC);
	res->mlx = init_mlx();
	res->color = C_WHITE;
	res->zoom = 4;
	res->minx = MIN_X;
	res->maxx = MAX_X;
	res->miny = MIN_Y;
	res->maxy = MAX_Y;
	res->shx = SHIFT_X;
	res->shy = SHIFT_Y;
	res->it = 10;
	return (res);
}
