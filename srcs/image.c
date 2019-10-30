/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboitier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 17:21:46 by aboitier          #+#    #+#             */
/*   Updated: 2019/10/30 13:58:10 by aboitier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head.h"

void	get_image_boundaries(t_info *info, double zoom)
{
	info->image_x = (info->AREA_X2 - info->AREA_X1) * zoom;
	printf("image_x = %d\n", info->image_x);
	info->image_x = 270;
	printf("AREA_X1 = %f\t AREA_X2 = %f\nAREA_Y1 = %f\tAREA_Y2 = %f\n", info->AREA_X1, info->AREA_X2, info->AREA_Y1, info->AREA_Y2);
	info->image_y = (info->AREA_Y2 - info->AREA_Y1) * zoom;
	printf("image_y = %d\n", info->image_y);
	info->image_y = 240;
}

int		create_image(t_info *info, int image_x, int image_y)
{
	int		bits_per_pixel;
	int		size_line;
	int		endian;

	printf("%d, %d\n",image_x, image_y);
	if (!(info->img_ptr = mlx_new_image(info->mlx_ptr, WIDTH, HEIGHT)))
		return (-1);
	info->pixels = mlx_get_data_addr(info->img_ptr,
			&bits_per_pixel, &size_line, &endian);
	ft_bzero(info->pixels, ft_strlen(info->pixels));
	info->size_line = size_line;
	info->bpp = bits_per_pixel;
	//printf("size_line = %d\n", size_line);
	return (0);
}
