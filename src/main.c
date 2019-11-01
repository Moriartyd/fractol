/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 16:10:03 by cpollich          #+#    #+#             */
/*   Updated: 2019/11/01 16:08:41 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "key_map.h"
#include "colors.h"
#include "errors.h"

int		parse_input_num(char **av)
{
	if (!(ft_strcmp(av[1], N_MANDELBROT)))
		return (MANDELBROT);
	else if (!(ft_strcmp(av[1], N_JULIA)))
		return (JULIA);
	else if (!(ft_strcmp(av[1], N_BSHP)))
		return (BSHP);
	else
		error(E_USAGE);
	return (0);
}

int		parse_input_str(char **av)
{
	if (!(ft_strcmp(av[1], S_MANDELBROT)))
		return (MANDELBROT);
	else if (!(ft_strcmp(av[1], S_JULIA)))
		return (JULIA);
	else if (!(ft_strcmp(av[1], S_BSHP)))
		return (BSHP);
	else
		return (parse_input_num(av));
}

int		main(int ac, char **av)
{
	t_fract	*fract;

	errno = 0;
	if (ac == 2)
	{
		fract = init_fract();
		fract->key = parse_input_str(av);
		hook_init(fract);
		draw(fract);
		mlx_loop(fract->mlx->mlx);
	}
	else
		error(E_USAGE);
	return (0);
}
