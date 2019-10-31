/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 16:09:55 by cpollich          #+#    #+#             */
/*   Updated: 2019/10/31 22:41:13 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include "math.h"
# include "libft.h"
# include <errno.h>
# include <stdio.h>

# define WIDTH			1000
# define HEIGHT			1000
# define MAX_X			1.0
# define MIN_X			-2.0
# define MIN_Y			-1.0
# define MAX_Y			MIN_Y + (MAX_X - MIN_X) * HEIGHT / WIDTH
# define SHIFT_X		(MAX_X - MIN_X) / (WIDTH - 1)
# define SHIFT_Y		(MAX_Y - MIN_Y) / (HEIGHT - 1)
# define S_MANDELBROT	"mandelbrot"
# define S_JULIA		"julia"
# define S_BSHP			"burning ship"
# define MANDELBROT		1
# define JULIA			2
# define BSHP			3
# define REPEATS		30
# define MLX(x) x->mlx

typedef struct	s_coord
{
	int			key;
	double		c_x;
	double		z_x;
	double		c_y;
	double		z_y;
	double		zx;
	double		zy;
}				t_coord;

typedef struct	s_mlx
{
	void		*mlx;
	void		*win;
	void		*img;
	int			*data_addr;
	int			bpp;
	int			size_line;
	int			endian;
}				t_mlx;

typedef struct	s_fract
{
	t_mlx		*mlx;
	t_coord		coord;
	int			color;
	int			key;
}				t_fract;

/*
**	Memory initialization
*/

t_fract			*init_fract();
void			error(char *str);

/*
**	Risovalka
*/

void			put_pixel(int x, int y, t_fract *fract);
void			draw(t_fract *fract);
void			mandelbrot(t_fract *fract);
void			bshp(t_fract *fract);

/*
**	KEYBOARD & MOUSE
*/

void			hook_init(t_fract *fdf);
int				key_press(int key, void *param);
int				close_fdf(void *param);

#endif
