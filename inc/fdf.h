/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 16:09:55 by cpollich          #+#    #+#             */
/*   Updated: 2019/10/31 22:09:00 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include "math.h"
# include "libft.h"
# include <errno.h>
# include <stdio.h>

# define WIDTH	1000
# define HEIGHT	1000
# define S_MANDELBROT	"mandelbrot"
# define S_JULIA		"julia"
# define S_BSHP			"burning ship"
# define MANDELBROT		1
# define JULIA			2
# define BSHP			3

typedef struct	s_coord
{
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
	char		*data_addr;
	int			bpp;
	int			size_line;
	int			endian;
}				t_mlx;

/*
**	Memory initialization
*/

t_map			*init_map();
t_fract			*init_fract(t_map *map);

void			draw_line(t_coords s, t_coords f, t_fract *fdf);
void			draw(t_fract *fdf);
void			draw_pic(t_fract *fdf);

void			error(char *str);

void			for_each(t_map *len
					, void (*f)(t_coords *s, t_coords *c,
							t_coords *i, t_map *map));
void			set_coords_in_screen_by_iso(t_coords *s,
					t_coords *c, t_coords *i, t_map *map);
void			set_coords_in_screen_by_conic(t_coords *s,
					t_coords *c, t_coords *i, t_map *map);
void			zoom_in(t_fract *fdf);
void			zoom_out(t_fract *fdf);
void			iso(t_coords *s, t_coords *c, t_coords *i, t_map *map);

/*
**	KEYBOARD & MOUSE
*/

void			hook_init(t_fract *fdf);
int				key_press(int key, void *param);
int				close_fdf(void *param);

void			arrow_control(t_fract *fdf, int key);
void			z_control(t_fract *fdf, int key);

void			print_c(t_map *map, t_coords **arr);

int				get_color(t_coords current, t_coords start,
						t_coords end, t_coords delta);

#endif
