/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboitier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 18:32:29 by aboitier          #+#    #+#             */
/*   Updated: 2019/11/03 21:41:16 by aboitier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head.h"

int		key_press_hook(int keycode, t_info *info)
{
	if (keycode == 49)
	{
		info->zoom = 100;
		info->AREA_X1 = -2.1; 
		info->AREA_X2 = 0.6;
		info->AREA_Y1 = -1.2;
		info->AREA_Y2 = 1.2;
		redraw(info);
	}
	if (keycode == 53)
	{
		exit(0);
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
	create_image(info);
	draw_mandelbrot(info);
	return (0);
}

int		zoom(int button, int x, int y, t_info *info)
{
	t_bound *ptr;
  	double tmp_zoom;

	ptr = &(info->boundaries);
	tmp_zoom = info->zoom;
	if (SCROLL_DOWN)
		info->zoom /= ZOOM_FACTOR;
	else if (SCROLL_UP)
		info->zoom *= ZOOM_FACTOR;
	ptr->x1 += (x / tmp_zoom) - (x / info->zoom);
	ptr->y1 += (y / tmp_zoom) - (y / info->zoom);
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
