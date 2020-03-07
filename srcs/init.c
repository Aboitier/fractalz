/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboitier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 22:07:38 by aboitier          #+#    #+#             */
/*   Updated: 2020/03/07 16:13:37 by aboitier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head.h"

void	get_mlx_params(t_info *info)
{
	if (!(info->mlx_ptr = mlx_init()))
	{
		perror("Error: mlx initialization. Check your environment settings\n");
		exit(0);
	}
	info->window_ptr = mlx_new_window(info->mlx_ptr, WIDTH, HEIGHT, "FRACTALZ");
	info->zoom = 100;
}

t_bound	get_boundaries(t_info *info)
{
	t_bound boundaries;

	boundaries.x1 = -6.25;
	boundaries.x2 = -3.55;
	boundaries.y1 = -3.8;
	boundaries.y2 = -1.4;
	info->env_param1 = 0.285;
	info->env_param2 = 0.01;
	return (boundaries);
}

void	reset_info(t_info *info)
{
	info->zoom = 100;
	info->boundaries.x1 = -6.25;
	info->boundaries.x2 = -3.55;
	info->boundaries.y1 = -3.8;
	info->boundaries.y2 = -1.4;
	info->translation = 1;
	info->env_param1 = 0.285;
	info->env_param2 = 0.01;
}

void	init(t_info *info)
{
	info->boundaries = get_boundaries(info);
	info->translation = 1;
	info->clicked = 0;
	info->max_iter = 50;
	init_colortab(info);
	get_mlx_params(info);
	create_image(info);
}
