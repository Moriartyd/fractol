/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 23:10:00 by cpollich          #+#    #+#             */
/*   Updated: 2019/11/01 23:13:28 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "key_map.h"

void	make_zoom(t_fract *fract, int button)
{
	if (button == MOUSE_SCROLL_UP)
	{
		fract->minx *= 0.95;
		fract->maxx *= 0.95;
		fract->miny *= 0.95;
		fract->it += 1;
		fract->zoom -= 0.2;
	}
	else if (button == MOUSE_SCROLL_DOWN)
	{
		fract->minx *= 1.1;
		fract->maxx *= 1.1;
		fract->miny *= 1.1;
		fract->it -= 1;
		fract->zoom += 0.2;
	}
	fract->maxy = fract->miny + (fract->maxx - fract->minx) * WIDTH / HEIGHT;
	fract->shx = (fract->maxx - fract->minx) / (WIDTH - 1);
	fract->shy = (fract->maxy - fract->miny) / (HEIGHT - 1);
}
