/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboitier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 18:47:16 by aboitier          #+#    #+#             */
/*   Updated: 2019/10/30 17:27:14 by aboitier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head.h"

void	get_mlx_params(t_info *info)
{
	if (!(info->mlx_ptr = mlx_init()))
	{
		perror("Error: mlx initialization. Check your environment settings");
		exit (0);
	}
	info->window_ptr = mlx_new_window(info->mlx_ptr, WIDTH, HEIGHT, "FRACTALZ");
	info->zoom = 100;
}

void	init(t_info *info)
{
	t_bound boundaries = { .x1 = -2.1, .x2 =  0.6, .y1 = -1.2, .y2 = 1.2 };

	info->boundaries = boundaries;
	
	get_mlx_params(info);
	get_image_boundaries(info, info->zoom);
	create_image(info, info->image_x, info->image_y);
}

int	main(int ac, char **av)
{
	t_info	info;

	ft_putstr(av[0]);
	if (ac > 2 /* or invalid fractal name */)
	{
		return (0);
	}

	ft_bzero(&info, sizeof(info));
	init(&info);
	printf("zoom = %f\n", info.zoom);
	draw_mandelbrot(&info);
	printf("hello\n");
	head_set_hooks(&info);
	mlx_loop(info.mlx_ptr);
	return (0);
}
