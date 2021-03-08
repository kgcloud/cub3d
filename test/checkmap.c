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
	j = 0;
	while (i--)
	{
		while (cub->map[i][j++])
		{	
			if (cub->map[i][j] != '0' && cub->map[i][j] != '1' && cub->map[i][j] != '2' && cub->map[i][j] != ' ')
			{
				if (cub->map[i][j] == 'N' || cub->map[i][j] == 'O' || cub->map[i][j] == 'E' || cub->map[i][j] == 'S')
				{
					if (cub->check != 0)
						return (-1);
					cub->check = 1;
					cub->px = j;
					cub->py = i;
				}
				else
					return (-1);
			}
		}
		j = 0;
	}
	return (0);
}