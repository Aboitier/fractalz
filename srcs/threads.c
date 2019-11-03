/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboitier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 20:16:54 by aboitier          #+#    #+#             */
/*   Updated: 2019/11/03 20:21:13 by aboitier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head.h"

void	*funct(void *vargp){ } 

int	main()
{
	int err = 0, count = 0;
	pthread_t tid;

	while (err == 0)
	{
		err = pthread_create(&tid, NULL, funct, NULL);
		printf("%d\n", count);
		count++;
	}
	printf("Maximum number of threads in a Process is %d\n", count);
	return (0);

}
