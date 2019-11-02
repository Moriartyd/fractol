/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 16:10:03 by cpollich          #+#    #+#             */
/*   Updated: 2019/11/02 19:36:51 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "key_map.h"
#include "colors.h"
#include "errors.h"

static char	*to_upper(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
	return (str);
}

static int	parse_input_num(char **av)
{
	if (!(ft_strcmp(av[1], N_MANDELBROT)))
		return (MANDELBROT);
	else if (!(ft_strcmp(av[1], N_JULIA)))
		return (JULIA);
	else if (!(ft_strcmp(av[1], N_BSHP)))
		return (BSHP);
	else
	{
		ft_putendl("Usage: ./fractol <fractol>\n\tYou can use this fractols:\
					\n\t1. Mandelbrot\
					\n\t2. Julia\
					\n\t3. Burning ship");
		exit(1);
	}
	return (0);
}

static int	parse_input_str(char **av)
{
	if (!(ft_strcmp(to_upper(av[1]), S_MANDELBROT)))
		return (MANDELBROT);
	else if (!(ft_strcmp(av[1], S_JULIA)))
		return (JULIA);
	else if (!(ft_strcmp(av[1], S_BSHP)))
		return (BSHP);
	else
		return (parse_input_num(av));
}

int			main(int ac, char **av)
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
		error("Usage: ./fractol <fractol>\n\tYou can use this fractols:\
					\n\t1. Mondelbrot\
					\n\t2. Julia\
					\n\t3. Burning ship");
	return (0);
}
