/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_mandelbrot.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboitier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 18:51:07 by aboitier          #+#    #+#             */
/*   Updated: 2019/10/30 17:30:01 by aboitier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head.h"

int		draw_mandelbrot(t_info *info)
{
	int x;
	int y;
	double c_r;
	double c_i;
	double z_r;
	double z_i;
	int i;
	double tmp;
	int color;

	x = 0;
	while (x < WIDTH)
	{	
			y = 0;
			while (y < HEIGHT)
			{
				c_r = x / info->zoom + info->AREA_X1;
				c_i = y / info->zoom + info->AREA_Y1;
				z_r = 0;
				z_i = 0;
				i = 0;
				
				while (z_r * z_r + z_i * z_i < 4 && i < MAX_ITER)
				{
					tmp = z_r;
					z_r = z_r*z_r - z_i * z_i + c_r;
					z_i = 2 * z_i * tmp + c_i;
					i++;
				}
				if (i == MAX_ITER)
					my_pixel_put_to_image(0x808080, info, x, y);
				else
				{
					color = (i * 255 / MAX_ITER);		
					my_pixel_put_to_image(color, info, x, y);
				}	
				y++;
			}
			x++;
	}
	printf("hello\n");
	mlx_put_image_to_window(info->mlx_ptr, info->window_ptr, info->img_ptr, 0, 0);
	return (0);
}
