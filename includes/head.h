/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   head.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboitier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 18:51:54 by aboitier          #+#    #+#             */
/*   Updated: 2019/10/30 13:59:25 by aboitier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEAD_H
# define HEAD_H

# include "../utils/X.h"
# include "mlx.h"
# include "../libft/libft.h"
# include <stdlib.h>
# include <stdio.h>

# define WIDTH 		1200
# define HEIGHT 	900
# define MAX_ITER 	50

/*
** Mandelbrot fractal boundaries
*/

# define AREA_X1 		boundaries.x1
# define AREA_X2 		boundaries.x2
# define AREA_Y1 		boundaries.y1
# define AREA_Y2 		boundaries.y2

# define SCROLL_DOWN 	button == 4
# define SCROLL_UP 		button == 5

typedef int		t_color;

typedef struct	s_bound
{
	float		x1;
	float		x2;
	float		y1;
	float		y2;
}				t_bound;

typedef struct	s_info
{
	int			image_x;
	int			image_y;
	t_bound		boundaries;
	double		zoom;
	void		*img_ptr;
	char		*pixels;
	int			size_line;
	int			bpp;
	void		*mlx_ptr;
	void		*window_ptr;
}				t_info;

void			head_set_hooks(t_info *info);
int				exit_hook(t_info *info);
int				key_press_hook(int keycode, t_info *info);
void			get_image_boundaries(t_info *info, double zoom);
int				create_image(t_info *info, int image_x, int image_y);
void			my_pixel_put_to_image(int img_color, t_info *info, int x, int y);

int				draw_mandelbrot(t_info *info);

#endif
