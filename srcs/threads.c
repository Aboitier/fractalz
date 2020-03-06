/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboitier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 20:16:54 by aboitier          #+#    #+#             */
/*   Updated: 2020/03/06 14:00:43 by aboitier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head.h"

t_complex	init_complex(int x, int y, t_info *info)
{
	t_complex nb;

	nb.c_r = x / info->zoom + info->AREA_X1;
	nb.c_i = y / info->zoom + info->AREA_Y1;
	nb.z_r = 0;
	nb.z_i = 0;
	nb.i = 0;
	return (nb);
}

t_complex	init_j_complex(int x, int y, t_info *info)
{
	t_complex nb;

	nb.c_r = info->env_param1; 
	nb.c_i = info->env_param2; 
	nb.z_r = x / info->zoom + info->AREA_X1;
	nb.z_i = y / info->zoom + info->AREA_Y1;
   	nb.i = 0;
	return (nb);
}

void	pthread_init(t_info *info)
{
	t_info		thread_info[NB_THREADS];
	pthread_t	thrtab[NB_THREADS];
	int			i;

	i = 0;
	while (i < NB_THREADS)
	{
		ft_memcpy((void*)&thread_info[i], (void*)info, sizeof(t_info));
		thread_info[i].x = (WIDTH / NB_THREADS) * i;
		thread_info[i].limit = (WIDTH / NB_THREADS) + thread_info[i].x;
		pthread_create(&thrtab[i], NULL, (void *)draw_mandelbrot, &thread_info[i]);
		i += 1;
	}
	while (i--)
		pthread_join(thrtab[i], NULL);
	mlx_put_image_to_window(info->mlx_ptr, info->window_ptr, info->img_ptr, 0, 0);
}
