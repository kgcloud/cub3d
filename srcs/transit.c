/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: canjugun <canjugun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 14:48:09 by canjugun          #+#    #+#             */
/*   Updated: 2021/03/10 15:20:00 by canjugun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		transit(t_cub *cub)
{
	if (cub->line[0] == 'R' && cub->line[1] == ' ')
	{
		int space;

		space = 0;
		if (cub->R != 0)
			return (-1);
		cub->R = 1;
		cub->i = 0;
		while (cub->line[++cub->i] == ' ')
			;
		cub->rx = cub->i;
		while (cub->line[cub->i])
		{
			if (!(cub->line[cub->i] >= '0' && cub->line[cub->i] <= '9'))
			{
				if (cub->line[cub->i] != ' ' && space == 1)
					return (-1);
				while (cub->line[cub->i] == ' ' && space == 0)
					cub->i++;
				space = 1;
				cub->ry = cub->i - 1;
			}
			cub->i++;
		}
		cub->rx = ft_atoi(cub->line + cub->rx);
		cub->ry = ft_atoi(cub->line + cub->ry);
		if (cub->rx > 2147483647 || cub->rx <= 0 || 
			cub->ry > 2147483647 || cub->ry <= 0)
			return (-1);
	}
	else if (cub->line[0] == 'N' && cub->line[1] == 'O' && cub->line[2] == ' ')
	{
		if (cub->NO != 0)
			return (-1);
		cub->NO = 1;
		cub->i = 2;
		while (cub->line[cub->i] == ' ')
			cub->i++;
		cub->no = ft_strdup(cub->line + cub->i);
	}
	else if (cub->line[0] == 'S' && cub->line[1] == 'O' && cub->line[2] == ' ')
	{
		if (cub->SO != 0)
			return (-1);
		cub->SO = 1;
		cub->i = 2;
		while (cub->line[cub->i] == ' ')
			cub->i++;
		cub->so = ft_strdup(cub->line + cub->i);
	}
	else if (cub->line[0] == 'W' && cub->line[1] == 'E' && cub->line[2] == ' ')
	{
		if (cub->WE != 0)
			return (-1);
		cub->WE = 1;
		cub->i = 2;
		while (cub->line[cub->i] == ' ')
			cub->i++;
		cub->we = ft_strdup(cub->line + cub->i);
	}
	else if (cub->line[0] == 'E' && cub->line[1] == 'A' && cub->line[2] == ' ')
	{
		if (cub->EA != 0)
			return (-1);
		cub->EA = 1;
		cub->i = 2;
		while (cub->line[cub->i] == ' ')
			cub->i++;
		cub->ea = ft_strdup(cub->line + cub->i);
	}
	else if (cub->line[0] == 'S' && cub->line[1] == ' ')
	{
		if (cub->S != 0)
			return (-1);
		cub->S = 1;
		cub->i = 1;
		while (cub->line[cub->i] == ' ')
			cub->i++;
		cub->s = ft_strdup(cub->line + cub->i);
	}
	else if (cub->line[0] == 'F' && cub->line[1] == ' ')
	{
		if (cub->F != 0)
			return (-1);
		cub->F = 1;
		cub->i = 0;
		while (cub->line[cub->i] == ' ')
			cub->i++;
		cub->f = ft_strdup(cub->line + cub->i);
	}
	else if (cub->line[0] == 'C' && cub->line[1] == ' ')
	{
		if (cub->C != 0)
			return (-1);
		cub->C = 1;
		cub->i = 0;
		while (cub->line[cub->i] == ' ')
			cub->i++;
		cub->c = ft_strdup(cub->line + cub->i);
	}
	else if (cub->line[0] != '\n')
		return (-1);
	return (0);
}
