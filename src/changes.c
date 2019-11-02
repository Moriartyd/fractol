/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   changes.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 15:46:28 by cpollich          #+#    #+#             */
/*   Updated: 2019/11/02 19:47:21 by cpollich         ###   ########.fr       */
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

void	back_pls(t_fract *f)
{
	f->zoom = 4;
	f->minx = MIN_X;
	f->maxx = MAX_X;
	f->miny = MIN_Y;
	f->maxy = MAX_Y;
	f->shx = SHIFT_X;
	f->shy = SHIFT_Y;
	f->speed = 0.002;
	f->lr = 0;
	f->ud = 0;
	f->mouse = 0;
	f->it = 30;
}