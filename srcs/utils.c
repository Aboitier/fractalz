/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboitier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 16:15:56 by aboitier          #+#    #+#             */
/*   Updated: 2020/03/07 16:08:33 by aboitier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head.h"

void	my_pixel_put_to_image(int img_color, t_info *info, int x, int y)
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	int				i;

	if (x < 0 || y < 0 || x > WIDTH || y > HEIGHT)
		return ;
	r = ((img_color & 0xFF0000) >> 16);
	g = ((img_color & 0xFF00) >> 8);
	b = (img_color & 0xFF);
	i = (x * (info->bpp / 8)) + (y * info->size_line);
	info->pixels[i] = b;
	info->pixels[++i] = g;
	info->pixels[++i] = r;
}

void	change_color(t_info *info)
{
	if (info->selected_col == 3)
		info->selected_col = 0;
	else
		info->selected_col++;
}
