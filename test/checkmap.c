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
	j = -1;
	while (i--)
	{
		while (cub->map[i][++j])
		{	
			if (cub->map[i][j] != '0' && cub->map[i][j] != '1' && cub->map[i][j] != '2' && cub->map[i][j] != ' ')
			{
				if (cub->map[i][j] == 'N' || cub->map[i][j] == 'O' || cub->map[i][j] == 'E' || cub->map[i][j] == 'S')
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
		j = -1;
	}
	cub->check != 0 ? j = 0 : j;
	return (j);
}

int		recursivemap(t_cub *cub, int x, int y)
{
	if (x <= 0 || y <= 0 || x > cub->x || y > cub->y)
		return (-1);
	if (cub->map[x][y] != '0')
	{
		if (cub->map[x][y] != '1' && cub->map[x][y] != '2' && cub->map[x][y] != '9')
			return (-1);
		else
			return (0);
	}
	cub->map[x][y] = '9';
	if (recursivemap(cub, x + 1, y) == - 1)
		return (-1);
	if (recursivemap(cub, x, y - 1) == - 1)
		return (-1);
	if (recursivemap(cub, x - 1, y) == - 1)
		return (-1);
	if (recursivemap(cub, x, y + 1) == - 1)
		return (-1);
	if (recursivemap(cub, x + 1, y + 1) == - 1)
		return (-1);
	if (recursivemap(cub, x - 1, y - 1) == - 1)
		return (-1);
	if (recursivemap(cub, x + 1, y - 1) == - 1)
		return (-1);
	if (recursivemap(cub, x - 1, y + 1) == - 1)
		return (-1);
	return (0);
}