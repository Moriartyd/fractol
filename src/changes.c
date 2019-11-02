/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   changes.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 15:46:28 by cpollich          #+#    #+#             */
/*   Updated: 2019/11/02 19:29:24 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "key_map.h"

void	change_iteration(t_fract *fract, int key)
{
	if (key == K_PLUS || key == K_PLUS_NUM)
		fract->it += 2;
	if (key == K_MINUS || key == K_MINUS_NUM)
		fract->it -= 2;
	if (fract->it < 0)
		fract->it = 0;
}

void	change_move_speed(t_fract *fract, int key)
{
	if (key == K_BOL)
		fract->speed += 0.001;
	else
	{
		fract->speed -= 0.001;
		if (fract->speed <= 0.001)
			fract->speed = 0.001;
	}
}

void	arrow_control(t_fract *fract, int key)
{
	if (key == K_ARROW_LEFT)
		fract->lr += fract->speed;
	else if (key == K_ARROW_RIGHT)
		fract->lr -= fract->speed;
	else if (key == K_ARROW_DOWN)
		fract->ud -= fract->speed;
	else if (key == K_ARROW_UP)
		fract->ud += fract->speed;
}
