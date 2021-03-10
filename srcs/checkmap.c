/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap[i].c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cloud <cloud@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 16:53:04 by canjugun          #+#    #+#             */
/*   Updated: 2021/03/08 17:11:34 by cloud            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		checkmap(t_cub *cub)
{
	int i;
	int	j;

	i = cub->y;
	while (i--)
	{
		j = -1;
		while (cub->map[i][++j])
		{	
			if (!ft_strchr("012 ", cub->map[i][j]))
			{				
				if (ft_strchr("NOES", cub->map[i][j]))
				{
					if (cub->check != 0)
						return (-1);
					cub->check = cub->map[i][j];
					cub->map[i][j] = '0';
					cub->px = j;
					cub->py = i;
				}
				else
					return (-1);
			}
		}
	}
	return ((!cub->check) * j);
}

int check_wall(t_cub *cub)
{
	int x;
	int y;

	y = -1;
	if (recursivemap(cub, cub->px, cub->py, 0) == -1)
		return (-1);
	while (++y < cub->y)
	{
		x = -1;
		while (++x < cub->x)
			if (cub->map[y][x] == '0' &&
				recursivemap(cub, x, y, 1) == -1)
				return (-1);
	}
	return (0);
}

int		recursivemap(t_cub *cub, int x, int y, int space)
{

	if (x < 0 || y < 0 || x >= cub->x || y >= cub->y ||
	 ((x == 0 || y == 0 || x == cub->x - 1 || y == cub->y - 1) && cub->map[y][x] != '1'))
		return (-1);
	if (cub->map[y][x] != '0' &&
		(cub->map[y][x] != ' ' || !space))
			return (-!ft_strchr("129", cub->map[y][x]));
	cub->map[y][x] = '9';
	if (recursivemap(cub, x + 1, y, space) == -1 ||
		recursivemap(cub, x, y - 1, space) == -1 ||
		recursivemap(cub, x - 1, y, space) == -1 ||
		recursivemap(cub, x, y + 1, space) == -1 ||
		recursivemap(cub, x + 1, y + 1, space) == -1 ||
		recursivemap(cub, x - 1, y - 1, space) == -1 ||
		recursivemap(cub, x + 1, y - 1, space) == -1 ||
		recursivemap(cub, x - 1, y + 1, space) == -1)
		return (-1);
	return (0);
}