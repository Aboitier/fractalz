/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboitier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 18:32:29 by aboitier          #+#    #+#             */
/*   Updated: 2020/03/03 22:05:35 by aboitier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head.h"

int		translate(int keycode, t_info *info)
{
	printf("BEFORE:\t%.30Lf\n", info->translation);
	if (keycode == ARROW_LEFT)
	{
		info->AREA_X1 += TRANSLATION * info->translation;
		info->AREA_X2 += TRANSLATION * info->translation;
	}
	else if (keycode == ARROW_RIGHT)
	{	
		info->AREA_X1 -= TRANSLATION * info->translation;
		info->AREA_X2 -= TRANSLATION * info->translation;
	}
	else if (keycode == ARROW_DOWN)
	{
		info->AREA_Y1 -= TRANSLATION * info->translation;
		info->AREA_Y2 -= TRANSLATION * info->translation;
	}
	else if (keycode == ARROW_UP)
	{
		info->AREA_Y1 += TRANSLATION * info->translation;
		info->AREA_Y2 += TRANSLATION * info->translation;
	}
	printf("AFTER:\t%.30Lf\n", info->translation);
	return (0);
}

int		key_press_hook(int keycode, t_info *info)
{
	if (keycode == 49)
	{
		info->zoom = 100;
		info->AREA_X1 = -2.1; 
		info->AREA_X2 = 0.6;
		info->AREA_Y1 = -1.2;
		info->AREA_Y2 = 1.2;
		info->translation = 1;
	}
	else if (keycode == ESC)
		exit(0);
	else if (keycode >= ARROW_LEFT && keycode <= ARROW_UP)
		translate(keycode, info);
	else if (keycode == PLUS || keycode == MINUS)
		modify_max_iter(keycode, info);
	redraw(info);
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
	pthread_init(info);
	put_nb_iter_to_image(info);
	return (0);
}

int		mouse_hook(int button, int x, int y, t_info *info)
{
	if (button == 4 || button == 5)
	{
		zoom(button, x, y, info);
		redraw(info);
	}
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
