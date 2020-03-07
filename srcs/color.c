/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboitier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 18:38:18 by aboitier          #+#    #+#             */
/*   Updated: 2020/03/07 16:08:26 by aboitier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head.h"

/*
** Louis's theme
*/

static void		colortab4(t_info *info)
{
	info->color[3][0] = 0x7f7f7f;
	info->color[3][1] = 0x708090;
	info->color[3][2] = 0x677179;
	info->color[3][3] = 0x548b9a;
	info->color[3][4] = 0x724e64;
	info->color[3][5] = 0x92b47c;
	info->color[3][6] = 0xa660df;
	info->color[3][7] = 0xffbf70;
	info->color[3][8] = 0x9e9e9e;
}

/*
** Psychedelic theme
*/

static void		colortab3(t_info *info)
{
	info->color[2][0] = 0xfd00ff;
	info->color[2][1] = 0xfdff00;
	info->color[2][2] = 0x00ff38;
	info->color[2][3] = 0x00f9ff;
	info->color[2][4] = 0x3c00ff;
	info->color[2][5] = 0xfd00ff;
	info->color[2][6] = 0xfdff00;
	info->color[2][7] = 0x00f9ff;
	info->color[2][8] = 0x3c00ff;
}

/*
**	Cyberpunk theme
*/

static void		colortab2(t_info *info)
{
	info->color[1][0] = 0x7f7f7f;
	info->color[1][1] = 0x708090;
	info->color[1][2] = 0x677179;
	info->color[1][3] = 0x048b9a;
	info->color[1][4] = 0x723e64;
	info->color[1][5] = 0x82c46c;
	info->color[1][6] = 0x6600ff;
	info->color[1][7] = 0xff7f00;
	info->color[1][8] = 0x9e9e9e;
}

/*
**	Original theme
*/

static void		colortab1(t_info *info)
{
	info->color[0][0] = 0x8cfc03;
	info->color[0][1] = 0x03f4fc;
	info->color[0][2] = 0xfc03fc;
	info->color[0][3] = 0xfc0314;
	info->color[0][4] = 0xf8fc03;
	info->color[0][5] = 0xdf03fc;
	info->color[0][6] = 0x1803fc;
	info->color[0][7] = 0xfc8c03;
	info->color[0][8] = 0xadfc03;
}

void			init_colortab(t_info *info)
{
	colortab1(info);
	colortab2(info);
	colortab3(info);
	colortab4(info);
}
