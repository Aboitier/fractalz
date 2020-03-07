/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_iter.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboitier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 19:44:32 by aboitier          #+#    #+#             */
/*   Updated: 2020/03/06 19:43:49 by aboitier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head.h"

void	modify_max_iter(int keycode, t_info *info)
{
	if (keycode == PLUS)
		info->max_iter += 25;
	else
		info->max_iter -= 25;
}

void	put_nb_iter_to_image(t_info *info)
{
	char	*nb_iter;
	char	*char_to_put;

	nb_iter = ft_itoa(info->max_iter);
	char_to_put = ft_strjoin("Number of iterations ", nb_iter);
	mlx_string_put(info->mlx_ptr, info->window_ptr,
					15, 15, 0x00000, char_to_put);
	free(nb_iter);
	free(char_to_put);
}
