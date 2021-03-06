/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboitier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 17:21:46 by aboitier          #+#    #+#             */
/*   Updated: 2020/03/03 21:58:00 by aboitier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head.h"

int		create_image(t_info *info)
{
	int		bits_per_pixel;
	int		size_line;
	int		endian;

	if (!(info->img_ptr = mlx_new_image(info->mlx_ptr, WIDTH, HEIGHT)))
		return (-1);
	info->pixels = mlx_get_data_addr(info->img_ptr,
			&bits_per_pixel, &size_line, &endian);
	ft_bzero(info->pixels, ft_strlen(info->pixels));
	info->size_line = size_line;
	info->bpp = bits_per_pixel;
	return (0);
}
