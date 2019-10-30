/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboitier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 18:32:29 by aboitier          #+#    #+#             */
/*   Updated: 2019/10/30 14:21:53 by aboitier         ###   ########.fr       */
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

	ptr = &(info->boundaries);
	interpolation = 0.0;
	double zoom_factor = 1.2;

	double mouseRe;
	mouseRe	= (double)x / (WIDTH / (info->AREA_X2 - info->AREA_X1)) + info->AREA_X1;
	double mouseIm;
   	mouseIm	= (double)y / (HEIGHT / (info->AREA_Y2 - info->AREA_Y1)) + info->AREA_Y1;


	if (SCROLL_DOWN)
	{
		interpolation = 1.0 / (1.0 / zoom_factor);
		info->zoom /= 1.2;
	}
	else if (SCROLL_UP)
	{
		interpolation = 1.0 / zoom_factor;
		info->zoom *= 1.2;
	}
		ptr->x1 = interpolate(mouseRe, ptr->x1, interpolation);
		ptr->x2 = interpolate(mouseRe, ptr->x2, interpolation);
		ptr->y1 = interpolate(mouseIm, ptr->y1, interpolation);
		ptr->y2 = interpolate(mouseIm, ptr->y2, interpolation);

	return (0);
}

int		mouse_hook(int button, int x, int y, t_info *info)
{
	if (button == 4 || button == 5)
		zoom(button, x, y, info);
	redraw(info);
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
