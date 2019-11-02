/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 21:04:23 by cpollich          #+#    #+#             */
/*   Updated: 2019/11/02 19:36:24 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include "math.h"
# include "libft.h"
# include <errno.h>
# include <stdio.h>

# define WIDTH			1000
# define HEIGHT			1000
# define MAX_ITER		100
# define MAX_X			2.0
# define MIN_X			-2.0
# define MIN_Y			-2.0
# define MAX_Y			MIN_Y + (MAX_X - MIN_X) * HEIGHT / WIDTH
# define SHIFT_X		(MAX_X - MIN_X) / (WIDTH - 1)
# define SHIFT_Y		(MAX_Y - MIN_Y) / (HEIGHT - 1)
# define S_MANDELBROT	"MANDELBROT"
# define N_MANDELBROT	"1"
# define S_JULIA		"JULIA"
# define N_JULIA		"2"
# define S_BSHP			"BURNING SHIP"
# define N_BSHP			"3"
# define MANDELBROT		1
# define JULIA			2
# define BSHP			3
# define REPEATS		30

# define MLX(x) x->mlx
# define CORD(x) x->coord
# define RGB(r, g, b)(256 * 256 * (int)(r) + 256 * (int)(g) + (int)(b))

typedef struct	s_coord
{
	int			key;
	int			color;
	double		j_x;
	double		j_y;
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
	int			key;
	int			it;
	int			mouse;
	int			color;
	double		speed;
	double		ud;
	double		lr;
	double		minx;
	double		maxx;
	double		miny;
	double		maxy;
	double		shx;
	double		shy;
	double		zoom;
}				t_fract;

/*
**	Memory initialization
*/

t_fract			*init_fract();
void			error(char *str);

/*
**	Risovalka
*/

void			put_pixel(int x, int y, t_fract *fract, int i);
void			draw(t_fract *fract);
void			mandelbrot(t_fract *fract);
void			bshp(t_fract *fract);
void			julia(t_fract *fract);

/*
**	KEYBOARD & MOUSE
*/

void			hook_init(t_fract *fdf);
void			make_zoom(t_fract *fract, int button);

/*
**	Change
*/

void			change_iteration(t_fract *fract, int key);
void			change_move_speed(t_fract *fract, int key);
void			arrow_control(t_fract *fract, int key);

#endif
