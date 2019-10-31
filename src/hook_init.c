/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 20:48:12 by cpollich          #+#    #+#             */
/*   Updated: 2019/10/31 22:10:57 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "key_map.h"
#include "fdf.h"
#include "colors.h"

int		key_press(int key, void *param)
{
	t_fract	*fdf;

	fdf = (t_fract *)param;
	ft_bzero(fdf->data_addr, WIDTH * HEIGHT * sizeof(int));
	if (key == K_ESC)
		exit(0);
	draw(fdf);
	return (0);
}

int		close_fdf(void *param)
{
	(void)param;
	exit(0);
}

void	hook_init(t_fract *fdf)
{
	mlx_hook(fdf->win, 2, 0L, key_press, fdf);
	mlx_hook(fdf->win, 17, 0L, close_fdf, fdf);
}
