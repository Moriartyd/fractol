/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 21:17:24 by cpollich          #+#    #+#             */
/*   Updated: 2019/10/31 21:50:55 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	iso(t_coords *s, t_coords *c, t_coords *i, t_map *map)
{
	int	prev_x;
	int	prev_y;

	prev_x = s->x;
	prev_y = s->y;
	(void)c;
	(void)map;
	i->x = (prev_x - prev_y) * (cos(0.523599));
	i->y = (s->z) + (prev_x + prev_y) * (sin(0.523599));
	i->color = s->color;
}

void	for_each(t_map *len
				, void (*f)(t_coords *s, t_coords *c, t_coords *i, t_map *map))
{
	int	i;
	int	j;

	i = -1;
	while (++i < len->height)
	{
		j = -1;
		while (++j < len->width)
			(*f)(&len->s_c[i][j], &len->c_c[i][j]
				, &len->iso_c[i][j], len);
	}
}

void	draw_pic(t_fract *fdf)
{
	int			i;
	int			j;
	t_coords	**arr;

	arr = fdf->map->c_c;
	i = -1;
	while (++i < fdf->map->height)
	{
		j = -1;
		while (++j < fdf->map->width)
		{
			if (j + 1 != fdf->map->width)
				draw_line(arr[i][j], arr[i][j + 1], fdf);
			if (i + 1 != fdf->map->height)
				draw_line(arr[i][j], arr[i + 1][j], fdf);
		}
	}
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
}

void	draw(t_fract *fdf)
{
	for_each(fdf->map, iso);
	if (fdf->map->camera == CAM_ISO)
		for_each(fdf->map, set_coords_in_screen_by_iso);
	else if (fdf->map->camera == CAM_PARALLEL)
		for_each(fdf->map, set_coords_in_screen_by_conic);
	draw_pic(fdf);
}
