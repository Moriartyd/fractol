/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   changes.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 15:46:28 by cpollich          #+#    #+#             */
/*   Updated: 2019/11/01 15:55:54 by cpollich         ###   ########.fr       */
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
