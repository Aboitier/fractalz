/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboitier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 18:32:29 by aboitier          #+#    #+#             */
/*   Updated: 2020/03/07 16:12:59 by aboitier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head.h"

void	switch_fract(int keycode, t_info *info)
{
	if (keycode == ONE)
		info->fract = MANDELBROT;
	else if (keycode == TWO)
		info->fract = JULIA;
	else if (keycode == THREE)
		info->fract = BURNING_SHIP;
}

int		key_press_hook(int keycode, t_info *info)
{
	if (keycode == 49)
		reset_info(info);
	else if (keycode == ESC)
		exit(0);
	else if (keycode == ENTER)
		change_color(info);
	else if (keycode >= ONE && keycode <= THREE)
		switch_fract(keycode, info);
	else if (keycode >= ARROW_LEFT && keycode <= ARROW_UP)
		translate(keycode, info);
	else if (keycode == PLUS || keycode == MINUS)
		modify_max_iter(keycode, info);
	redraw(info);
	return (0);
}

int		mouse_hook(int button, int x, int y, t_info *info)
{
	if (button == 4 || button == 5)
		zoom(button, x, y, info);
	else if (button == 1)
		info->clicked = (info->clicked == 1) ? 0 : 1;
	redraw(info);
	return (0);
}

int		mouse_motion(int x, int y, t_info *info)
{
	long double	res;

	(void)y;
	if (info->fract == JULIA && info->clicked == 0)
	{
		res = info->boundaries.x1 - info->boundaries.x2;
		res = (res > 0) ? res : -res;
		res = res / info->zoom;
		if (info->tmp_x > x)
		{
			info->env_param1 -= res;
			info->env_param2 -= res;
		}
		else
		{
			info->env_param1 += res;
			info->env_param2 += res;
		}
		info->tmp_x = x;
	}
	redraw(info);
	return (0);
}

void	head_set_hooks(t_info *info)
{
	mlx_hook(info->window_ptr, 17, 0, exit_hook, info);
	mlx_key_hook(info->window_ptr, key_press_hook, info);
	mlx_mouse_hook(info->window_ptr, mouse_hook, info);
	mlx_hook(info->window_ptr, 6, 1L << 6, mouse_motion, info);
}
