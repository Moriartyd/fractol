/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 16:10:03 by cpollich          #+#    #+#             */
/*   Updated: 2019/10/31 22:02:51 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "key_map.h"
#include "colors.h"
#include "errors.h"

int		parse_input(char **av)
{
	if (!(ft_strcmp(av[1], S_MANDELBROT)))
		return (MANDELBROT);
	else if (!(ft_strcmp(av[1], S_JULIA)))
		return (JULIA);
	else if (!(ft_strcmp(av[1], S_BSHP)))
		return (BSHP);
	else
		error(E_USAGE);
}

int		main(int ac, char **av)
{
	int			fd;
	t_map		*map;
	t_fract		*fdf;

	errno = 0;
	if (ac == 2)
	{
		map = init_map();
		fdf = init_fract(map);
		parse_input(av);
		hook_init(fdf);
		draw(fdf);
		mlx_loop(fdf->mlx);
	}
	else
		error(E_USAGE);
	return (0);
}
