/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboitier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 18:47:16 by aboitier          #+#    #+#             */
/*   Updated: 2020/03/07 16:10:46 by aboitier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head.h"

int		select_fract(char *fract, t_info *info)
{
	if (ft_strcmp(fract, "mandelbrot") == 0)
		info->fract = MANDELBROT;
	else if (ft_strcmp(fract, "julia") == 0)
		info->fract = JULIA;
	else if (ft_strcmp(fract, "burning-ship") == 0)
		info->fract = BURNING_SHIP;
	else
		return (FALSE);
	return (TRUE);
}

int		main(int ac, char **av)
{
	t_info	info;

	ft_bzero(&info, sizeof(info));
	if (ac != 2 || select_fract(av[1], &info) == FALSE)
	{
		ft_putstr("Usage: ./fractol mandelbrot | julia | burning-ship\n");
		return (0);
	}
	init(&info);
	pthread_init(&info);
	head_set_hooks(&info);
	mlx_loop(info.mlx_ptr);
	return (0);
}
