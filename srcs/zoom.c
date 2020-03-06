/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboitier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 18:36:04 by aboitier          #+#    #+#             */
/*   Updated: 2020/03/03 22:00:22 by aboitier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head.h"

int		zoom(int button, int x, int y, t_info *info)
{
	t_bound *ptr;
  	double tmp_zoom;

	ptr = &(info->boundaries);
	tmp_zoom = info->zoom;
	if (SCROLL_DOWN)
	{
		info->zoom /= ZOOM_FACTOR;
		info->translation *= ZOOM_FACTOR; 
	}
	else if (SCROLL_UP)
	{
		info->zoom *= ZOOM_FACTOR;
		info->translation /= ZOOM_FACTOR;
	}
	ptr->x1 += (x / tmp_zoom) - (x / info->zoom);
	ptr->y1 += (y / tmp_zoom) - (y / info->zoom);
	return (0);
}

