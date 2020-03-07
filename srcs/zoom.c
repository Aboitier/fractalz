/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboitier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 18:36:04 by aboitier          #+#    #+#             */
/*   Updated: 2020/03/07 16:15:31 by aboitier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head.h"

int		zoom(int button, int x, int y, t_info *info)
{
	t_bound	*ptr;
	double	tmp_zoom;

	ptr = &(info->boundaries);
	tmp_zoom = info->zoom;
	if (button == SCROLL_DOWN)
	{
		info->zoom /= ZOOM_FACTOR;
		info->translation *= ZOOM_FACTOR;
	}
	else if (button == SCROLL_UP)
	{
		info->zoom *= ZOOM_FACTOR;
		info->translation /= ZOOM_FACTOR;
	}
	ptr->x1 += (x / tmp_zoom) - (x / info->zoom);
	ptr->y1 += (y / tmp_zoom) - (y / info->zoom);
	return (0);
}

int		translate(int keycode, t_info *info)
{
	if (keycode == ARROW_LEFT)
	{
		info->boundaries.x1 += TRANSLATION * info->translation;
		info->boundaries.x2 += TRANSLATION * info->translation;
	}
	else if (keycode == ARROW_RIGHT)
	{
		info->boundaries.x1 -= TRANSLATION * info->translation;
		info->boundaries.x2 -= TRANSLATION * info->translation;
	}
	else if (keycode == ARROW_DOWN)
	{
		info->boundaries.y1 -= TRANSLATION * info->translation;
		info->boundaries.y2 -= TRANSLATION * info->translation;
	}
	else if (keycode == ARROW_UP)
	{
		info->boundaries.y1 += TRANSLATION * info->translation;
		info->boundaries.y2 += TRANSLATION * info->translation;
	}
	return (0);
}
