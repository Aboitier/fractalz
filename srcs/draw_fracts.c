/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fracts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboitier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 19:09:47 by aboitier          #+#    #+#             */
/*   Updated: 2020/03/06 12:36:59 by aboitier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head.h"

	// ajouter les modifs pour julia && autre fractale
	// julia : autres valeurs d'init
	// BShip : nb absolus quelque part

int		draw_mandelbrot(t_info *info)
{
	int y;
	int color;
	t_complex nb;

	while (info->x < info->limit)
	{	
			y = 0;
			while (y < HEIGHT)
			{
				nb = (info->fract == MANDELBROT) ? 
						init_complex(info->x, y, info)
						: init_j_complex(info->x, y, info);	
				while (nb.z_r * nb.z_r + nb.z_i * nb.z_i < 4 && nb.i < info->max_iter)
				{
					nb.tmp = nb.z_r;
					nb.z_r = nb.z_r * nb.z_r - nb.z_i * nb.z_i + nb.c_r;
					nb.z_i = 2 * nb.z_i * nb.tmp + nb.c_i;
					nb.i++;
				}
				if (nb.i == info->max_iter)
					my_pixel_put_to_image(0x000000, info, info->x, y);
				else
				{
					color = info->color[nb.i % 8];
					my_pixel_put_to_image(color, info, info->x, y);
				}	
				y++;
			}
			info->x++;
	}
	return (0);
}
