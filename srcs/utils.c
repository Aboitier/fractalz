/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboitier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 16:15:56 by aboitier          #+#    #+#             */
/*   Updated: 2020/03/03 21:55:43 by aboitier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head.h"

void	my_pixel_put_to_image(int img_color, t_info *info, int x, int y)
{
	unsigned char r;
	unsigned char g;
	unsigned char b;
	int i;

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
