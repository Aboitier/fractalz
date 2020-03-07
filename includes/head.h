/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   head.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboitier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 18:51:54 by aboitier          #+#    #+#             */
/*   Updated: 2020/03/07 16:15:43 by aboitier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEAD_H
# define HEAD_H

# include "../utils/X.h"
# include "mlx.h"
# include "../libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include <math.h>
# include <pthread.h>

# define WIDTH 			2400
# define HEIGHT 		1600
# define MAX_ITER 		300
# define ZOOM_FACTOR	1.5
# define TRANSLATION	0.5
# define NB_THREADS		24

# define TRUE			1
# define FALSE			0

# define MANDELBROT		1
# define JULIA			2
# define BURNING_SHIP	3

/*
** Key codes
*/

# define SCROLL_DOWN 	4
# define SCROLL_UP 		5
# define ONE			18
# define TWO			19
# define THREE			20
# define ESC			53
# define ENTER			36
# define PLUS			69
# define MINUS			78
# define ARROW_LEFT		123
# define ARROW_RIGHT	124
# define ARROW_DOWN		125
# define ARROW_UP		126

typedef int				t_color;

typedef struct			s_bound
{
	long double			x1;
	long double			x2;
	long double			y1;
	long double			y2;
}						t_bound;

typedef struct			s_complex
{
	double				c_r;
	double				c_i;
	double				z_r;
	double				z_i;
	double				tmp;
	int					i;
}						t_complex;

typedef struct			s_info
{
	int					image_x;
	int					image_y;
	t_bound				boundaries;
	int					x;
	int					tmp_x;
	int					limit;
	int					max_iter;
	int					fract;
	double				env_param1;
	double				env_param2;
	int					clicked;
	long double			zoom;
	long double			translation;
	void				*img_ptr;
	char				*pixels;
	int					size_line;
	int					bpp;
	int					selected_col;
	int					color[4][15];
	void				*mlx_ptr;
	void				*window_ptr;
}						t_info;

void					head_set_hooks(t_info *info);
int						exit_hook(t_info *info);
int						key_press_hook(int keycode, t_info *info);
void					get_image_boundaries(t_info *info, double zoom);
int						create_image(t_info *info);
void					my_pixel_put_to_image(int img_color,
						t_info *info, int x, int y);

void					reset_info(t_info *info);
int						draw_fracts(t_info *info);
int						redraw(t_info *info);
int						exit_hook(t_info *info);

/*
** Initialization
*/

void					get_mlx_params(t_info *info);
void					init_colortab(t_info *info);
void					change_color(t_info *info);
void					init(t_info *info);

/*
** Zoom & Translation
*/
int						zoom(int button, int x, int y, t_info *info);
int						translate(int keycode, t_info *info);

/*
** Iteration Management
*/
void					modify_max_iter(int keycode, t_info *info);
void					put_nb_iter_to_image(t_info *info);

/*
** Threads & concurrency
*/
void					pthread_init(t_info *info);
t_complex				init_complex(int x, int y, t_info *info);
t_complex				init_j_complex(int x, int y, t_info *info);

#endif
