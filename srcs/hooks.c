/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboitier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 18:32:29 by aboitier          #+#    #+#             */
/*   Updated: 2019/10/30 21:46:02 by aboitier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head.h"

int		key_press_hook(int keycode, t_info *info)
{
	if (keycode == 53)
	{	
		exit(0);
		info->mlx_ptr = NULL;
	}
	return (0);
}

int		exit_hook(t_info *info)
{
	mlx_destroy_window(info->mlx_ptr, info->window_ptr);
	exit(0);
}

int		redraw(t_info *info)
{
	mlx_destroy_image(info->mlx_ptr, info->img_ptr);
	get_image_boundaries(info, info->zoom);
	create_image(info, info->image_x, info->image_y);
	draw_mandelbrot(info);
	return (0);
}

double	interpolate(double start, double end, double interpolation)
{
	return (start + ((end - start) * interpolation));
}

int		zoom(int button, int x, int y, t_info *info)
{
	t_bound *ptr;
	double interpolation;
	double mouseRe;
	double mouseIm;

	ptr = &(info->boundaries);
	interpolation = 0.0;

	mouseRe	= (double)x / (WIDTH / (info->AREA_X2 - info->AREA_X1)) + info->AREA_X1;
	printf("mouseRe = %f\n", mouseRe);
 	mouseIm	= (double)y / (HEIGHT / (info->AREA_Y2 - info->AREA_Y1)) + info->AREA_Y1;
  printf("mouse Im = %f\n", mouseIm);

//	double offset;
//	offset = (info->xoffset + info->yoffset) / (WIDTH + HEIGHT);

  	double tmp_zoom = info->zoom;
	if (SCROLL_DOWN)
	{
		interpolation = 1.0 / (1.0 / ZOOM_FACTOR);
		info->zoom /= ZOOM_FACTOR;
	}
	else if (SCROLL_UP)
	{
		interpolation = 1.0 / ZOOM_FACTOR;
		info->zoom *= ZOOM_FACTOR;
	}
		ptr->x1 += /*interpolate(mouseRe, ptr->x1, interpolation) + */(x / tmp_zoom) - (x / info->zoom);
		ptr->x2 += /*interpolate(mouseRe, ptr->x1, interpolation) + */(x / tmp_zoom) - (x / info->zoom);
		//ptr->x2 = interpolate(mouseRe, ptr->x2, interpolation); 
		ptr->y1 += /*interpolate(mouseIm, ptr->y1, interpolation) + */(y / tmp_zoom) - (y / info->zoom);
		ptr->y2 += /*interpolate(mouseIm, ptr->y1, interpolation) + */(y / tmp_zoom) - (y / info->zoom);
		//ptr->y2 = interpolate(mouseIm, ptr->y2, interpolation);

	info->xoffset = x;
	info->yoffset = y;
	return (0);
}

int		mouse_hook(int button, int x, int y, t_info *info)
{
	if (button == 4 || button == 5)
	{
			zoom(button, x, y, info);
			redraw(info);
	}
	x = y;
	printf("info->zoom = %f\n", info->zoom); 
	return (0);
}

void	head_set_hooks(t_info *info)
{
	//mlx_expose_hook(info->mlx_ptr, expose_hook, info);
	mlx_hook(info->window_ptr, 17, 0, exit_hook, info);
	mlx_key_hook(info->window_ptr, key_press_hook, info);
	mlx_mouse_hook(info->window_ptr, mouse_hook, info);
	//mlx_loop_hook(info->mlx_ptr, my_loop_hook, info);
}
