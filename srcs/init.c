/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboitier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 22:07:38 by aboitier          #+#    #+#             */
/*   Updated: 2020/03/06 14:31:31 by aboitier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head.h"

void	get_mlx_params(t_info *info)
{
	if (!(info->mlx_ptr = mlx_init()))
	{
		perror(MLX_ERROR);
		exit (0);
	}
	info->window_ptr = mlx_new_window(info->mlx_ptr, WIDTH, HEIGHT, "FRACTALZ");
	info->zoom = 100;
}

void	init_colortab(t_info *info)
{
	info->color[0] = 0x8cfc03; //vert yuzu
	info->color[1] = 0x03f4fc; //bleu curacao
	info->color[2] = 0xfc03fc; //rose pink
	info->color[3] = 0xfc0314; //rouge
	info->color[4] = 0xf8fc03; //jaune marsupilami
	info->color[5] = 0xdf03fc; //violet clair
	info->color[6] = 0x1803fc; //bleu klein
	info->color[7] = 0xfc8c03; //orange gouda
	info->color[8] = 0xadfc03; //jaune verdatre
}

t_bound	get_boundaries(t_info *info)
{
	t_bound boundaries;

	if (info->fract == MANDELBROT)
	{
		boundaries.x1 = -2.75;
		boundaries.x2 = -0.05;
	}
	else// if (info->fract == JULIA)
	{
		boundaries.x1 = -2.25;
		boundaries.x2 = -0.25;
	}
	boundaries.y1 = -1.8;
	boundaries.y2 = 0.6;
	info->env_param1 = 0.285;
	info->env_param2 = 0.01;
	return (boundaries);
}

void	init(t_info *info)
{
	info->boundaries = get_boundaries(info);
	info->translation = 1;
	info->max_iter = 50;
	init_colortab(info);
	get_mlx_params(info);
	create_image(info);
}
