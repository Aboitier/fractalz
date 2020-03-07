/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fracts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboitier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 19:09:47 by aboitier          #+#    #+#             */
/*   Updated: 2020/03/06 19:49:20 by aboitier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head.h"

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

void	input_color(t_info *info, int y, int i)
{
	int color;

	if (i == info->max_iter)
		my_pixel_put_to_image(0x000000, info, info->x, y);
	else
	{
		color = info->color[info->selected_col][i % 8];
		my_pixel_put_to_image(color, info, info->x, y);
	}
}

int		compute_complex(t_complex nb, t_info *info)
{
	while (nb.z_r * nb.z_r + nb.z_i * nb.z_i < 4 && nb.i < info->max_iter)
	{
		nb.tmp = nb.z_r;
		nb.z_r = nb.z_r * nb.z_r - nb.z_i * nb.z_i + nb.c_r;
		nb.z_i = 2 * nb.z_i * nb.tmp + nb.c_i;
		if (info->fract == BURNING_SHIP)
		{
			nb.z_r = (nb.z_r < 0) ? -nb.z_r : nb.z_r;
			nb.z_i = (nb.z_i < 0) ? -nb.z_i : nb.z_i;
		}
		nb.i++;
	}
	return (nb.i);
}

int		draw_fracts(t_info *info)
{
	int			y;
	t_complex	nb;

	while (info->x < info->limit)
	{
		y = 0;
		while (y < HEIGHT)
		{
			nb = (info->fract == MANDELBROT || info->fract == BURNING_SHIP) ?
					init_complex(info->x, y, info)
					: init_j_complex(info->x, y, info);
			nb.i = compute_complex(nb, info);
			input_color(info, y, nb.i);
			y++;
		}
		info->x++;
	}
	return (0);
}
