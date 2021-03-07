/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: canjugun <canjugun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 12:48:37 by cloud             #+#    #+#             */
/*   Updated: 2021/03/07 17:07:01 by canjugun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	initcub(t_cub *cub)
{
	cub->x = 0;
	cub->y = 0;
	cub->ret = 1;
	cub->fd = 0;
	cub->R = 0;
	cub->NO = 0;
	cub->SO = 0;
	cub->WE = 0;
	cub->EA = 0;
	cub->S = 0;
	cub->F = 0;
	cub->C = 0;
	cub->i = 0;
	cub->map = NULL;
	cub->line = NULL;
	cub->no = NULL;
	cub->so = NULL;
	cub->we = NULL;
	cub->ea = NULL;
	cub->s = NULL;
	cub->rx = 0;
	cub->ry = 0;
}